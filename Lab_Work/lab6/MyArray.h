//Lab 6 Exercise 2: MyArray
//Fall 2018
//js236

#include <cassert>
using namespace std;

template <typename T>
class MyArray
{
private:
    T *data;        // array that stores the elements
    int size;       // size of the array
    int start;      // first index of array
    
public:
    MyArray (int);
    MyArray (int,int);
    MyArray (const MyArray &);
    ~MyArray();
    
    T getElement(int position);
    void setElement(int position, T item);
};

template <typename T>
MyArray<T>::MyArray (int s) {
    size = s;
    data = new T [size];
    start = 0;
}
template <typename T>
MyArray<T>::MyArray (int st, int end) {
    size = (end-st);
    data = new T [size];
    start = st;
}

template <class T>
MyArray<T>::MyArray(const MyArray &obj) {
    size = obj.size;
    data = new T [size];
    start = obj.start;
    for(int i = 0; i < size; i++)
        data[i] = obj.data[i];
}

template <class T>
MyArray<T>::~MyArray() {
    if (size>0)
        delete [] data;
}

template <class T>
T MyArray<T>::getElement(int position)
{
    assert (start <= position && position < start+size);
    return data[position-start];
}

template <class T>
void MyArray<T>::setElement(int position, T item)
{
    assert (start <= position && position < start+size);
    data[position-start] = item;
}



