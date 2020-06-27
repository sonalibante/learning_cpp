// Lab 8
// Fall 2018
// js236


#include <iostream>
#include <assert.h>
using namespace std;

#include "IntList.h"

IntList::IntList() {
    head = NULL;
    size=0;
}

IntList::~IntList() {
    while (size > 0) {
//     cout << "erase " << getAt(0) << endl;
       eraseAt(0);
    }
    //the code from numberList.h is also acceptable 
}

void IntList::display() {
    ListNode *p = head;
    // use a count-controlled loop with size or use while(p)
    for(int i = 0 ; i< size; i++){
        cout << p->value << " ";
        p=p->next;
    }
    cout << endl;
}

int IntList::sum() {
    int sum =0;
    for (ListNode *p = head; p; p = p->next)
        sum+=p->value;
    return sum;
}

void IntList::insertAt(int position,int val) {
    
    assert(position<=size && position >= 0);
    
    ListNode *newNode; // ptr to new node
    ListNode *p;       // ptr to traverse list
    
    //allocate new node
    newNode = new ListNode;
    newNode->value = val;
    
    p = head;
    if (position == 0)
    {
        head = newNode;
        newNode->next = p;
    }
    else
    {
        ListNode *n;
        for (int pos = 0; pos<position; pos++) {
            n = p;
            p = p->next; // advance
        }
        
        newNode->next=p;
        n->next = newNode;
    }
    size++;    
}

void IntList::replaceAt(int position, int val) {
    
    assert(position<size && position >= 0);
    
    ListNode *p = head;
    for (int i=0; i<position; i++) {
        p = p->next;
    }
    
    p->value = val;
}


int IntList::getAt(int position) {
    
    assert(position<size && position >= 0);

    ListNode *p; // ptr to traverse list
    p = head;
    
    // if size is correct and position<size, then p will never become null
    for (int pos = 0; pos<position; pos++)
        p = p->next; // advance
    return p->value;
}

void IntList::eraseAt(int position) {
    
    assert(position<size && position >= 0);

    ListNode *p; // ptr to traverse list
    p = head;
    
    if (position == 0)   //remove the first node
    {
        head=p->next;
        delete p;
    }
    else
    {
        ListNode *n;
        for (int pos = 0; pos<position; pos++) {
            n = p;
            p = p->next; // advance
        }
        n->next = p->next;
        delete p;
    }
    size--;
}

