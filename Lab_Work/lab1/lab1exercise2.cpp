// Lab1 exercise 2
// Fall 2018
// js236

#include <iostream>
using namespace std;
	

int main()
{
    int secondsElapsed, hours, minutes, seconds;
    
    const int secondsPerMinute = 60;
    const int secondsPerHour = 60 * secondsPerMinute;
    
    cout << "Please enter the number of seconds elapsed: ";
    cin >> secondsElapsed;
    
    hours = secondsElapsed / secondsPerHour;
    secondsElapsed = secondsElapsed % secondsPerHour;
    minutes = secondsElapsed / secondsPerMinute;
    seconds = secondsElapsed % secondsPerMinute;
    
    cout <<"The elapsed time in hours, minutes, and seconds: "
         << hours << ":" << minutes << ":" << seconds << endl;
    
    return 0;
}
