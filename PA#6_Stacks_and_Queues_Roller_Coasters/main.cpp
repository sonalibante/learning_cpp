// File Name: StackDriver.cpp
//
// Author: Jill Seaman
// Date: 4/14/2019
// Assignment Number: 6
// CS 2308.255 and CS 5301 Spring 2019
// Instructor: Jill Seaman
//
// A demo driver for Stack.
//

#include "Stack.h"
#include <iostream>
#include <iomanip>
using namespace std;

void testEmpty() {
    cout << "------- Test case 1, empty stack -------\n";
    //testing StringList
    Stack stack;

    // testing on empty list
    cout << "isEmpty: " << boolalpha << stack.isEmpty() << endl;
}

void testSizeOne() {
    cout << "------- Test case 2, stack of size 1 -------\n";
    //testing StringList
    Stack stack;
    stack.push("Star Wars");

    cout << "isEmpty: " << boolalpha << stack.isEmpty() << endl;
    cout << "top: " << stack.pop() << endl;
}

void testSizeTwo() {
    cout << "------- Test case 3, stack of bigger size  -------\n";
    //testing StringList
    Stack stack;
    stack.push("Star Wars");
    stack.push("Back to the Future");

    cout << "top: " << stack.pop() << endl;
    cout << "isEmpty: " << boolalpha << stack.isEmpty() << endl;
    cout << "top: " << stack.pop() << endl;
    cout << "isEmpty: " << boolalpha << stack.isEmpty() << endl;
}

int main()
{
    testEmpty();
    testSizeOne();
    testSizeTwo();
}
