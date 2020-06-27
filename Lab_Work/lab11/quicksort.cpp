// Exercise 2
// Lab 11
// Fall 2018
// js236

#include <stack>
#include <iostream>
using namespace std;

// Quick sort
int partition(int set[], int start, int end)
{
    stack<int> stck1;
    stack<int> stck2;
    
    int pivotValue = set[start];
    
    for (int i=start+1; i<=end; i++) {
        if (set[i] < pivotValue)
            stck1.push(set[i]);
        else
            stck2.push(set[i]);
    }
    
    int pivotIndex;
    int i = 0;
    
    while(!stck1.empty()) {
        set[start+i] = stck1.top();
        stck1.pop();
        i++;
    }
    pivotIndex = start+i;  //save to be returned at the end
    set[start+i]=pivotValue;
    i++;
    while(!stck2.empty()) {
        set[start+i] = stck2.top();
        stck2.pop();
        i++;
    }
    return pivotIndex;
}

void quickSort(int set[], int start, int end) {
    
    if (start < end)
    {
        // Get the pivot point.
        int pivotPoint = partition(set, start, end);
        // Sort the first sub list.
        quickSort(set, start, pivotPoint - 1);
        // Sort the second sub list.
        quickSort(set, pivotPoint + 1, end);
    }
}

void quickSort (int set[], int size) {
    quickSort(set, 0, size-1);
}

int main() {
    int a[] = {5,13,8,27,6,2,1,9,12,23,56,74,53,28};
    quickSort(a,14);
    for (int i=0; i<14; i++)
        cout << a[i] << " ";
    cout << endl;
}
