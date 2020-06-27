//Lab 4 exercise 1
//Fall 2018
//js236

#include <iostream>
using namespace std;

void sumdigit(int num, int*sum)
{
    sum = 0;
    while(num>0)
    {
        *sum=*sum+num%10;
        num=num/10;
    }
}

int * subst(int *arr, int size, int x, int y) {
    
    int *p = new int[size];
    for (int i=0; i<size; i++) {
        if(arr[i]==x)
            p[i] = y;
        else
            p[i]=arr[i];
    }
    return p;
}

int main()
{
    int num = 325;
    int sum = 0;
    sumdigit(num, &sum);
    cout<<"Sum of the digits: num = "<<num<< " sum = "<<sum<<endl;
    
    int arr[]={2,0,5,6,0,9,11,0,15,20,0};
    int n = 11;
    int *array1 = subst(arr,n,0,7);
    
    cout << "subst: " << endl;
    for (int i=0; i<11; i++) {
        cout << array1[i] << " ";
    }
    cout << endl;
    
    delete [] array1;
    
    return 0;
}
