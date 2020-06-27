//Lab 2 exercise 2
//Fall 2018
//js236

#include <iostream>
#include <iomanip> 
using namespace std;

int main(){
    
    int n; //number
    cout << "Enter a number: ";
    cin >> n;

    cout << endl;
    
    for(int j=1; j<=100; j++) //loop from 1 to 100 (10 rows)
    {
        cout << setw(5) << j*n << "  "; //print multiple of n
        if( j%10 == 0 )    //every 10 numbers (10 columns)
            cout << endl;  //start new line
    }
    return 0;
}

// here is the solution with nested loops:
/*
int main(){
    
    int n; //number
    cout << "Enter a number: ";
    cin >> n;
    
    cout << endl;
    
    int sum = 0;
    for (int i=1; i<=10; i++) {
        for(int j=1; j<=10; j++)
        {
            sum = sum + n;
            cout << setw(5) << sum << "  ";
        }
        cout << endl;
    }
    return 0;
}
*/