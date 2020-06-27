// Lab1 exercise 1
// Fall 2018
// js236

#include <iostream>
#include <iomanip>
#include <math.h>   
using namespace std; 

int main()
{
    double Principal, Rate, CI;
    int Time;

    cout << "Please enter the Principal amount: ";
    cin >> Principal;

    cout << "Please enter the Rate: ";
    cin >> Rate;

    cout << "Please enter the Time: ";
    cin >> Time;
 
    /* Calculate compound interest */
    CI = Principal * (pow((1 + Rate / 100), Time));

    cout << fixed << setprecision(3);
 
    cout << "Compound interest is: " << CI << endl;
 
    return 0;
}
