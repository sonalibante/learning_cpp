//Lab 2 exercise 1
//Fall 2018
//js236

#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
    float totalHours, hours, overtime, hourlyRate;
    
    cout << "Enter the weekly hours: " ;
    cin >> totalHours;
    cout<<"Enter the hourly rate: ";
    cin>>hourlyRate;
    
    overtime = totalHours - 40; // calculate the overtime hours
    
    if(totalHours > 40) //if the total hours is grater than 40
        hours = 40;
    
    else                //if the total hours is less than or equal to 40
        hours = totalHours;
    
    float weeklyPay = hours * hourlyRate;
    float overtimePay = 0;
    float extraOvertime = 0;
    
    if (overtime > 0)
    {
        if (overtime > 10)   //if overtime hours more 10
        {
            extraOvertime = overtime - 10; //calculate the extra overtime hours
            overtimePay = hourlyRate * 1.5 * 10;
            overtimePay += hourlyRate * 2.5 * extraOvertime;
        }
        else   // if overtime hours 10 or less
        {
            overtimePay = hourlyRate * 1.5 * overtime;
        }
    }
    
    cout << fixed << setprecision(2);
    cout << "This week pay = $" << weeklyPay + overtimePay << endl;
    
    return 0;
}
