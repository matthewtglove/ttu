/*
    Title: mod7a.cpp
    Author: Matthew Love
    Date: 2023-10-04, Wed
    Purpose: Check for number of digits or characters in a given string
*/

#include <iostream>
#include <string>
using namespace std;

int countCharacters(string inputString, int whatToCount);

int main()
{
    string givenString;

    cout << "Please input a string of characters: ";
    getline(cin, givenString);

    cout << "Number of digits: " << countCharacters(givenString, 1) << endl;
    cout << "Number of punctuation characters: " << countCharacters(givenString, 2) << endl;
}

int countCharacters(string inputString, int whatToCount)
{
    if (whatToCount == 1)
    {
        int digitCount = 0;
        for (int i = 0; i < inputString.length(); i++)
        {
            if (isdigit(inputString.at(i)))
            {
                digitCount++;
            }
        }

        return digitCount;
    }
    else if (whatToCount == 2)
    {
        int punctCount = 0;
        for (int i = 0; i < inputString.length(); i++)
        {
            if (ispunct(inputString.at(i)))
            {
                punctCount++;
            }
        }

        return punctCount;
    }
    else
    {
        cout << "ERROR: Invalid 2nd paramater for function countCharacters (1: count digits, 2: count punctuation)" << endl;
        return 0;
    }
}