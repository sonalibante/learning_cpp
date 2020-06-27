//put your header here
#include<assert.h>
#include<string>
using namespace std;

class Queue
{
    private:
        //
        struct Node
        {
            string data;
            Node *next;
            Node *prev;
        };
        Node *head;
        Node *tail;

    public:
        Queue();
        void enqueue(string);
        string dequeue();
        bool isEmpty();
        int size();
        // return the number of elements in the queue
};

Queue:: Queue()
{
    head = NULL;
    tail = NULL;
}

void Queue:: enqueue(string x)
{
    Node *newnode = new Node();
    newnode->value = x;
    newnode->next = NULL;

    if (!tail)
    {
        newnode->prev = NULL;
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}
string Queue:: dequeue()
{
    assert (!isempty());

    T result = head->value;
    Node *temp = head;
    head = head->next;
    if (head)
        head->prev = NULL;
    delete temp;

    if (head==NULL)
        tail = NULL;

    return result;
}

bool Queue:: isEmpty()
{
    return (head==NULL);
}
int Queue:: size()
{
    int count=0;
    for (Node *p=head; p; p=p->next)
        count++;
    return count;
}
