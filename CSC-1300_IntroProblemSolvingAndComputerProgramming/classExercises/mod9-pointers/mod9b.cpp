/*
    Title: mod9b.cpp
    Author: Matthew Love
    Date: 2023-10-31, Tue
    Purpose: Outputting an array of strings with pointers
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string coolFoods[10];
    string *pCoolFoods;

    pCoolFoods = coolFoods;

    cout << "Enter your favorite foods!" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "Favorite food " << i + 1 << ": ";
        getline(cin, *(pCoolFoods + i));
    }

    cout << endl;
    cout << "Great, here is your list: " << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << coolFoods[i] << endl;
    }

    return 0;
}
