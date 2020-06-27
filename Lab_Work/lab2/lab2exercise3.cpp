//Lab 2 exercise 3
//Fall 2018
//js236

#include <iostream>

using namespace std;

int main()
{
    int popA, popB, year = 1;
    double growthRateA, growthRateB;
    
    cout << "Enter the population and growth rate of Town A: ";
    cin >> popA >> growthRateA;
    cout << endl;
    
    cout << "Enter the population and growth rate of Town B: ";
    cin >> popB >> growthRateB;
    cout << endl;
    
    
    if (popA < popB && growthRateA > growthRateB)
    {
        while (popA < popB)
        {
            // calculates population growth in one year of town A:
            popA = (((growthRateA / 100) * popA) + popA);
            
            // calculates population growth in one year of town B
            popB = (((growthRateB / 100) * popB) + popB);
            
            year++;
        }
        
        cout << "Town A will have more population than Town B after "
             << year << " years.\n" ;
        cout << "The final population of Town A is: " << popA << ".\n";
        cout << "The final population of Town B is: " << popB << ".\n";
    }
    else
    {
        cout << "Error Invalid Input: " << endl
        << "Town A population must be less than Town B population. "
        << endl
        << "and Town A growth rate must be higher than Town B growth rate."
        << endl;
    }
    
    return 0;
}