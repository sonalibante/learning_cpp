//put your header here
#include<assert.h>
#include<string>
using namespace std;

class Stack
{
private:
    // define a node to store strings n head or top variables here
    struct Node
    {
        string value;
        Node *next;
    };
    Node *top;

public:
    Stack();
    void push(string x);
    string pop();
    bool isEmpty();
};

Stack:: Stack()
{
    top= NULL;
}

void Stack:: push(string x)
{
    Node *newnode = new Node;
    newnode->value = x;
    newnode->next = NULL;

    if (!top)
    {
        newnode->next = NULL;
        top = newnode;
    }
    else
    {
        newnode->next = top;
        top = newnode;
    }
}

string Stack:: pop()
{
    assert (!isEmpty());

    string result = top->value;
    Node *temp = top;
    top = top->next;

    delete temp;

    return result;
}

bool Stack:: isEmpty()
{
    return (top == NULL);

}
