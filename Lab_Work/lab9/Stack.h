// Lab 9
// Fall 2018
// js236

#include "HTList.h"

template <class T>

class Stack
{
private:
    HTList<T> stk;
public:
    Stack();
   ~Stack();

    // Stack operations:
    void push(T);
    T pop();
    bool isempty();
    void display();   //top to bottom

};


template <class T>
Stack<T>::Stack() {  }  //automatically constructs stk

template <class T>
Stack<T>::~Stack() {  }  //automatically destructs stk

template <class T>
void Stack<T>:: push(T val) {
    stk.insert_head(val);
}

template <class T>
T Stack<T>::pop() {
    return stk.remove_head();  //return is required!
}

template <class T>
bool Stack<T>::isempty() {
    return stk.isempty();     //return is required!
}

template <class T>
void Stack<T>::display() {
    stk.displayForward();
}
