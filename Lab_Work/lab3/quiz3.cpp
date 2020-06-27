// Quiz 3
// Fall 2018

#include <iostream>
using namespace std;
double median(int a[],int n)
{
    int mid = n/2;
    if(n%2 !=0)
        return a[mid];
    else
        return (double)(a[mid-1]+a[mid])/2;
}

double trimmedMean (int array[], int size)
{
    int total = 0;
    for (int i=1; i<size-1; i++)
        total += array[i];
    return (double)total/(size-2);
}

int main()
{
    int a[]={3,5,7,7,8,8,9,99};
    cout << "Median = " << median(a,8) << endl;
    cout << "Trimmed Mean = " << trimmedMean(a,8) << endl;
    return 0;
}


