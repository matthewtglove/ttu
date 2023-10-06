/*
    Title: mod7b.cpp
    Author: Matthew Love
    Date: 2023-10-06, Fri
    Purpose: Pass paramaters into a function
*/

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

bool luckyGuess(int guess);

int main()
{
    srand(time(0));

    string name;
    string favoriteFood;
    int favoriteNumber;

    cout << "Welcome! Please input your name, favorite food, and your favorite number." << endl;
    cout << "Name: ";
    getline(cin, name);
    cout << "Favorite food: ";
    getline(cin, favoriteFood);
    cout << "Favorite number: ";
    cin >> favoriteNumber;
    cout << endl;

    if (luckyGuess(favoriteNumber))
    {
        cout << "Hooray! " << name << ", you will get infinite " << favoriteFood << " for the rest of your life!" << endl;
    }
    else
    {
        cout << "Sorry " << name << ", you were not lucky today. You get no " << favoriteFood << ". How unfortunate." << endl;
    }
}

bool luckyGuess(int guess)
{
    int randomNumber = (rand() % 100) + 1;
    unsigned int difference = randomNumber - guess;

    if (difference <= 25)
    {
        return true;
    }
    else
    {
        return false;
    }
}