//
// An example of implementing map data structure.
// It's not complete, but it's a start showing how
// the basic abstractions work.
// 
// Prof. Joe Hummel
// Northwestern University
// CS 211
// 

#include <iostream>
#include <map>
#include <string>
#include <utility>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::pair;

//
// class map:
//
template<typename KeyT, typename ValueT>
class map {
private:
  //
  // we start by implementing a map as a linked-list of nodes:
  //
  struct NODE {
    pair<KeyT, ValueT> KeyValuePair;
    NODE* Next;

    NODE(KeyT key)
      : KeyValuePair(make_pair(key, ValueT() /*defalt value*/)), 
        Next(nullptr)
    { }
  };

  //
  // data members:
  //
  NODE* Root;  // pointer to first node in linked-list
  int   Size;  // size of the linked-list

public:
  // 
  // constructor:
  //
  map()
  : Root(nullptr),Size(0)
  { }

  //
  // size:
  //
  int size() {
    return this->Size;
  }

  //
  // []:
  //
  ValueT& operator[](KeyT key)
  {
    //
    // first we search to see if the given key is
    // already in the list, and if so, we return
    // the VALUE as a reference (C++ handles the 
    // reference part, we just return the value):
    //

    // TODO: do this SECOND
    NODE* cur = Root;
    while (cur != nullptr)
    {
      if (cur->KeyValuePair.first == key)
      {
        return cur->KeyValuePair.second;
      }
      cur = cur->Next; //move onto next node
    }


    //
    // not found, we have to insert at the 
    // front of the list and return the VALUE
    // as a reference (C++ handles the reference
    // part, we just return the value):
    //
    NODE* newnode = new NODE(key);

    // TODO: do this FIRST
    newnode->Next=nullptr;
    newnode->Next = this->Root;
    this->Root=newnode;
    this->Size++;

    return newnode->KeyValuePair.second;
  }
};

//
// main:
//
int main() {
  map<string, int> animals;

  animals["elephant"] = 1;
  animals["cat"] = 3;
  animals["owl"] = 1;
  animals["dog"] = 2;
  animals["bear"] = 1;
  animals["moth"] = 9;
  animals["pig"] = 4;
  animals["ferret"] = 6;
  animals["zebra"] = 1;

  while (true) {

    string type;

    cout << "Enter a type of animal> ";
    cin >> type;

    if (type == "$") {
      break;
    }
    else if (type == "#") {
      cout << "# of animals: " << animals.size() << endl;
    }
    else {
      cout << "I own " << animals[type] << " " << type << endl;
    }

  }//while

  return 0;
}
