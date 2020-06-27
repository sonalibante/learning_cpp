// Exercise 1
// Lab 10
// Fall 2018
// js236

#include <iostream>
using namespace std;

void multiples (int x, int n)
{
   if (n != 0)
   {
      multiples (x, n-1);
      cout<< x*n <<" ";
   }
} 

void subst (int arr[],int size, int x , int y )
{
      if (size != 0)
      {
         subst (arr, size-1, x, y ) ;
         if (arr[size-1] == x)
         {
             arr[size-1] = y;
         }
      }
}

int indexOfSpace (string str)
{
    if (str.empty())
        return -1;
    
    char x = str[0];
    if(x == ' ')
    {
        return 0;
    }
    else
    {
        int result = indexOfSpace(str.substr(1,str.size()));
        if (result==-1)
            return -1;
        else
            return result+1;
    }
}

void parseString (string str)
{
    if (str.empty())
    {
        cout<<" ";
    }
    else
    {
        int n = indexOfSpace(str);
        if (n==-1)
            cout << str << endl;
        else {
            cout << str.substr(0,n) << endl;
            parseString (str.substr(n+1,str.size()));
        }
   }
}

int main () {
    
    // Test multiples
    cout << "multiples: " << endl;
    multiples(800,3);
    cout << endl;
    multiples(7,10);
    cout << endl;
    multiples(3,25);
    cout << endl;
    
    // Test subst
    int arr[]={2,0,5,6,0,9,11,0,15,20,0};
    int n = 11;
    subst(arr,n,0,7);
    
    cout << "subst: " << endl;
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Test indexOfSpace function
    cout << "indexOfSpace: " << endl;
    cout << "indexOfSpace(\"I am kilroy\")  " << indexOfSpace("I am kilroy");
    cout << endl;
    cout << "indexOfSpace(\"Computer Science\")  "
         << indexOfSpace("Computer Science");
    cout << endl;
    cout << "indexOfSpace(\"IHaveNoSpaces\")  " << indexOfSpace("IHaveNoSpaces");
    cout << endl;

    // Test parseString function
    cout << "parseString: " << endl;
    cout << "parseString(\"I am kilroy\")  " << endl;
    parseString("I am kilroy");
    cout << endl;
    cout << "parseString(\"Computer Science\")  " << endl;
    parseString("Computer Science");
    cout << endl;
    cout << "parseString(\"IHaveNoSpaces\")  " << endl;
    parseString("IHaveNoSpaces");
    cout << endl;
}
