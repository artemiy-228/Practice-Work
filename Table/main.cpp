#include <iostream>
#include <iomanip>
#include <coniow.h>
#include <fstream>
#include <cstring>
#define MAX_SIZE 100


struct Proc {
   char name[24];
   int cores;
   double frequency;
};

int cur_size = 0;
Proc proc[MAX_SIZE];
Proc proc_copy = proc[MAX_SIZE];

void show_table();
void table_header();
void add_proc();
void delete_proc();
void edit_table();
void sort_table(int sort_type);
void swap(Proc &a, Proc &b);


using namespace std;

int main() {
   char n;
   int sort_type;
   cout << left << fixed;
   while (true) {
      clrscr();
      table_header();
      show_table();
      cout << "Введите 1, чтобы добавить элемент" << '\n' << "Введите 2, чтобы удалить элемент" << '\n' << "Введите 3, чтобы редактировать элемент" << '\n' << "Введите 4, чтобы отсортировать таблицу"<< '\n' << "Введите 0, чтобы завершить работу" << '\n'<<"Выберите действие: ";
      cin >> n;
      getchar();
      clrscr();
      switch (n) {
      case '1':
         add_proc();
         break;
      case '2':
         delete_proc();
         getchar();
         break;
      case '3':
         edit_table();
         getchar();
         break;
      case '0':
         return 0;
      case '4':
         cout << "Введите номер столбца, по которому проводим сортировку(1 - название, 2 - ядра, 3 - частота): " << '\n';
         cin >> sort_type;
         sort_table(sort_type);
         break;
      default:
         cout << "Несуществующая операция";
         getchar();
         break;
      }
      clrscr();
   }
   return sizeof(Proc);
}


void table_header() {
   cout << setw(2) <<"№"  << '|' ;
   cout << setw(24) << "Название" << '|' ;
   cout << setw(5) << "Ядра" << '|' ;
   cout << setw(7) <<"Частота" << '|' << '\n';
   cout << "------------------------------------------" << '\n';
}

void show_table() {
   cout.precision(2);
   cout << fixed;
   for (int i = 0 ; i < cur_size; i++) {
      cout << setw(2) << i + 1 << '|' ;
      cout << setw(24) << proc[i].name << '|' ;
      cout << setw(5) << proc[i].cores << '|' ;
      cout << setw(3) << proc[i].frequency << "Ghz" << '|' <<'\n';
      cout << "------------------------------------------" << '\n';
   }
}

void add_proc() {
   if (cur_size >= MAX_SIZE) {
      clrscr();
      cout << "Превышен максимальный размер. Обратитесь к администратору, для изменения фундаментальных параметров таблицы: ";
      getchar();
   }
   else {
      cout << "Введите название процессора: ";
      cin.getline(proc[cur_size].name, 24); //Мы принимаем строку в название. Сделано через getline,  по причине пробельного ввода//
      cout << "Введите количество ядер: ";
      while (!(cin >> proc[cur_size].cores)) { //cin >> возвращает 1 в случае успешного ввода и 0 в случае неудачного. Соответственно, если пользователь вводит не число, а букву, то цикл не заканчивается//
         cin.clear();//При введении буквы, что бы не происходило ошибок добавляем cin.clear(); сбрасывает флаги ошибок для объекта cin//
         cin.ignore(256, '\n');//Функция cin.ignore() позволяет очистить входной буфер потока cin, то есть удалить все символы из буфера до указанного разделителя.//
         cout << "Ошибка! Введите целое число: ";
      }
      cout << "Введите частоту процессора: ";
      while (!(cin >> proc[cur_size].frequency)) {
         cin.clear();
         cin.ignore(256, '\n');// 1 параметр - длина строки, 2 параметр разделитель, если строка меньше, чем указаная длина//
         cout << "Ошибка! Введите число: ";
      }
      cur_size++;
   }
}


void delete_proc() {
   int n;
   cout << "Введите номер удаляемого элемента: ";
   while (!(cin >> n)) {
      cin.clear();
      cin.ignore(256, '\n');// 1 параметр - длина строки, 2 параметр разделитель, если строка меньше, чем указаная длина//
      cout << "Ошибка! Введите число: ";
   }
   if (cur_size > 0 && n <= cur_size) {
      int k = n - 1;
      for (k; k < cur_size ; k++) {
         proc[k] = proc[k + 1];
      }
   }
   else {
      clrscr();
      cout << "Не существует такого элемента: ";
      getchar();
      return;
   }
   cur_size--;
}

void edit_table() {
   int n;
   cout << "Введите номер редактируемого элемента: ";
   while (!(cin >> n)) {
      cin.clear();
      cin.ignore(256, '\n');// 1 параметр - длина строки, 2 параметр разделитель, если строка меньше, чем указаная длина//
      cout << "Ошибка! Введите число: ";
   }
   if (cur_size == 0 || n < 1 || n > cur_size) {
      clrscr();
      cout << "Не существует такого элемента: ";
      getchar();
   }
   else {
      cout << "Редактирование элемента №" << n << '\n';
      cout << "Введите новое название процессора: ";
      getchar();
      cin.getline(proc[n - 1].name, 24);
      cout << "Введите новое количество ядер: ";
      cin >> proc[n - 1].cores;
      getchar();
      cout << "Введите новую частоту процессора: ";
      cin >> proc[n - 1].frequency;
   }
}

void sort_table(int sort_type) {
   for (int i = 0; i < cur_size - 1; i++) { //Использовал пузырьковый метод, тк другие не знаю//
      for (int j = 0; j < cur_size - 1 - i; j++) { //В Зависимости от выбранного типа сотрировки, мы делаем проверку. Можно было вынести отдельно в начало, но это бы повлияло на читаемость кода//
         if (sort_type == 1 && proc[j + 1].name > proc[j].name) { //Сортировка по названию//
            swap(proc[j + 1], proc[j]);
         }
         else if (sort_type == 2 && proc[j + 1].cores > proc[j].cores) { //Сортировка по ядрам//
            swap(proc[j + 1], proc[j]);
         }
         else if (sort_type == 3 && proc[j + 1].frequency > proc[j].frequency) { //Сортировка по тактовой частоте процессора//
            swap(proc[j + 1], proc[j]);
         }
      }
   }
}

void swap(Proc &a, Proc &b) {
   Proc temp = a;
   a = b;
   b = temp;
}

