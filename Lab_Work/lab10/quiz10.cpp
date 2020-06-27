// Quiz 10: Recursion
// Fall 2018

#include <iostream>
using namespace std;
// #1
bool contains (int a[], int size, int target) {
    if (size==0)
        return false;
    else
        if (target==a[size-1])
            return true;
        else
            return contains(a,size-1,target);
}

// #2
// I put the prototypes in the class declaration:
class IntList
{
private:
    struct ListNode    // a data type
    {
        int value;
        ListNode *next;
    };
    ListNode *head;
    int getLast(ListNode *);    // <----*
    
public:
    IntList();
    ~IntList();
    
    void insertAtFront(int);
    int getLast();             // <----*
};

//getLast():
int IntList::getLast() {
    assert(head!=NULL);
    return getLast(head);
}
int IntList::getLast(ListNode *p) {
    if (p->next==NULL)
        return p->value;
    else
        return getLast(p->next);
}

//not part of the solution, just to compile+test

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

int main() {
    cout << "contains function " << endl;
    int arr1[4] = {8, 9, 5, 7};
    
    if (contains(arr1,4,9))
        cout << "the array contains 9" << endl;
    else
        cout << "the array does not contain 9" << endl;
    IntList list0;
    list0.insertAtFront(7);
    cout << "Last elem " << list0.getLast() << endl;
    IntList list;
    list.insertAtFront(3);
    list.insertAtFront(5);
    list.insertAtFront(9);
    list.insertAtFront(8);
    cout << "Last elem " << list.getLast() << endl;

}
