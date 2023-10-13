/*
    Title: mod7c.cpp
    Author: Matthew Love
    Date: 2023-10-13, Fri
    Purpose: Pass by reference
*/

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

bool luckyGuess(int guess);

void getUserData(string &userName, string &userFavoriteFood, int &userFavoriteNumber);

int main()
{

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
