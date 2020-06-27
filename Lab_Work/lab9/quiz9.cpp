// Quiz 9
// Fall 2018

#include <iostream>
#include <cassert>
using namespace std;

//From the quiz instructions:
class Queue {
private:
    double arr[10];
    int front, rear, numItems;
public:
    Queue() {front = numItems = 0; rear = -1;}
    void enqueue(double);
    double dequeue();
    bool isEmpty() {return numItems==0;}
    bool isFull()  {return numItems==10;}
    double sum();
};

// Solution is: the following functions:
void Queue::enqueue(double val) {
    assert (!isFull());
    
    rear = (rear+1) % 10;
    arr[rear] = val;
    numItems++;
}
double Queue::dequeue() {
    assert(!isEmpty());
    
    double v = arr[front];
    front = (front+1) % 10; //wrap the index around
    numItems--;
    return v;
}

double Queue::sum() {
    double total = 0;
    int i=front;
    for (int count = 0; count<numItems; count++) {
        total = total + arr[i];
        i=(i+1)%10;  //wrap around
    }
    return total;
}

//double Queue::sum() {
//    cout << "front: " << front << " rear: " << rear << endl;
//    double total = 0;
//    //won't work after wraparound, because rear < front
//    for (int i=front; i<=rear; i=(i+1)%10)
//        total = total + arr[i];
//    return total;
//}

//testing:
int main () {
    Queue x;
    x.enqueue(10.5);
    x.enqueue(13.8);
    x.enqueue(20.2);
    x.enqueue(1.5);
    x.enqueue(2.0);
    x.dequeue();
    x.dequeue();
    x.enqueue(2.0);
    x.enqueue(1.5);
    x.enqueue(2.0);
    x.enqueue(1.5);
    x.dequeue();
    x.dequeue();
    x.enqueue(2.0);
    x.enqueue(1.5);
    x.enqueue(2.0);
    cout << x.sum() << endl;
}
