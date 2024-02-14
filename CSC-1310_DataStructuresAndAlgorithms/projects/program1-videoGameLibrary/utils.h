#ifndef UTILS_H
#define UTILS_H

#include <iostream>
using namespace std;

// Input validation
int requireIntInput(int minRange = INT_MIN, int maxRange = INT_MAX)
{
    int userInput = 0;
    bool validRange = false;
    do
    {
        userInput = 0;
        cin >> userInput;
        cin.ignore();

        validRange = (userInput >= minRange && userInput <= maxRange);
        if (!validRange)
        {
            if (!(minRange == INT_MIN && maxRange == INT_MAX))
            {
                cout << " Please enter " << minRange << " to " << maxRange;
            }
            if ((minRange == INT_MIN && maxRange == INT_MAX))
            {
                cout << "Please enter a number within range.";
            }
            cout << endl;
        }
    } while (!validRange);

    return userInput;
}

#endif