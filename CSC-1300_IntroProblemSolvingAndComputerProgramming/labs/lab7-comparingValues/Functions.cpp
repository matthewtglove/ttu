/*
    Title: Lab 7
    Author: Matthew Love
    Date: 2023-10-17, Tue
    Purpose: Check whether two superheros would be compatable as roommates
*/

#include "Lab7.h"

void getData(string &hero1Name, string &hero2Name, int &hero1Age, int &hero2Age, string &hero1Pet, string &hero2Pet)
{
    cout << "Enter the following for superhero 1:\n";

    cout << "NAME: ";
    getline(cin, hero1Name);
    cout << "AGE: ";
    cin >> hero1Age;
    cin.ignore();
    cout << "FAVORITE PET: ";
    getline(cin, hero1Pet);

    cout << "Enter the following for superhero 2:\n";

    cout << "NAME: ";
    getline(cin, hero2Name);
    cout << "AGE: ";
    cin >> hero2Age;
    cin.ignore();
    cout << "FAVORITE PET: ";
    getline(cin, hero2Pet);
}

bool calculateResults(string hero1Name, string hero2Name, int hero1Age, int hero2Age, string hero1Pet, string hero2Pet)
{
    // Check 1 - Name ASCII value within 50 of each other
    bool check1;
    int hero1NameValue = 0;

    int testTimesRun1;
    for (int i = 0; i < hero1Name.length(); i++)
    {
        hero1NameValue += static_cast<int>(hero1Name[i]);
        testTimesRun1++;
    }

    cout << testTimesRun1 << endl;

    int hero2NameValue = 0;
    for (int i = 0; i < hero2Name.length(); i++)
    {
        hero2NameValue += static_cast<int>(hero2Name[i]);
    }

    cout << endl;
    cout << "The added ASCII value of " << hero1Name << " is " << hero1NameValue << endl;
    cout << "The added ASCII value of " << hero2Name << " is " << hero2NameValue << endl;

    int nameDifference = abs(hero1NameValue - hero2NameValue);
    check1 = nameDifference <= 50;

    string check1Text = check1 ? "true" : "false";
    cout << "Check 1 is " << check1Text << "." << endl;

    // Check 2 - Age within 10 years of each other
    bool check2;

    int ageDifference = abs(hero1Age - hero2Age);
    check2 = ageDifference <= 10;

    string check2Text = check2 ? "true" : "false";
    cout << "Check 2 is " << check2Text << "." << endl;

    // Check 3 - Same favorite pet
    int check3 = hero1Pet == hero2Pet;

    string check3Text = check3 ? "true" : "false";
    cout << "Check 2 is " << check3Text << "." << endl;

    int countPassed = 0;
    if (check1)
    {
        countPassed++;
    }
    if (check2)
    {
        countPassed++;
    }
    if (check3)
    {
        countPassed++;
    }

    return (countPassed >= 2);
}