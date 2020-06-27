// Exercise 1
// Lab 11
// Fall 2018
// js236

#include <iostream>
using namespace std;

void display (string a[], int size) {
    for (int i=0; i<size; i++)
        cout << a[i] << " ";
    cout << endl;
}


// Returns the index of the smallest element, starting at start
int findIndexOfMin (string array[], int size, int start) {
    int minIndex = start;
    for (int i = start+1; i < size; i++) {
        if (array[i] < array[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Sorts an array, using findIndexOfMin
int selectionSortA (string array[], int size) {
    int count = 0;
    int minIndex;
    for (int index = 0; index < (size -1); index++) {
        minIndex = findIndexOfMin(array, size, index);
        swap(array[minIndex],array[index]);
        cout << array[index] << endl;
        count ++;
    }
    return count;
}

int selectionSortB(string array[], int size)
{
    int count = 0;
    for(int i=0; i<size; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(array[i]>array[j])
            {
                swap(array[i],array[j]);
                count++;
            }
        }
        cout << array[i] << endl;
    }
    return count;
}

int main () {
    
    string slist[] = {"giraffe","horse","lion","dog","cat","elephant",};
    display(slist,6);
    int countA = selectionSortA(slist,6);
    display(slist,6);
    cout << "number of swaps: " << countA << endl;

    
    cout << "-------------------" << endl;
    
    
    string slist1[] = {"giraffe","horse","lion","dog","cat","elephant",};
    display(slist1,6);
    int countB = selectionSortB(slist1,6);
    display(slist1,6);
    cout << "number of swaps: " << countB << endl;

}
