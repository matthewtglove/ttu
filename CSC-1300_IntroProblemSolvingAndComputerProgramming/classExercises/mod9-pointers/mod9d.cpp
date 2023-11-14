/*
    Title: mod9d.cpp
    Author: Matthew Love
    Date: 2023-11-06, Mon
    Purpose: Working with dynamically allocated memory
*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int requireIntInput(int minRange = INT_MIN, int maxRange = INT_MAX, string invalidInputMessage = "Invalid input.")
{
    int userInput = 0;
    bool validRange = false;
    do
    {
        int convertedInput;
        bool successfulConversion = false;
        do
        {
            try
            {
                string input;
                getline(cin, input);
                // Should fail if user did not input a number
                convertedInput = stoi(input);
                successfulConversion = true;
            }
            catch (...)
            {
                if (minRange == INT_MIN && maxRange == INT_MAX)
                {
                    cout << invalidInputMessage << " Please enter an integer." << endl;
                }
                else
                {
                    cout << invalidInputMessage << " Please enter an integer " << minRange << " to " << maxRange << endl;
                }
            };
        } while (!(successfulConversion));

        userInput = convertedInput;

        validRange = (userInput >= minRange && userInput <= maxRange);
        if (!validRange)
        {
            cout << invalidInputMessage << " Please enter " << minRange << " to " << maxRange << endl;
        }
    } while (!validRange);

    return userInput;
}

int main()
{
    int countDogsAdopt = 0;
    cout << "How many dogs can you adopt?" << endl;
    // cin >> countDogsAdopt;
    // cin.ignore();
    countDogsAdopt = requireIntInput();

    string *dogName;
    string *dogBreed;
    int *dogAge;

    dogName = new string[countDogsAdopt];
    dogBreed = new string[countDogsAdopt];
    dogAge = new int[countDogsAdopt];

    cout << setw(40) << setfill('*') << "" << endl;
    cout << setfill(' ');
    cout << left << "Enter the dog data:\n"
         << endl;

    for (int i = 0; i < countDogsAdopt; i++)
    {
        cout << "Dog " << i + 1 << endl;

        cout << "\tNAME: ";
        getline(cin, *(dogName + i));

        cout << "\tBREED: ";
        getline(cin, *(dogBreed + i));

        cout << "\tAGE: ";
        // cin >> *(dogAge + i);
        // cin.ignore();
        *(dogAge + i) = requireIntInput();
        cout << endl;
    }

    cout << setw(40) << setfill('*') << "" << endl;
    cout << setfill(' ');
    cout << "Your dog details printed out:\n"
         << endl;
    for (int i = 0; i < countDogsAdopt; i++)
    {
        cout << "Dog " << i + 1 << endl;

        cout << "\tNAME: " << *(dogName + i) << endl;
        cout << "\tBREED: " << *(dogBreed + i) << endl;
        cout << "\tAGE: " << *(dogAge + i) << endl;
        cout << endl;
    }

    delete[] dogName;
    delete[] dogBreed;
    delete[] dogAge;

    return 0;
}