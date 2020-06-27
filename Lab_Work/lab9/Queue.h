// Lab 9
// Fall 2018
// js236

#include "HTList.h"

template <class T>
class Queue {
private:
    HTList<T> que;
public:
     Queue();
    ~Queue();
    
    // Queue operations
    void enqueue(T);
    T dequeue();
    bool isempty();
    void display();   //front to rear
};

template <class T>
Queue<T>::Queue() { }  //automatically constructs que

template <class T>
Queue<T>::~Queue() { } //automatically destructs que

template <class T>
void Queue<T>::enqueue(T val) {
    que.insert_tail(val);
}

template <class T>
T Queue<T>::dequeue() {
    return que.remove_head();  //return is required!
}

template <class T>
bool Queue<T>::isempty() {
    return que.isempty();    //return is required!
}

template <class T>
void Queue<T>::display() {
    que.displayForward();
}
