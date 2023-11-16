/*
    Title: lab10.cpp
    Author: Matthew Love
    Date: 2023-11-14, Tue
    Purpose: Recording details on chefs
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct PastryCategory
{
    string name;
    int countAwards;
};

struct Chef
{
    string name;
    string hometown;
    int numCategories;
};

int main()
{
    cout << "Welcome!" << endl;

    int numChefs;
    cout << "How many chefs are participating?" << endl;
    cin >> numChefs;
    cin.ignore();

    Chef *chef;
    chef = new Chef[numChefs];
    PastryCategory **awardsArray;
    awardsArray = new PastryCategory *[numChefs];

    // delete stuff
}