// PassengerCar, implementation file
// Lab 7 exercise 1
// Fall 2018
// js236

#include <iostream>
using namespace std;

#include "PassengerCar.h"

PassengerCar::PassengerCar(int id, int pn)
: RailCar(id) {
    passengerNum = pn;
}
void PassengerCar::print() {
    RailCar::print();
    cout << " Number of Passengers: " << passengerNum << endl;
}
