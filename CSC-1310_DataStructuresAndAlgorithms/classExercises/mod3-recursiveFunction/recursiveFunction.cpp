/*
    Title: recursiveFunction.cpp
    Author: Matthew Love
    Date: 2024-01-25, Thu
    Purpose: Using a recursive function
*/
#include "recursiveFunction.h"
// I was crazy once

int i = 0;
int runningTotal = 0;
int sumArray(int intArray[], int arraySize)
{
    if (i == arraySize)
    {
        return runningTotal;
    }

    runningTotal += intArray[i];
    i++;
    return sumArray(intArray, arraySize);
}

// A rubber room