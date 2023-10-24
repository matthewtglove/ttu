/*
    Title: mod8a.cpp
    Author: Matthew Love
    Date: 2023-10-23, Mon
    Purpose: Use arrays
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string thing[10];
    double price[10];

    cout << "Tell me 10 useful things and their price:\n"
         << endl;

    for (int i = 0; i < (sizeof(price) / sizeof(double)); i++)
    {
        cout << "Useful thing " << i + 1 << ": ";
        getline(cin, thing[i]);

        string priceString = "";
        cout << "Price for thing " << i + 1 << ": ";
        getline(cin, priceString);
        price[i] = stoi(priceString);
    }

    cout << endl;

    cout << "Your list of useful items include:\n";
    for (int i = 0; i < 10; i++)
    {
        cout << thing[i] << ", $" << price[i] << "\n";
    }

    cout << endl;
    return 0;
}