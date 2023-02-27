




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
      cout << "������� 1, ����� �������� �������" << '\n' << "������� 2, ����� ������� �������" << '\n' << "������� 3, ����� ������������� �������" << '\n' << "������� 0, ����� ��������� ������" << '\n'<<"�������� ��������: ";
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
    if (cur_size >= MAX_SIZE){
        clrscr();
        cout << "�������� ������������ ������. ���������� � ��������������, ��� ��������� ��������������� ���������� �������: ";
        getchar();
    } 
    else{
        cout << "������� �������� ����������: ";
        cin.getline(proc[cur_size].name, 24); //�� ��������� ������ � ��������. ������� ����� getline,  �� ������� ����������� �����//
        cout << "������� ���������� ����: ";
        while (!(cin >> proc[cur_size].cores)){//cin >> ���������� 1 � ������ ��������� ����� � 0 � ������ ����������. ��������������, ���� ������������ ������ �� �����, � �����, �� ���� �� �������������//
            cin.clear();//��� �������� �����, ��� �� �� ����������� ������ ��������� cin.clear(); ���������� ����� ������ ��� ������� cin//
            cin.ignore(256, '\n');//������� cin.ignore() ��������� �������� ������� ����� ������ cin, �� ���� ������� ��� ������� �� ������ �� ���������� �����������.//
            cout << "������! ������� ����� �����: ";
        }
        cout << "������� ������� ����������: ";
        while (!(cin >> proc[cur_size].frequency)) {
            _abracadabra_cast(cin);