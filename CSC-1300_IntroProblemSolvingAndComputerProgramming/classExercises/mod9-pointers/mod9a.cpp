/*
    Title: mod9a.cpp
    Author: Matthew Love
    Date: 2023-10-30, Mon
    Purpose: Using pointers
*/

#include <iostream>
using namespace std;

int main()
{
    double coolNumber = 7.25;
    double *coolPointer = nullptr;

    coolPointer = &coolNumber;

    cout << "Value of coolNumber: " << *coolPointer << endl;
    cout << "Memory address of coolNumber: " << coolPointer << endl;

    return 0;
}