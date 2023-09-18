/*
    Title: lab3c-improved.cpp
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
            break;              // Used to exit the while loop
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

        // Validates user input - reads only the first character they input
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
    while (true)
    {
        // Gets a random number for the math problem
        srand(time(0));
        int num1 = rand() % 99;
        int num2 = rand() % 99;
        cout << "What is " << num1 << " + " << num2 << "?" << endl;

        int userAnswer = reqIntFromUser();
        int correctAnswer = num1 + num2;

        if (userAnswer == correctAnswer)
        {
            cout << "Correct! Great job" << endl;
            cout << endl;
        }
        else
        {
            cout << endl;
            cout << "Incorrect.\n"
                 << "Your answer: " << userAnswer << "\n"
                 << "Expected answer: " << correctAnswer << endl;
            cout << endl;
        }

        // Uses the boolean returned by askRunAgain() to determine playAgain
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