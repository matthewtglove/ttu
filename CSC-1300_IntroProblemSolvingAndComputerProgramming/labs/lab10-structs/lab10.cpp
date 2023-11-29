/*
    Title: lab10.cpp
    Author: Matthew Love
    Date: 2023-11-14, Tue
    Purpose: Recording details on chefs
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

// To hold the pastry award details for each award each chef earned
struct PastryCategory
{
    string name;
    int countAwards;
};

// For holding a chef's details
struct Chef
{
    string name;
    string hometown;
    int numCategories;
};

int main()
{
    cout << endl;
    cout << "Welcome!" << endl;

    int numChefs;
    cout << "How many chefs are participating? ";
    cin >> numChefs;
    cin.ignore();
    cout << endl;

    // To allow memory for each award each chef has
    Chef *chef;
    chef = new Chef[numChefs];
    PastryCategory **awardsArray;
    awardsArray = new PastryCategory *[numChefs];

    cout << endl;
    cout << "Please enter information about each chef." << endl;
    cout << endl;

    for (int i = 0; i < numChefs; i++)
    {
        cout << "---- CHEF " << i + 1 << " ----" << endl;

        cout << "\tNAME: ";
        getline(cin, chef[i].name);
        cout << "\tHOMETOWN: ";
        getline(cin, chef[i].hometown);

        cout << "\tHow many categories did " << chef[i].name << " win? ";
        cin >> chef[i].numCategories;
        cin.ignore();
        cout << endl;

        // Allocates the memory for each individual award
        awardsArray[i] = new PastryCategory[chef[i].numCategories];
        for (int j = 0; j < chef[i].numCategories; j++)
        {
            cout << "\tCATEGORY " << j + 1 << ":" << endl;

            cout << "\t\tName of category - ";
            getline(cin, awardsArray[i][j].name);

            cout << "\t\tNumber of awards in " << awardsArray[i][j].name << " - ";
            cin >> awardsArray[i][j].countAwards;
            cin.ignore();
            cout << endl;
        }
    }

    // Used to find the chef that has the most awards
    int maxAwards = numeric_limits<int>::min();
    int iMaxAwards = 0;
    for (int i = 0; i < numChefs; i++)
    {
        int countAwards = 0;
        for (int j = 0; j < chef[i].numCategories; j++)
        {
            countAwards += awardsArray[i][j].countAwards;
        }

        if (maxAwards < countAwards)
        {
            maxAwards = countAwards;
            iMaxAwards = i;
        }
    }

    cout << endl
         << endl;
    cout << "The pastry chef who has won the most awards (" << maxAwards << " awards) is " << chef[iMaxAwards].name << ", with awards in the following categories:" << endl;
    for (int j = 0; j < chef[iMaxAwards].numCategories; j++)
    {
        cout << "\t" << awardsArray[iMaxAwards][j].name << " (" << awardsArray[iMaxAwards][j].countAwards << ")" << endl;
    }

    cout << endl
         << endl;
    cout << "Goodbye now!" << endl;
}