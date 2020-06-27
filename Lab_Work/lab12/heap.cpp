// Heap
// Week 12
// js236

#include <iostream>
#include <iomanip>
#include <cassert>
using namespace std;

class Heap {
    
private:
    int array[1000];  // nodes are stored in an array (start at 1)
    int size;         // number of nodes in the array
    
    //private functions
    void percolateUp(int);
    
    void PostOrderTraversal(int x);
    bool inRange(int);


public:
    Heap();
    void insertItem(int);
    
    // displays the tree like this (positions in array are shown):
    // 1
    // 2 3
    // 4 5 6 7
    // 8 9 10 11 12 13 14 15
    // etc.
    void display();
    
    void PostOrderTraversal();
    bool inRange();
    void printDescendents(int target);
    void printAncestors(int t);
    double AvgDropLowest();
};


Heap::Heap() {
    size = 0;
}

void Heap::insertItem(int x) {

    // place x at end of tree, use percolate up to move to proper place
    size++;
    array[size] = x;
    percolateUp(size);
}

void Heap::percolateUp(int loc) {

    if (loc==1)  //base case, at root
        return;
    if (array[loc] > array[loc/2])   //base case, array[loc] > parent
        return;
    
    // recursive case: swap array[loc] with parent, repeat on the parent
    swap(array[loc],array[loc/2]);
    percolateUp(loc/2);

}

void Heap::display () {
    for (int i=1; i<=size; i++) {
        if ((i & (i - 1)) == 0)  // i is a power of 2
            cout << endl;
        cout << array[i] << " " ;
    }
    cout << endl;
}

void Heap::PostOrderTraversal() {
    PostOrderTraversal(1);
    cout << endl;
}
 
void Heap::PostOrderTraversal(int x) {
    if (x <= size) {
        PostOrderTraversal(x*2);
        PostOrderTraversal(x*2+1);
        cout << array[x] << " ";
    }
}

bool Heap::inRange() {
    return inRange(1);
}

bool Heap::inRange(int loc) {
    if (loc > size)     // null tree
        return true;
    else {
        if (array[loc] >= 0 && array[loc] <=100)
            return inRange(loc*2) && inRange(loc*2+1);
        else
            return false;
    }
}


void Heap::printDescendents(int target) 
{
    int index = -1;
    int i = 1;
    while(index == -1 && i<=size){
        if(array[i]==target)
        {
            index = i;
        }
        i++;
    }
    if (index!=-1) {
        PostOrderTraversal(index*2);
        PostOrderTraversal(index*2+1);
    }
    cout << endl;
}

void Heap::printAncestors(int target)
{ 
    int index = -1;
    int i = 1;
    while(index == -1 && i<=size){
        if(array[i]==target)
        {
            index = i;
        }
        i++;
    }
    if (index != -1) {
        int parent = index/2;
        while(parent>=1)
        {
            cout<<array[parent]<<" ";
            parent = parent/2;
        }
    }
    cout << endl;
}


double Heap::AvgDropLowest()
{
    int sum = 0;
    for (int i=1; i<=size; i++) {
       sum = sum + array[i];
    }
    
    double avg = (double) (sum-array[1])/(size-1);
    
    return avg;
}


// Driver  **************************************************************


int main () {
    
    int array[] = {10,5,12,14,7,2};
    Heap t1;
    for (int i=0; i<6; i++)
        t1.insertItem(array[i]);
    
    cout << "Heap display: " << endl;
    t1.display();
    
    cout << "PostOrder Traversal" << endl;
    t1.PostOrderTraversal();
    
    cout << "in range t1: " << boolalpha << t1.inRange() << endl;
    t1.insertItem(105);
    cout << "in range t1+105: " << boolalpha << t1.inRange() << endl;
    
    cout<<"Descendents of 5 \n";
    t1.printDescendents(5);
    cout<<"Descendents of 2 \n";
    t1.printDescendents(2);
    cout<<"Descendents of 100 \n";
    t1.printDescendents(100);
    
    cout<<"Ancestors of 10 \n";
    t1.printAncestors(10);
    cout<<"Ancestors of 105 \n";
    t1.printAncestors(105);
    cout<<"Ancestors of 100 \n";
    t1.printAncestors(100);

    cout << "Ave: " <<  t1.AvgDropLowest() << endl;

}
