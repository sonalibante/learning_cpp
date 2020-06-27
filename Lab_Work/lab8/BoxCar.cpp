// BoxCar, implementation file
// Lab 7 exercise 1
// Fall 2018
// js236

#include <iostream>
using namespace std;

#include "BoxCar.h"

BoxCar::BoxCar(int id, float c)
: RailCar(id) {
    capacity = c;
}
void BoxCar::print() {
    RailCar::print();
    cout << " Capacity: " << capacity << endl;
}
