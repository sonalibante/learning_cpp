// Quiz 11: Searching and Sorting
// Fall 2018

#include <iostream>
using namespace std;
//prototypes for quicksort function
void quickSort (int set[], int size);           //define this
void quickSort (int set[], int start, int end); //define this
int partition (int set[], int start, int end);  //Do NOT define this

// solution starts here:
// Quick sort
void quickSort (int set[], int size) {
    quickSort(set, 0, size-1);
}

void quickSort(int set[], int start, int end) {
    if (start < end) {
        int pivotPoint = partition(set, start, end);
        quickSort(set, start, pivotPoint - 1);
        quickSort(set, pivotPoint + 1, end);
    }
}

// linearSearch
struct Node {
    int value;
    Node * next;
};
int linearSearch (Node *head, int target) {

    Node *p = head;
    int count = 0;
    while (p!=NULL) {
        if (p->value==target)
            return count;
        count++;
        p = p->next;
    }
    return -1;
}

// This was assumed to be given, not part of the solution
int partition(int set[], int start, int end)
{
    int mid = (start + end) / 2;  // locate the pivot value
    swap(set[start], set[mid]);
    int pivotIndex = start;
    int pivotValue = set[start];
    for (int scan = start + 1; scan <= end; scan++)
    {  // finds values less than pivotValue and
        // moves them to the left of the pivotIndex
        if (set[scan] < pivotValue)
        {
            pivotIndex++;
            swap(set[pivotIndex], set[scan]);
        }
    }
    swap(set[start], set[pivotIndex]);
    return pivotIndex;
}
//for testing

void addToFront (Node *&head, int val) {
    Node *nn = new Node;
    nn->value = val;
    nn->next = head;
    head = nn;
}
int main()
{
    int tests[] = {9,7,3,4,2,10};
    quickSort(tests,6);
    for (int i=0; i<6; i++)
        cout << tests[i] << " ";
    cout << endl;
    
    //set up a linked list
    int tests2[] = {9,7,3,4,2,10};
    Node *head = NULL;
    for (int i=6; i>=0; i--)
       addToFront (head, tests2[i]);

    cout << linearSearch(head,9) << endl;
    cout << linearSearch(head,3) << endl;
    cout << linearSearch(head,8) << endl;
    cout << endl;
}
