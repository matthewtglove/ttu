#include <iostream>
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
                convertedInput = stoi(input);
                successfulConversion = true;
            }
            catch (...)
            {
                cout << invalidInputMessage << " Please enter an integer " << minRange << "-" << maxRange << endl;
            };
        } while (!(successfulConversion));

        userInput = convertedInput;

        validRange = (userInput >= minRange && userInput <= maxRange);
        if (!validRange)
        {
            cout << invalidInputMessage << " Please enter " << minRange << "-" << maxRange << endl;
        }
    } while (!validRange);

    return userInput;
}