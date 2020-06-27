// IntBinaryTree class, modified from Gaddis textbook
// Week 12
// js236

#include <iostream>
#include <iomanip>
#include <cassert>
using namespace std;

class IntBinaryTree
{
private:
    struct TreeNode
    {
        int value;         // The value in the node
        TreeNode *left;    // Pointer to left child node
        TreeNode *right;   // Pointer to right child node
    };
    
    TreeNode *root;       // Pointer to the root node
    
    // Private member functions
    void insert(TreeNode *&, int);
    void destroySubTree(TreeNode *);
    void displayPostOrder(TreeNode *) const;
    
    // added for solution
    void printAncestors(TreeNode *, int target);
    void printDescendents(TreeNode *, int target) ;
    int sum(TreeNode *);
    int count(TreeNode *);
    int findMin(TreeNode *);
    bool inRange( TreeNode *);
    
public:
    
    IntBinaryTree()       { root = NULL; }
    ~IntBinaryTree()      { destroySubTree(root); }
    
    // Binary tree operations
    void insertNode(int);
    
    // traversals
    void displayPostOrder() const     {  displayPostOrder(root); cout << endl; }
    
    // added for solution
    bool inRange( );
    void printAncestors(int target);
    void printDescendents(int target);
    double AvgDropLowest();
};



//*************************************************************
// insert accepts a TreeNode pointer and a pointer to a node. *
// The function inserts the node into the tree pointed to by  *
// the TreeNode pointer. This function is called recursively. *
//*************************************************************

void IntBinaryTree::insert(TreeNode *&nodePtr, int num)
{
    if (nodePtr == NULL) {
        // Create a new node and store num in it, making nodePtr point to it
        nodePtr = new TreeNode;
        nodePtr->value = num;
        nodePtr->left = nodePtr->right = NULL;
    }
    else if (num < nodePtr->value)
        insert(nodePtr->left, num);     // Search the left branch
    else if (num > nodePtr->value)
        insert(nodePtr->right, num);    // Search the right branch
    // else nodePt->value == num, do nothing, no duplicates
}

//**********************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function.                   *
//**********************************************************

void IntBinaryTree::insertNode(int num)
{
    //call the recursive function
    insert(root, num);
}

//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes all nodes in the tree.                   *
//***************************************************

void IntBinaryTree::destroySubTree(TreeNode *nodePtr)
{
    if (nodePtr)
    {
        if (nodePtr->left)
            destroySubTree(nodePtr->left);
        if (nodePtr->right)
            destroySubTree(nodePtr->right);
        delete nodePtr;
    }
}

//****************************************************************
// The displayPostOrder member function displays the values      *
// in the subtree pointed to by nodePtr, via postorder traversal.*
//****************************************************************

void IntBinaryTree::displayPostOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << " ";
    }
}

void IntBinaryTree::printAncestors(TreeNode *p, int target)
{ 
    if (p != NULL) {
        if (target < p->value) {
            cout << p->value << " ";
            printAncestors(p->left,target);
        }
        if (target > p->value) {
            cout << p->value << " ";
            printAncestors(p->right,target);
        }
    }
}

void IntBinaryTree::printAncestors(int target) 
{
    printAncestors(root,target);
    cout << endl;
}

void IntBinaryTree::printDescendents(TreeNode *p, int target)
{ 
    if (p != NULL) {
        if (p->value == target)
        {
            displayPostOrder(p->left);
            displayPostOrder(p->right);
        }
        else if (target < p->value)
            printDescendents(p->left, target) ;
        else
            printDescendents(p->right, target) ;
    }
}

void IntBinaryTree::printDescendents(int target) 
{
    printDescendents(root,target);
    cout << endl;
}

int IntBinaryTree::findMin(TreeNode *root)
{
    assert (root);  // min of empty tree is undefined
    
    TreeNode *temp = root;
    while (temp->left) {
        temp = temp->left;
    }
    return temp->value;
}

int IntBinaryTree::sum(TreeNode *root){
    if(root == NULL)
        return 0;
    return root->value + sum(root->right) + sum(root->left);
}
int IntBinaryTree::count(TreeNode *root){
    if(root == NULL)
        return 0;
    return 1 + count(root->right) + count(root->left);
}
double IntBinaryTree::AvgDropLowest(){
    int min = findMin(root);
    return (double)(sum(root)-min) / (count(root)-1);
}


bool IntBinaryTree::inRange(TreeNode *p)
{
    if(p==NULL)
        return true;
    
    if( p -> value >= 0 &&  p -> value <= 100)
        return inRange(p -> left) && inRange(p -> right);
    else
        return false;
}

bool IntBinaryTree::inRange()
{
    return inRange( root);
}


// Driver  **************************************************************


int main() {
    
    int array[] = {10,5,7,2,12,14};
    IntBinaryTree t1;
    for (int i=0; i<6; i++)
        t1.insertNode (array[i]);
    
    cout << "PostOrder Traversal" << endl;
    t1.displayPostOrder();
    
    cout << "in range t1: " << boolalpha << t1.inRange() << endl;
    t1.insertNode(105);
    cout << "in range t1+105: " << boolalpha << t1.inRange() << endl;
    
    cout<<"Descendents of 5 \n";
    t1.printDescendents(5);
    cout<<"Descendents of 10 \n";
    t1.printDescendents(10);
    cout<<"Descendents of 100 \n";
    t1.printDescendents(100);
    
    cout<<"Ancestors of 2 \n";
    t1.printAncestors(2);
    
    cout<<"Ancestors of 105 \n";
    t1.printAncestors(105);
    
    cout << "Average, drop lowest: " << t1.AvgDropLowest() << endl;
    
}
