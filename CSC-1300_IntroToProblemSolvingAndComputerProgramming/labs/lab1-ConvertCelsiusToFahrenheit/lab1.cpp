/*
    Title: labl.cpp
    Author: Matthew Love
    Date: January 2023
    Prupose: Convert Celsius to Fahrenheit
*/

#include <iostream>
using namespace std;

int main()
{
    double fahrenheit, celsius;
    cout << "\n\nWhat is the temperature (Celsius to Fahrenheit)? ";
    cin >> celsius;
    fahrenheit = (celsius * (9.0/5.0)) + 32;
    cout << "\nRESULT: " << celsius << " degrees Celsius is ";
    cout << fahrenheit << " degrees Fahrenheit.\n\n";
    return 0;
}