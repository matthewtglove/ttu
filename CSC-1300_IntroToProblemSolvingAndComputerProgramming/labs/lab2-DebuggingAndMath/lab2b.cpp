/*
    Filename: lab2a.cpp
    Author: Trey Gannod and Matthew Love
    Date: 2023-08-29, Tue
    Purpose: Display the approximate number of customers who purchased one of more energy drinks per week and the number of customers within that number who prefer citrus-flavored energy drinks.
*/

#include <iostream>

using namespace std;

int main()
{
    const int SURVERYED = 16500;
    const double PURCHASEDPERCENT = 15.00;
    const double CITRUSPERCENT = 58.00;

    // Calculates the num of people surveyed that buy at least one energy drink a week
    int PURCHASED = PURCHASEDPERCENT * (SURVERYED / 100);
    // Calculates the num of people surveyed that buy at least one energy drink a week and prefer citrus drinks
    int CITRUS = PURCHASED * (CITRUSPERCENT / 100);

    cout << "The number of people who buy 1 or more energy drinks a week are " << PURCHASED << "." << endl << endl;
    cout << "The number of people who but 1 or more enegry drinks a week and prefer citrus drinks are " <<  CITRUS << "." << endl;
}