/*
    Title: Lab 7
    Author: Matthew Love
    Date: 2023-10-17, Tue
    Purpose: Check whether two superheros would be compatable as roommates
*/

#include "Lab7.h"

int main()
{
    cout << setw(74) << setfill('-') << "" << endl;
    cout << "Welcome to the Super Hero Roommate Compatibility Checker! Please input your Super Hero details.\n"
         << endl;

    string hero1Name;
    string hero2Name;
    int hero1Age;
    int hero2Age;
    string hero1Pet;
    string hero2Pet;

    getData(hero1Name, hero2Name, hero1Age, hero2Age, hero1Pet, hero2Pet);
    bool compatible = calculateResults(hero1Name, hero2Name, hero1Age, hero2Age, hero1Pet, hero2Pet);

    cout << endl;
    cout << "***** RESULTS *****" << endl;
    if (compatible)
    {
        cout << "Hooray! " << hero1Name << " and " << hero2Name << " are compatible to be roommates!" << endl;
    }
    else
    {
        cout << hero1Name << " and " << hero2Name << " are not compatible to be roommates. Best not put them together." << endl;
    }

    return 0;
}