/*
    Title: mod7d.cpp
    Author: Matthew Love
    Date: 2023-10-13, Fri
    Purpose: Splitting up program into multiple files
*/

#include "luckyguess.h"

int main()
{
    srand(time(0));

    string name;
    string favoriteFood;
    int favoriteNumber;

    cout << "Welcome! Please input your name, favorite food, and your favorite number." << endl;
    getUserData(name, favoriteFood, favoriteNumber);

    if (luckyGuess(favoriteNumber))
    {
        cout << "Hooray! " << name << ", you will get infinite " << favoriteFood << " for the rest of your life!" << endl;
    }
    else
    {
        cout << "Sorry " << name << ", you were not lucky today. You get no " << favoriteFood << ". How unfortunate." << endl;
    }
}
