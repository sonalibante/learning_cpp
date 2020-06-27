// Lab 9
// Fall 2018
// js236

#include <iostream>
#include <string>
using namespace std;

#ifndef HTLIST_H
#define HTLIST_H

template <class T>
class HTList
{
private:
    // Structure for nodes
    struct Node {
        T value;     // Value in the node
        Node *prev;    // Pointer to the previous node
        Node *next;    // Pointer to the next node
    };
    Node *head;       // Pointer to the first element
    Node *tail;        // Pointer to the last element
    
public:
     HTList();
    ~HTList();
    
    bool isempty();              // true if the list has no elems, else false
    void insert_head(T value);   // adds value to front of list
    T remove_head();             // removes value from front and returns it
    void insert_tail(T value);   // adds value to rear of list
    T remove_tail();             // removes value from rear and returns it
    
    // These functions should display the values all on one line,
    // each element separated by a space.
    void displayForward();    // displays elems to screen, front to rear
    void displayBackward();   // displays elems to screen, rear to front.
    
};

template <class T>
HTList<T>::HTList() {
    head = NULL;
    tail = NULL;
}

template <class T>
HTList<T>::~HTList() {
    while (!isempty())
        remove_head();
}

template <class T>
bool HTList<T>::isempty() {
    return (head==NULL);
}

template <class T>
void HTList<T>::insert_head(T value) {
    Node *newnode = new Node;
    newnode->value = value;
    newnode->prev = NULL;
    
    if (!head) {
        newnode->next = NULL;
        head = newnode;
        tail = newnode;
    } else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}
template <class T>
T HTList<T>::remove_head() {
    assert (!isempty());
    
    T result = head->value;
    Node *temp = head;
    head = head->next;
    if (head)
        head->prev = NULL;
    delete temp;
    
    //this is not necessarily required
    if (head==NULL)
        tail = NULL;
    
    return result;
}

template <class T>
void HTList<T>::insert_tail(T value) {
    Node *newnode = new Node();
    newnode->value = value;
    newnode->next = NULL;
    
    if (!tail) {
        newnode->prev = NULL;
        head = newnode;
        tail = newnode;
    } else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}
template <class T>
T HTList<T>::remove_tail() {
    assert (!isempty());
    
    T result = tail->value;
    Node *temp = tail;
    tail = tail->prev;
    if (tail)
        tail->next = NULL;
    delete temp;
    
    //this is required so isempty will work
    if (tail==NULL)
        head = NULL;
    
    return result;
}

template <class T>
void HTList<T>::displayForward() {
    for (Node *p=head; p; p=p->next)
        cout << p->value << " ";
    cout << endl;
}

template <class T>
void HTList<T>::displayBackward() {
    for (Node *p=tail; p; p=p->prev)
        cout << p->value << " ";
    cout << endl;
}

#endif /* HTLIST_H */
