/*
    Title: lab3c.cpp
    Author: Matthew Love
    Date: 2023-09-12, Tue
    Purpose: Using while loops by asking user to answer a math problem
*/

#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

// Requires an int from the user
int reqIntFromUser()
{
    while (true)
    {
        try
        {
            string input;
            getline(cin, input);
            return stoi(input); // Tries to convert to number (should only works if input is number)
            break;
        }
        catch (...)
        {
            cout << "Please enter an integer: ";
            continue;
        };
    }
}

// Asks the user if they would like to run the program again. Validates response and only accepts a string begining in 'y' or 'n' (not case sensitive)
bool askRunAgain(string prompt = "Would you like to run this program again? (y/n) ")
{
    while (true)
    {
        cout << prompt;

        // Parses user input - repeats only the first character they input
        string input;
        getline(cin, input);
        char runAgainResponse = tolower(input[0]);

        if (runAgainResponse == 'y')
        {
            return true;
            break;
        }
        else if (runAgainResponse == 'n')
        {
            return false;
            break;
        }
    }
}

int main()
{
    bool runAgain = true;

    while (true)
    {
        srand(time(0));
        int num1 = rand() % 99;
        int num2 = rand() % 99;
        cout << "What is " << num1 << " + " << num2 << "?" << endl;

        int answer = reqIntFromUser();
        int correctAnswer = num1 + num2;

        if (answer == correctAnswer)
        {
            cout << "Correct! Great job" << endl;
        }
        else
        {
            cout << endl;
            cout << "Incorrect.\n"
                 << "Your answer: " << answer << "\n"
                 << "Expected answer: " << correctAnswer << endl;
            cout << endl;
        }

        if (askRunAgain())
        {
            continue;
        }
        else
        {
            break;
        }
    }
    return 0;
}