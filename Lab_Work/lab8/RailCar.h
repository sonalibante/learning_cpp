// RailCar header file
// Lab 7 exercise 1
// Fall 2018
// js236

#ifndef RAILCAR_H
#define RAILCAR_H
#include <string>
using namespace std;

class RailCar {
    
private:
    int IDnumber;
public:
    RailCar(int);
    void setIDnumber(int);
    int getIDnumber();
    virtual void print();
};
#endif /* RAILCAR_H */
