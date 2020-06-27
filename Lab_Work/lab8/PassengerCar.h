// PassengerCar header file
// Lab 7 exercise 1
// Fall 2018
// js236

#include <string>
using namespace std;

#include "RailCar.h"

class PassengerCar : public RailCar{
    
private:
    int passengerNum;
public:
    PassengerCar(int,int);
    void print();
};
