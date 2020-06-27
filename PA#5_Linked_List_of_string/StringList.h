// File Name: StringList.h
//
// Author: Jill Seaman
// Date: 4/3/2019
// Assignment Number: 5
// CS2308.255 and CS5301 Spring 2019
// Instructor: Jill Seaman
//
// Represents a list of strings.
// Supports adding and removing strings, displaying and sorting strings,
// removing the maximum and count of the number of strings in the list.

#include <string>
using namespace std;

class StringList
{
  private:
    struct StringNode          // the Nodes of the linked list
    {
        string data;           // data is a string
        StringNode *next;      // points to next node in list
    };

    StringNode *head;           // the head pointer
    void remove(StringNode *);
    StringNode * maximum();  //Note: use the following function header:
                             //StringList::StringNode * StringList:: maximum()

  public:
    StringList();
    ~StringList();

    int count();
    void push_front(string);
    void push_back(string);
    void pop_front();
    void display();
    void sort();

    //for testing, called from the Driver:
    void removeNode (int i) {
        StringNode *p = head;
        while (i>0 && p) {p=p->next; i--;}
        if (p) remove(p);
    }
    void badRemove() {  //to test calling remove on a node not in the list
        StringNode *p = new StringNode;
        remove(p);  //should do nothing: not crash, not remove anything
        delete p;
    }
    string maxElem() {
        StringNode *p = maximum();
        return p->data;
    }
};
