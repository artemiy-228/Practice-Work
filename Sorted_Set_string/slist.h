#ifndef SLIST_H
#define SLIST_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class SList{
   private:
      string* data; // array for string
      int max_size; // max size for this array
      int current_size; // current size for this array
   
  public:
    SList(int maxsize); // constructor
    ~SList() {delete[] data;} // destructor
    void add(const string& str);   // add string
    int size(){return current_size;}  // count of string
    int find(const string& str); // find string, return -1, if not exists
    void remove(int); // delete string
    const string& item(int); // string by index
    void print(); // write status of object
};

#endif