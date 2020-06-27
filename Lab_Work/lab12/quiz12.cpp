// Quiz 12: Trees
// Fall 2018

#include <iostream>
#include <cassert>
using namespace std;

// Given:
class BST  {
private:
    struct TreeNode {
        int value;
        TreeNode *left;
        TreeNode *right;
    };
    TreeNode * root;
    bool findItem(TreeNode *, int);
    
    
public:
    BST() { root = NULL; }
    bool findItem(int x);
};
// 1:

bool BST::findItem(int x) {
    return findItem(root, x);
}

bool BST::findItem(TreeNode *p, int x) {
    
    if (p==NULL)
        return false;
    if (p->value==x)
        return true;
    if (x < p->value)
        return findItem(p->left,x);
    else
        return findItem(p->right,x);
}

// Given:
class Heap {
private:
    int array[100];
    int size;
    
public:
    Heap() { size=0; }
    Heap(int [], int );
    void display ();

    //outputs comma separated list of the node values found on the path from
    //the last node to the root
    void lastToRoot();
};

//solution:
void Heap::lastToRoot() {
    int loc = size;
    while (loc >= 1) {
        cout << array[loc] << ", ";
        loc = loc/2;
    }
    cout << endl;
}

// for testing:
Heap::Heap(int a[], int sizeA) {
    size = sizeA;
    for (int i=0; i<sizeA; i++)
        array[i+1] = a[i];
}
void Heap::display () {
    for (int i=1; i<=size; i++) {
        if ((i & (i - 1)) == 0)  // i is a power of 2
            cout << endl;
        cout << array[i] << " " ;
    }
    cout << endl;
}

int main() {
    int array[] = {13,21,16,24,31,19,68,65,26,32};
    Heap hp(array,10);
    hp.display();
    hp.lastToRoot();
}
