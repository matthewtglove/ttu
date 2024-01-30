/*
    Title: recursiveFunction.cpp
    Author: Matthew Love
    Date: 2024-01-25, Thu
    Purpose: Using a recursive function
*/
#include "recursiveFunction.h"

int main()
{
    // The array (Crazy)
    int funArray[10] = {3, 56, 4, 3, 4, 9, 85, 4, 22, 9};
    cout << "The sum of all elements is " << sumArray(funArray, 10) << ". This was calculated using a recursive function instead of a for loop because yes." << endl;

    return 0;
}

// A rubber room with