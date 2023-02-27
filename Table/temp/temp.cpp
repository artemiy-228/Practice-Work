




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
   cout << left << fixed;
   while (true) {
      clrscr();
      table_header();
      show_table();
      cout << "Введите 1, чтобы добавить элемент" << '\n' << "Введите 2, чтобы удалить элемент" << '\n' << "Введите 3, чтобы редактировать элемент" << '\n' << "Введите 0, чтобы завершить работу" << '\n'<<"Выберите действие: ";
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
         sort_table(2);
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
    if (cur_size >= MAX_SIZE){
        clrscr();
        cout << "Превышен максимальный размер. Обратитесь к администратору, для изменения фундаментальных параметров таблицы: ";
        getchar();
    } 
    else{
        cout << "Введите название процессора: ";
        cin.getline(proc[cur_size].name, 24); //Мы принимаем строку в название. Сделано через getline,  по причине пробельного ввода//
        cout << "Введите количество ядер: ";
        while (!(cin >> proc[cur_size].cores)){//cin >> возвращает 1 в случае успешного ввода и 0 в случае неудачного. Соответственно, если пользователь вводит не число, а букву, то цикл не заканчивается//
            cin.clear();//При введении буквы, что бы не происходило ошибок добавляем cin.clear(); сбрасывает флаги ошибок для объекта cin//
            cin.ignore(256, '\n');//Функция cin.ignore() позволяет очистить входной буфер потока cin, то есть удалить все символы из буфера до указанного разделителя.//
            cout << "Ошибка! Введите целое число: ";
        }
        cout << "Введите частоту процессора: ";
        while (!(cin >> proc[cur_size].frequency)) {
            _abracadabra_cast(cin);