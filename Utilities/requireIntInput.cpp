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