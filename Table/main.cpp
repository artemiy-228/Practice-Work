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
      cout << "������� 1, ����� �������� �������" << '\n' << "������� 2, ����� ������� �������" << '\n' << "������� 3, ����� ������������� �������" << '\n' << "������� 4, ����� ������������� �������"<< '\n' << "������� 0, ����� ��������� ������" << '\n'<<"�������� ��������: ";
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
         cout << "������� ����� �������, �� �������� �������� ����������(1 - ��������, 2 - ����, 3 - �������): " << '\n';
         cin >> sort_type;
         sort_table(sort_type);
         break;
      default:
         cout << "�������������� ��������";
         getchar();
         break;
      }
      clrscr();
   }
   return sizeof(Proc);
}


void table_header() {
   cout << setw(2) <<"�"  << '|' ;
   cout << setw(24) << "��������" << '|' ;
   cout << setw(5) << "����" << '|' ;
   cout << setw(7) <<"�������" << '|' << '\n';
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
      cout << "�������� ������������ ������. ���������� � ��������������, ��� ��������� ��������������� ���������� �������: ";
      getchar();
   }
   else {
      cout << "������� �������� ����������: ";
      cin.getline(proc[cur_size].name, 24); //�� ��������� ������ � ��������. ������� ����� getline,  �� ������� ����������� �����//
      cout << "������� ���������� ����: ";
      while (!(cin >> proc[cur_size].cores)) { //cin >> ���������� 1 � ������ ��������� ����� � 0 � ������ ����������. ��������������, ���� ������������ ������ �� �����, � �����, �� ���� �� �������������//
         cin.clear();//��� �������� �����, ��� �� �� ����������� ������ ��������� cin.clear(); ���������� ����� ������ ��� ������� cin//
         cin.ignore(256, '\n');//������� cin.ignore() ��������� �������� ������� ����� ������ cin, �� ���� ������� ��� ������� �� ������ �� ���������� �����������.//
         cout << "������! ������� ����� �����: ";
      }
      cout << "������� ������� ����������: ";
      while (!(cin >> proc[cur_size].frequency)) {
         cin.clear();
         cin.ignore(256, '\n');// 1 �������� - ����� ������, 2 �������� �����������, ���� ������ ������, ��� �������� �����//
         cout << "������! ������� �����: ";
      }
      cur_size++;
   }
}


void delete_proc() {
   int n;
   cout << "������� ����� ���������� ��������: ";
   while (!(cin >> n)) {
      cin.clear();
      cin.ignore(256, '\n');// 1 �������� - ����� ������, 2 �������� �����������, ���� ������ ������, ��� �������� �����//
      cout << "������! ������� �����: ";
   }
   if (cur_size > 0 && n <= cur_size) {
      int k = n - 1;
      for (k; k < cur_size ; k++) {
         proc[k] = proc[k + 1];
      }
   }
   else {
      clrscr();
      cout << "�� ���������� ������ ��������: ";
      getchar();
      return;
   }
   cur_size--;
}

void edit_table() {
   int n;
   cout << "������� ����� �������������� ��������: ";
   while (!(cin >> n)) {
      cin.clear();
      cin.ignore(256, '\n');// 1 �������� - ����� ������, 2 �������� �����������, ���� ������ ������, ��� �������� �����//
      cout << "������! ������� �����: ";
   }
   if (cur_size == 0 || n < 1 || n > cur_size) {
      clrscr();
      cout << "�� ���������� ������ ��������: ";
      getchar();
   }
   else {
      cout << "�������������� �������� �" << n << '\n';
      cout << "������� ����� �������� ����������: ";
      getchar();
      cin.getline(proc[n - 1].name, 24);
      cout << "������� ����� ���������� ����: ";
      cin >> proc[n - 1].cores;
      getchar();
      cout << "������� ����� ������� ����������: ";
      cin >> proc[n - 1].frequency;
   }
}

void sort_table(int sort_type) {
   for (int i = 0; i < cur_size - 1; i++) { //����������� ����������� �����, �� ������ �� ����//
      for (int j = 0; j < cur_size - 1 - i; j++) { //� ����������� �� ���������� ���� ����������, �� ������ ��������. ����� ���� ������� �������� � ������, �� ��� �� �������� �� ���������� ����//
         if (sort_type == 1 && proc[j + 1].name > proc[j].name) { //���������� �� ��������//
            swap(proc[j + 1], proc[j]);
         }
         else if (sort_type == 2 && proc[j + 1].cores > proc[j].cores) { //���������� �� �����//
            swap(proc[j + 1], proc[j]);
         }
         else if (sort_type == 3 && proc[j + 1].frequency > proc[j].frequency) { //���������� �� �������� ������� ����������//
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

