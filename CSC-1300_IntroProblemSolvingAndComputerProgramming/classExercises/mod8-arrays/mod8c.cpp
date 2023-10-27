/*
    Title: mod8c.cpp
    Author: Matthew Love
    Date: 2023-10-25, Wed
    Purpose: Using character arrays
*/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char name1[30] = "Matthew";
    string name2 = "Jamieson";

    cout << "name1: " << name1 << "\n";
    cout << "name2: " << name2 << "\n";
    cout << endl;

    cout << "What is your full name? ";
    cin.getline(name1, 30);
    cout << "What is your friend's full name? ";
    getline(cin, name2);

    cout << endl;
    cout << "name1: " << name1 << "\n";
    cout << "name2: " << name2 << "\n";
    cout << endl;

    strcpy(name1, "SCOUT");
    name2 = "JACK";

    size_t lengthName1 = strlen(name1);
    for (int i = 0; i < lengthName1; i++)
    {
        cout << name1[i] << "*";
    }

    cout << endl;
    size_t lengthName2 = name2.length();
    for (int i = 0; i < lengthName2; i++)
    {
        cout << name2[i] << "*";
    }

    cout << endl;

    return 0;
}