// Quiz 8
// Fall 2018

#include <iostream>
using namespace std;

class NumberList  {
private:
    struct ListNode  {
        double value;
        struct ListNode *next;
    };
    ListNode *head;
public:
    NumberList() {head = NULL; }
    ~NumberList();
    double sumOfSquares();
    void firstToLast();
    //for testing:
    void push_front(double);
    void displayList();
};

//beginning of solution:

double NumberList::sumOfSquares() {
    double total = 0;
    ListNode *p = head;
    while (p!=NULL) {
        total += p->value * p->value;
        p = p->next;
    }
    return total;
}

void NumberList::firstToLast() {
    if (head==NULL || head->next==NULL)
        return;
    
    ListNode *firstNode = head;
    
    head = head->next;  //removes (skips over) first node
    
    firstNode->next = NULL;  //makes it point to null

    ListNode *p=head;       //find last node, make it point to first one
    while (p->next!=NULL) {
        p = p->next;
    }
    p->next = firstNode;
}

//end of solution

void NumberList::push_front(double d) {
    ListNode *newNode = new ListNode;
    newNode->value = d;
    newNode->next = head;
    head = newNode;
}
void NumberList::displayList() {
    ListNode *p = head;
    while (p!=NULL) {
        cout << p->value  << "  ";
        p = p->next;
    }
    cout << endl;
}
NumberList::~NumberList() {
    ListNode *p;
    ListNode *n;
    p = head;
    while (p!=NULL) {
        n = p->next;  //save address of next node
        delete p;
        p = n;        //make p point to the next node
    }
}

int main() {
    
    // set up the list
    NumberList list;
    
    //push some values to the list
    list.push_front(3.3);
    list.push_front(2.2);
    list.push_front(1.1);
    
    // Display the values in the list
    list.displayList();
    
    // Demo sumOfSquares:
    cout << "sumOfSquares: " << list.sumOfSquares() << endl;
    
    // Demo firstToLast:
    cout << endl << "firstToLast:" << endl;
    list.firstToLast();
    list.displayList();

    // Demo firstToLast:
    cout << endl << "firstToLast:" << endl;
    list.firstToLast();
    list.displayList();

    // Demo firstToLast:
    cout << endl << "firstToLast:" << endl;
    list.firstToLast();
    list.displayList();

}
