/*
    Title: lab9_b.cpp
    Author: Matthew Love
    Date: 2023-11-13, Mon
    Purpose: Using pointers
*/

#include <iostream>
using namespace std;

int main()
{
    int length;
    int width;
    int area;

    int *pLength = &length;
    int *pWidth = &width;

    cout << "Length of rectangle: ";
    cin >> *pLength;
    cout << "Width of rectangle: ";
    cin >> *pWidth;
    cout << endl;

    area = *pLength * *pWidth;

    cout << "The area is " << area << endl;

    if (*pLength > *pWidth)
    {
        cout << "The length is greater that the width" << endl;
    }
    else if (*pLength < *pWidth)
    {
        cout << "The width is greater that the length" << endl;
    }
    else if (*pLength == *pWidth)
    {
        cout << "The length and width are equal" << endl;
    }
    else
    {
        cout << "The length and/or width is not a real number" << endl;
    }

    return 0;
}