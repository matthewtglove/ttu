/*
    Title: lab3c.cpp
    Author: Matthew Love
    Date: 2023-09-12, Tue
    Purpose: Using while loops by asking user to answer a math problem
*/

#include <iostream>
#include <cstring>
using namespace std;

// Attempted to make the int validation a function - Error: only returning 0
/*
void getIntFromUser(int intName)
{
    bool validInputInt = false;
    while (!validInputInt)
    {
        string input;
        // getline(cin, input); // Using getline() breaks the catch for some reason, and the program is terminated
        cin >> input;
        bool successfulConversion;

        try
        {
            stoi(input); // Tries to convert to number (should only works if input is number)
            successfulConversion = true;
        }
        catch (...)
        {
            // default not successful
        };

        if (!successfulConversion)
        {
            cout << "Please enter an integer: ";
        }
        else
        {
            int convertedInput = stoi(input); // Have to use stoi() to assign what was previously a string to int
            intName = convertedInput;

            validInputInt = true;
        }
    }
}
*/

int main()
{
    bool runAgain = true;

    while (runAgain)
    {
        runAgain = false;

        cout << "What is 4 + 18?" << endl;

        int answer = 0;

        // getIntFromUser(answer);

        // Validates user input - only accepts a number
        bool validInputInt = false;
        while (!validInputInt)
        {
            string input;
            // getline(cin, input); // Using getline() breaks the catch for some reason, and the program is terminated
            cin >> input;
            bool successfulConversion;

            try
            {
                stoi(input); // Tries to convert to number (should only works if input is number)
                successfulConversion = true;
            }
            catch (...)
            {
                // default not successful
            };

            if (!successfulConversion)
            {
                cout << "Please enter an integer: ";
            }
            else
            {
                int convertedInput = stoi(input); // Have to use stoi() to assign what was previously a string to int
                answer = convertedInput;

                validInputInt = true;
            }
        }

        if (answer == 22)
        {
            cout << "Correct! Great job" << endl;
        }
        else
        {
            cout << endl;
            cout << "Incorrect.\n"
                 << "Your answer: " << answer << "\n"
                 << "Expected answer: The right one" << endl;
            cout << endl;
        }

        // Asks the user if they would like to run the program again. Validates response and only accepts a string begining in 'y' or 'n' (not case sensitive)
        bool validYNInput = false;
        while (!validYNInput)
        {
            cout << "Would you like to run this program again? (y/n) ";

            // Parses user input - repeats only the first character they input
            string input;
            getline(cin, input);
            char runAgainResponse = tolower(input[0]);

            if (runAgainResponse == 'y')
            {
                validYNInput = true;
                runAgain = true;
            }
            else if (runAgainResponse == 'n')
            {
                validYNInput = true;
                runAgain = false;
            }
        }
    }

    return 0;
}