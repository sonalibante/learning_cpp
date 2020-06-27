// Quiz 2
// Fall 2018

#include <iostream>
using namespace std;

int main()
{
    int num ,digit ,count , digitCheck;
    bool oddCheck , evenCheck ;
    
    cout<<"Enter a positive number to use as a pass code : ";
    cin>>num;
    
    oddCheck = false;
    evenCheck = false;
    count = 0;
    
    while(num>0) {
        digit = num%10;
        
        if( digit%2 != 0)
            oddCheck = true;
        else
            evenCheck = true;
        
        num=num/10;
        count++;
    }
    
    
    if (oddCheck == true && evenCheck == true && count >= 4)
        cout<<"The pass code is accepted."<<endl;
    else
        cout<<"The pass code is not accepted."<<endl;
}


