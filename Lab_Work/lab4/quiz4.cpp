// Quiz 4
// Fall 2018

#include <iostream>
#include <cmath>
using namespace std;

//part 1
int *padArray(int arr[],int n) {
    int size = n+6;
    int *result = new int[size];
    
    for (int i=0; i<3; i++) {
        result[i]=1;
        result[(size-1)-i]=1;
    }
    for(int j = 0; j<n; j++)
        result[j+3]=arr[j];
    return result;
}

//part 2
struct Point {
    double x;
    double y;
};

int main() {
    Point points[4]={{-1,3},{11.5,3},{-1,2},{8,2}};
    
    for(int i = 0; i<4;i++)
        cout << sqrt(pow(points[i].x,2)+pow(points[i].y,2)) << endl;
    
    //part 3
    int arr[4]={2,3,4,5};
    int *pArr = padArray(arr,4);
    for (int i=0; i<10; i++)
        cout << pArr[i] << " ";
    cout << endl;
    delete [] pArr;
}
