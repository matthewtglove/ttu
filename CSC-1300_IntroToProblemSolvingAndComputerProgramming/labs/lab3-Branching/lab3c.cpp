/*
    Title: lab3c.cpp
    Author: Matthew Love
    Date: 2023-09-12, Tue
    Purpose: Using while loops by asking user to answer a math problem
*/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    bool runAgain = true;

    while (runAgain)
    {
        runAgain = false;

        cout << "What is do you get when you add 4 + 18? " << endl;

        int answer;
        cin >> answer;

        cout << "Enter the letter 'y' if you want to quit. " << endl;

        char runAgainResponse;
        cin >> runAgainResponse;

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

        if (runAgainResponse != 'y')
        {
            cout << "The letter you entered is " << runAgainResponse << endl;
            runAgain = true;
        }
        else
        {
            cout << "The letter you entered is " << runAgainResponse << endl;
            runAgain = false;
        }
    }

    return 0;
}