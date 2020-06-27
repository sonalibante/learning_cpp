// File Name: Driver.cpp
//
// Author: Jill Seaman
// Date: 3/24/2017
// Assignment Number: 5
// CS 2308 Spring 2017
// Instructor: Jill Seaman
//
// A demo driver for StringList.
//

#include<iostream>
#include<iomanip>
using namespace std;

#include "StringList.h"

int main()
{
    //testing StringList
    StringList slist;

    string movie1 = "Star Wars";
    string movie2 = "Fargo";
    string movie3 = "Back to the Future";
    string movie4 = "Titanic";

    // Testing add/display/count
    cout << "Testing push_front/display/count: " << endl;
    cout << "count is: " << slist.count() << endl;

    slist.push_front(movie1);
    slist.display();
    cout << "count is: " << slist.count() << endl;

    slist.push_front(movie2);
    slist.display();
    cout << "count is: " << slist.count() << endl;

   slist.push_back(movie3);
   slist.push_back(movie4);
   slist.display();
    cout << "count is: " << slist.count() << endl;

   // Testing remove
    cout << endl;
   cout << "Testing remove: " << endl;
    cout << "remove at 0" << endl;
    slist.removeNode(0);
    slist.display();
    cout << "count is: " << slist.count() << endl;

    cout << "remove at 2 " << endl;
    slist.removeNode(2);
    slist.display();
    cout << "count is: " << slist.count() << endl;

 /*  //Testing pop_front()
   cout << endl;
    cout << "Testing pop_front: " << endl;
    slist.pop_front();
   cout << "pop_front: " << endl;
   slist.display();
    cout << "count is: " << slist.count() << endl;
    cout << "pop_front: " << endl;
    slist.pop_front();
    slist.display();
    cout << "count is: " << slist.count() << endl;
    cout << "pop_front (should not crash): " << endl;
    slist.pop_front();
    slist.display();
    cout << "count is: " << slist.count() << endl;
    */
//
//
//    // Testing maximum
//    StringList s2;
//    s2.push_front(movie1);
//    s2.push_front(movie3);
//
//    cout << endl;
//    cout << "Testing maximum: " << endl;
//
//    cout << "Test maximum 1: " << endl;
//    s2.display();
//    cout << "maximum: " << s2.maxElem() << endl;
//
//    cout << "Test maximum 2: " << endl;
//    s2.push_front(movie4);
//    s2.display();
//    cout << "maximum: " << s2.maxElem() << endl;
//
//    cout << "Test maximum 3: " << endl;
//    s2.push_front(movie2);
//    s2.display();
//    cout << "maximum: " << boolalpha << s2.maxElem() << endl;
//
//    //Testing sort and display
//    cout << endl;
//    cout << "Testing sort/display: " << endl;
//    s2.sort();
//    s2.display();
//
//    cout << endl;
//    cout << "Testing sort/display after push_front: " << endl;
//    s2.push_front("Jurassic Park");
//    s2.display();
//    cout << "now sorted: " << endl;
//    s2.sort();
//    s2.display();
}


/*  expected output:

 Testing push_front/display/count:
 count is: 0
 Star Wars
 count is: 1
 Fargo
 Star Wars
 count is: 2
 Fargo
 Star Wars
 Back to the Future
 Titanic
 count is: 4

 Testing remove:
 remove at 0
 Star Wars
 Back to the Future
 Titanic
 count is: 3
 remove at 2
 Star Wars
 Back to the Future
 count is: 2

 Testing pop_front:
 pop_front:
 Back to the Future
 count is: 1
 pop_front:
 count is: 0
 pop_front (should not crash):
 count is: 0

 Testing maximum:
 Test maximum 1:
 Back to the Future
 Star Wars
 maximum: Star Wars
 Test maximum 2:
 Titanic
 Back to the Future
 Star Wars
 maximum: Titanic
 Test maximum 3:
 Fargo
 Titanic
 Back to the Future
 Star Wars
 maximum: Titanic

 Testing sort/display:
 Back to the Future
 Fargo
 Star Wars
 Titanic

 Testing sort/display after push_front:
 Jurassic Park
 Back to the Future
 Fargo
 Star Wars
 Titanic
 now sorted:
 Back to the Future
 Fargo
 Jurassic Park
 Star Wars
 Titanic

 */
