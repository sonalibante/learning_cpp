// Exercise 3
// Lab 11
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
    int size;            //the number of nodes in the list
    
public:
    IntList();
    ~IntList();
    
    void display();
    void insertAt(int position,int val);
    int getAt(int position);
    void eraseAt(int position);
    int maximum();
    void sort();
};


IntList::IntList() {
    head = NULL;
    size=0;
}

IntList::~IntList() {
    while (size > 0) {
       eraseAt(0);
    }
}

void IntList::display() {
    ListNode *p = head;
    // use a count-controlled loop with size or while(p)
    
    for(int i = 0 ; i< size; i++){
        cout << p->value << " ";
        p=p->next;
    }
    cout << endl;

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

int IntList:: maximum()
{
    if (head==NULL)
        return -1;
    
    ListNode *p;    // pointer used to traverse the list
    p = head;
    int maximum = p->value;  //first value
    int maxPosition = 0;     //first position

    p = p->next;
    int count = 1;           //to track the current position
    while (p!=NULL) {
        if (p->value > maximum){
            maximum = p->value;  //save new maximum
            maxPosition = count; //save its position
        }
        p = p->next;         //makes p point to the next node
        count++;
    }
    return maxPosition;
}



void IntList::sort()
{
    ListNode *newHead=NULL;   // the head of the new list
    int oldsize = size;
    
    // repeat until the original list is empty
    while (size > 0) {  //or head != NULL
        
        // find the current maximum
        int maxPos = maximum();
        int max = getAt(maxPos);  //save the value
        
        // remove it from the list
        eraseAt(maxPos);
       
        // make a new node
        ListNode *newNode = new ListNode();
        newNode->value = max;     //put the max value in it
        newNode->next = NULL;
        
        // add it to the front of the new list
        newNode -> next = newHead;
        newHead = newNode;
        
    }
 
    // make head point to the new list, reset the size
    head = newHead;
    size = oldsize;
   
}



int main() {
    IntList list;
    list.insertAt(0, 0);
    list.insertAt(1, 20);
    list.insertAt(2, 22);
    list.insertAt(3, 33);
    list.insertAt(4, 1);
    list.display();
    
    list.sort();
    list.display();
    
 
}

