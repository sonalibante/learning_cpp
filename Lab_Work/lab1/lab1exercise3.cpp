// Lab1 exercise 3
// Fall 2018
// js236

#include <iostream>
#include <iostream>
#include <iomanip>

using namespace std;
	

int main()
{
    double originalCost, salesTaxRate, finalPrice, salesTaxAmount, markupAmount;
    int markupPercentage;
    
    cout << "Please enter the original cost: $";
    cin >> originalCost;
    
    cout << "Please enter the mark-up percentage: ";
    cin >> markupPercentage;
    
    cout << "Please enter the sales tax percentage: ";
    cin >> salesTaxRate;
    
    markupAmount = originalCost * (markupPercentage / 100.0);
    salesTaxAmount = (originalCost + markupAmount) * (salesTaxRate / 100);
    finalPrice = originalCost + salesTaxAmount + markupAmount;
    
	cout << fixed << setprecision(2);
    
    cout << "Markup amount: $" << markupAmount << endl;

    cout << "Sales Tax: $" << salesTaxAmount << endl;

    cout << "Final Price: $" << finalPrice << endl;
    
    return 0;
}

