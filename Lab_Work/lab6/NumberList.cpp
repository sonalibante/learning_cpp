// file NumberList.h
// implemented using an array

#include <cassert>
#include <iostream>
using namespace std;

template <class T>
class NumberList {
private:
    T array[100];           //contains the elements
    int count;                //tracks the current number of elements
    
public:
    NumberList();             // creates an empty list
    void appendNode(T);
    void deleteNode(T);
    void displayList();
};

template <class T>
NumberList<T>::NumberList()
{
    count = 0;
}
template <class T>
void NumberList<T>::appendNode(T num)
{
    assert (count < 100);
    array[count] = num;
    count++;
}
template <class T>
void NumberList<T>::deleteNode(T num)
{
    int i=0;
    while (i<count && array[i]!=num) {
        i++;
    }
    if (i<count) {
        count--;
        while (i<count) {
            array[i] = array[i+1];
            i++;
        }
    }
}
template <class T>
void NumberList<T>::displayList()
{
    for (int i=0; i<count; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    
    // set up the list
    NumberList<double> list;
    
    //Append Some values to the list
    list.appendNode(2.5);
    list.appendNode(7.9);
    list.appendNode(12.6);
    
    
    // Display the values in the list
    list.displayList();
    
    // Demo delete:
    cout << endl << "remove 7.9:" << endl;
    list.deleteNode(7.9);
    list.displayList();
    
    cout << endl << "remove 8.9: " << endl;
    list.deleteNode(8.9);
    list.displayList();
    
    cout << endl << "remove 2.5: " << endl;
    list.deleteNode(2.5);
    list.displayList();
    
    cout << endl << "remove 12.6: " << endl;
    list.deleteNode(12.6);
    list.displayList();
    
}
