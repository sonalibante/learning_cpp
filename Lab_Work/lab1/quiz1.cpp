// Quiz 1
// Fall 2018

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int correctA, incorrectA, total;
    
    double correctPct, incorrectPct;
    
    cout << "Please enter the number of correct and incorrect answers: ";
    cin >> correctA >> incorrectA;
    
    total = correctA + incorrectA;
    
    correctPct = (double)(correctA*100)/total;
    incorrectPct = (double)(incorrectA*100)/total;
    
    cout << fixed << setprecision(2);
    
    cout<< "The percentage of correct answers: "<< correctPct <<endl;
    cout<< "The percentage of incorrect answers: "<< incorrectPct <<endl;
    
}

