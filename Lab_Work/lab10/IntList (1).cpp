// Exercise 2
// Lab 10
// Fall 2018
// js236

#include <iostream>
#include <assert.h>
using namespace std;

class IntList
{
private:
    struct ListNode
    {
        int value;
        ListNode* next;
    };
    ListNode * head;
    
    int getSize(ListNode *P);
    int sumR(ListNode *P);
    
public:
    IntList();
    ~IntList();
    
    void insertAtFront(int val);

    double Avg();
};

IntList::IntList() {
    head = NULL;
}

IntList::~IntList() {
    ListNode *p;
    ListNode *n;
    p = head;
    while (p!=NULL) {
        n = p->next;  //save address of next node
        delete p;
        p = n;        //make p point to the next node
    }
}

void IntList::insertAtFront(int val) {
    
    
    ListNode *newNode; // ptr to new node
    ListNode *p;       // ptr to traverse list
    
    //allocate new node
    newNode = new ListNode;
    newNode->value = val;
    newNode->next = head;
    head = newNode;
}


int IntList::getSize(ListNode *P)
{
    if (P==NULL)
      return 0;
      
    else
        return (1+getSize(P->next));
    
}

int IntList::sumR (ListNode *P)
{
    if (P == NULL)
        return 0;
    
    else
        return (P->value + sumR(P->next));
}

double IntList::Avg()
{
    double avg =(double) sumR(head) / getSize(head);
    
    return avg;
       
}

int main() {
    IntList list;
    list.insertAtFront(33);
    list.insertAtFront(22);
    list.insertAtFront(11);
    
    cout << list.Avg() << endl;

    list.insertAtFront(44);
    cout << list.Avg() << endl;

    list.insertAtFront(99);
    cout << list.Avg() << endl;
}

//expected output:
//  22
//  27.5
//  41.8
