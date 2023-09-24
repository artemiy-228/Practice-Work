#include <slist.h>

// creating constructor
SList::SList(int maxsize){
   max_size = maxsize;
   current_size = 0;
   data = new string[max_size];
}

// add method
void SList::add(const string& str){
   if (current_size < max_size)
   {
      data[current_size] = str;
      current_size++;
      sort(data, data + current_size);
   }
   else{
      cout << "List is full. You can't add new element." << '\n';
      exit(1);
   }
}


// find element and return its index
int SList::find(const string& str){
   for (int i = 0; i < current_size; i++)
   {
      if (data[i] == str)
      {
         return i;
   }
   }
   return -1;
}

// remove element by index
void SList::remove(int index){
   if (index >= 0 && index < current_size){
      for (int i = index; i < current_size - 1; i++){
         data[i] = data[i + 1];
      }
      current_size--;
   }
   else{
      cout << "element with this index doesn't exist" << '\n';
      exit(1);
   }
}

// return string by index if it exists
const string& SList::item(int index){
   if (index >= 0 && index < current_size){
      return data[index];
   }
   else{
      cout << "Index out of bounds. Returning an empty string." << '\n';
      exit(1);
   }
}


// show info about current status of object
void SList::print() {
    cout << "List Elements: [";
    for (int i = 0; i < current_size; i++) {
        cout << "'" << data[i] << "'";
        if (i < current_size - 1) {
            cout << ", ";
        }
    }

    cout << "]" << '\n';
}
