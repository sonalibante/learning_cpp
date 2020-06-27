// File Name: assign3_s_b611.cpp
// Author: Sonali Bante
// Date: 2/27/2019
// Assignment Number: 3
// CS 5301.255 Spring 2019
// Instructor: Jill Seaman
/* C++  program that will implement and test the five functions described below
that use pointers and dynamic memory allocation. */

#include<iostream>
using namespace std;

/************************************************************************
* function name: minimum - Function to find minimum value in array      *
*                without using square brackets.                         *
* param-1: array -  pointer to integer array (test data)                *
* param-2: size  - size of array passed as argument to this function.   *
* returns: min   - return the minimum value from the array              *
************************************************************************/
int minimum(int *array, int size)
{
    int min = *(array);            // variable to store minimum value
    for (int i=1; i< size; i++)
    {
        if(*(array+i) < min)       // pointer operator used with array variable
            min = *(array+i);
    }
    return min;
}

/**************************************************************************
* function name: swapTimesTen - using reference parameters i.e. pointers  *
*                instead of reference variables which swaps the value of  *
*                 variables and multiply them by 10.                      *
* param-1: *x  -  pointer to variable x                                   *
* param-2: *y  -  pointer to variable x                                   *
* returns:     - return addition of values in variable x, y               *
**************************************************************************/
int swapTimesTen (int *x, int *y)
{
    int temp = *x;                 // stores value in temp. variable
    *x = *y * 10;                  // swap value in y into x and multiply by 10
    *y = temp * 10;                // swap value in x into y and multiply by 10
    return *x + *y;                // return addition of with new values of x,y
}

/******************************************************************************
* function name: doubleArray - Function that takes an int array and the       *
*                array's size as arguments doubles it's size stores original  *
*                array and double of the original array respective positions  *
* param-1: array - integer array (test data)                                  *
* param-2: size  - size of array passed as argument to this function.         *
* returns: p     - returns a pointer to new doubled array                     *
******************************************************************************/
int *doubleArray(int array[], int size)
{
    if (size <= 0)                 // size must be positive
        return NULL;               // NULL is 0, an invalid address

    /* create a new array that is twice the size of the argument array */
    int *p = new int[2*size];

    /* copy contents of the argument array to first half of the new array */
    for (int i=0; i<size; i++)
    {
        p[i] = array[i];
    }

    /* copy the contents of the argument array each
    multiplied by 2 to the second half of the new array */
    for (int i=size; i<(2*size); i++)
    {
        p[i] = 2*array[i];
    }
    return p;
}

/******************************************************************************
* function name: subArray - Function that takes an int array and the          *
*                array's size as arguments doubles it's size stores original  *
*                array and double of the original array respective positions  *
* param-1: array  - integer array (test data)                                 *
* param-2: index  - starting index of desired sub array                       *
* param-3: length - desired length of sub array                               *
* returns: p      - returns a pointer to new sub array                        *
******************************************************************************/
int *subArray(int array[], int index, int length)
{
    int size = index+length;       // variable to calculate size of new array

    /* create a new array with size calculated with start index and length */
    int *p = new int[size];

    /* starting at the start index, and has length equal
    to the length argument passed to function */
    for (int i=0; i<size ; i++)
    {
        *(p+i) = array[index+i];   //copy of elements from the original array
    }
    return p;
}

/******************************************************************************
* function name: duplicateArray - No changes in duplicateArray, Code for the  *
*                 definition of the duplicateArray function from Unit 3 notes *
* param-1: array -  pointer to integer array (test data)                      *
* param-2: size  - size of array passed as argument to this function.         *
* returns: p     - returns a pointer to new duplicate array                   *
******************************************************************************/
int *duplicateArray (int *array, int size)
{
    if (size <= 0)                  //size must be positive
        return NULL;                //NULL is 0, an invalid address

    int *p = new int [size];      //allocate new array
    for (int index = 0; index < size; index++)
        p[index] = array[index]; //copy to new array
    return p;
}

/******************************************************************************
* function name: subArray2 - No alteration in subArray2 from question         *
*                starting index of Sub Array and size of array filled in      *
*                proper blanks mentioned in question.                         *
* param-1: array  - pointer to integer array (test data)                      *
* param-2: start  - starting index of desired sub array                       *
* param-3: length - desired length of sub array                               *
* returns: result - returns a pointer to new sub array                        *
******************************************************************************/
int *subArray2 (int *array, int start, int length)
{
    // variable to store result of function duplicateArray
    int *result = duplicateArray(&*(array+start), (start+length));
    return result;
}

/******************************************************************************
* function name:arrayDisplay - Recommended function to display values in array*
* param-1: array  - pointer to integer array (test data)                      *
* param-2: start  - starting index of desired sub array                       *
* param-3: length - desired length of sub array                               *
* returns: result - returns a pointer to new sub array                        *
******************************************************************************/
void arrayDisplay(int *array, int size)
{
    for (int i=0; i< size; i++)
    {
        cout << *(array+i) << " ";
    }
    cout << "\n";
    delete [] array;
}

/*  main function which is functioning as driver function*/
int main()
{
    // constant test data arrays
    int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, -8, 9, 0 };
    int arr2[10] = { 1, 2, 3, 4, 5, 16, 7, 8, 9, 0 };
    int arr3[9]  = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr4[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    /* a label indicating which function is being tested */
    cout << "testing minimum:\n";

    /* output desired four lines to compare results */
    cout << "test data:  1 2 3 4 5 6 7 -8 9 0 \n";
    cout << "Expected minimum: -8\n" ;
    // function call using the test data
    cout << "Actual minimum  : " << minimum(arr1, 10) << "\n";

    /* output desired four lines to compare results */
    cout << "test data: 1 2 3 4 5 16 7 8 9 0\n";
    cout << "Expected minimum: 0\n" ;
    // function call using the test data
    cout << "Actual minimum  : " << minimum(arr2, 10) << "\n";

    /*a label indicating which function is being tested which demonstrate
        that it changes the values of the variables passed into it */
    cout << "\ntesting swapTimesTen:\n";
    int a=3, b=5;    // variable a, b to store values and pass to function

    // function call using the test data
    int z= swapTimesTen(&a, &b);     // variable z to store result of function
    cout << "Expected result: 80 a: 50 b: 30 \n";
    cout << "Actual results : " << z << " a: "<< a << " b: " << b << "\n";

    /* a label indicating which function is being tested */
    cout << "\ntesting doubleArray:\n";

    // function call using the test data and stored in a variable output1
    int *output1 = doubleArray(arr3, 9);
    /* output desired four lines to compare results */
    cout << "test data: 1 2 3 4 5 6 7 8 9\n";
    cout << "Expected result: 1 2 3 4 5 6 7 8 9 2 4 6 8 10 12 14 16 18 \n";
    cout << "Actual result  : ";
    arrayDisplay(output1, 18);

    /* a label indicating which function is being tested */
    cout << "\ntesting subArray:\n";

    // function call using the test data and stored in a variable output2
    int *output2 = subArray(arr4, 5, 4);
    /* output desired four lines to compare results */
    cout << "test data: 1 2 3 4 5 6 7 8 9 10\n";
    cout<< "start: 5 length: 4\nExpected result: 6 7 8 9\n";
    cout<< "Actual result  : ";
    arrayDisplay(output2, 4);

    /* a label indicating which function is being tested */
    cout << "\ntesting subArray2:\n";

    // function call using the test data and stored in a variable output3
    int *output3 = subArray2(arr4, 5, 4);
    /* output desired four lines to compare results */
    cout << "test data: 1 2 3 4 5 6 7 8 9 10\n";
    cout<< "start: 5 length: 4\nExpected result: 6 7 8 9\n";
    cout<< "Actual result  : ";
    arrayDisplay(output3, 4);

    delete [] output1;
    delete [] output2;
    delete [] output3;

    return 0;
}
