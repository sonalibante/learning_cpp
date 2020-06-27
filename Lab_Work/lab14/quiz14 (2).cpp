// Quiz 14: Review
// Fall 2018

#include <iostream>
using namespace std;

#include <iostream>

//#4 linked list
class NumList {
private:
    struct Node {
        int data;
        Node *next;
    };
    Node *head;
public:
    NumList() { head = NULL; }
    void deleteAfter (int);
    void display();
    void addToFront(int);
};
void NumList::display() {
    Node *p = head;
    while (p) {
        cout << p->data << " ";
        p=p->next;
    }
    cout << endl;
}

void NumList::addToFront(int s) {
    Node *newNode = new Node;
    newNode->data = s;
    newNode->next = head;
    head = newNode;
}

//solution:
void NumList::deleteAfter(int y) {
    
    Node *p = head;
    while (p && p->data!=y) {
        p = p->next;
    }
    if (p && p->next) {  //if y is  found AND it's not the last element
        Node *temp = p->next;
        p->next = temp->next;
        delete temp;
    }
}

int main()
{
    NumList n;
    n.addToFront(20);
    n.addToFront(16);
    n.addToFront(14);
    n.addToFront(12);
    n.addToFront(10);
    n.display();

    n.deleteAfter(14);
    n.display();
    n.deleteAfter(15);  //no change
    n.display();
    n.deleteAfter(20);  //no change
    n.display();
}
