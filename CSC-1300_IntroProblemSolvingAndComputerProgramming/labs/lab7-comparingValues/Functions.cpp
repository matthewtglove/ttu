/*
    Title: Lab 7
    Author: Matthew Love
    Date: 2023-10-17, Tue
    Purpose: Check whether two superheros would be compatable as roommates
*/

#include "Lab7.h"

void getData(string &hero1Name, string &hero2Name, string &hero1Age, string &hero2Age, string &hero1Pet, string &hero2Pet)
{
    cout << "Enter the following for superhero 1:\n";

    cout << "NAME: ";
    getline(cin, hero1Name);
    cout << "AGE: ";
    getline(cin, hero1Age);
    cout << "FAVORITE PET: ";
    getline(cin, hero1Pet);

    cout << "Enter the following for superhero 2:\n";

    cout << "NAME: ";
    getline(cin, hero2Name);
    cout << "AGE: ";
    getline(cin, hero2Age);
    cout << "FAVORITE PET: ";
    getline(cin, hero2Pet);
}

bool calculateResults(string hero1Name, string hero2Name, int hero1Age, int hero2Age, string hero1Pet, string hero2Pet)
{
    // Check 1 - Name ASCII value within 50 of each other
    // int hero1NameValue = static_cast<int>(hero1Name);

    // Check 2 - Age within 10 years of each others

    // Check 3 - Same favorite pet
}