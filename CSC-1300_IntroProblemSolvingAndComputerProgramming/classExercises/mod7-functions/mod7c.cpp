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

void getUserData(string &userName, string &userFavoriteFood, int &userFavoriteNumber)
{
    cout << "Name: ";
    getline(cin, userName);
    cout << "Favorite food: ";
    getline(cin, userFavoriteFood);
    cout << "Favorite number: ";
    cin >> userFavoriteNumber;
    cout << endl;
}