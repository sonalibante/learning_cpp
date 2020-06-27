// RailCar, implementation file
// Lab 7 exercise 1
// Fall 2018
// js236


#include <iostream>
#include <iomanip>
using namespace std;

#include "RailCar.h"

RailCar::RailCar(int id) {
    IDnumber = id;
}
void RailCar::setIDnumber(int id) {
    IDnumber = id;
}
int RailCar::getIDnumber() {
    return IDnumber;
}

void RailCar::print() {
    cout << "ID Number: " << IDnumber <<endl;
}
