// BoxCar header file
// Lab 7 exercise 1
// Fall 2018
// js236

#include <string>
using namespace std;

#include "RailCar.h"

class BoxCar : public RailCar {
    
private:
    float capacity;
public:
    BoxCar(int,float);
    void print();
};
