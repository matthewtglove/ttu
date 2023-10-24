/*
    Title: mod8b.cpp
    Author: Matthew Love
    Date: 2023-10-23, Mon
    Purpose: Passing arrays into functions
*/

#include <iostream>
#include <string>
using namespace std;

double findHighest(double inputArray[])
{
    int arrayLength = 10;

    double maxValue = inputArray[0];
    for (int i = 0; i < arrayLength; i++)
    {
        if (inputArray[i] > maxValue)
        {
            maxValue = inputArray[i];
        }
    }

    return maxValue;
}

double findLowest(double inputArray[])
{
    int arrayLength = 10;

    double minValue = inputArray[0];
    for (int i = 0; i < arrayLength; i++)
    {
        if (inputArray[i] < minValue)
        {
            minValue = inputArray[i];
        }
    }

    return minValue;
}

double findAverage(double inputArray[])
{
    int arrayLength = 10;

    double arrayTotal;
    for (int i = 0; i < arrayLength; i++)
    {
        arrayTotal += inputArray[i];
    }

    return arrayTotal / arrayLength;
}

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

    int iHighestPrice = findHighest(price);
    int iLowestPrice = findHighest(price);
    int averagePrice = findAverage(price);

    cout << "*****RESULTS*****\n";
    cout << "HIGHEST PRICE: " << thing[iHighestPrice] << " with price $" << price[iHighestPrice] << "\n";
    cout << "LOWEST PRICE: " << thing[iLowestPrice] << " with price $" << price[iLowestPrice] << "\n";
    cout << "AVERAGE PRICE: " << averagePrice << "\n";

    return 0;
}