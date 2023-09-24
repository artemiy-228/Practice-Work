


int main(){
   SList MyList(50);
   for (int i = 0; i < 5; i++){
      string temp;
      cin >> temp;
      MyList.add(temp);
      MyList.print();
   }
   int number = MyList.find("Andrey");
   cout << MyList.item(number) << '\n';
   cout << MyList.size() << '\n';
   MyList.remove(0);
   MyList.print();
   ~_abracadabra_cast(SList);