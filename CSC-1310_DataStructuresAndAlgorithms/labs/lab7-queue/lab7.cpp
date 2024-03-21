/*
    Title: lab7.cpp
    Author: Matthew Love
    Date: 2024-03-20, Wed
    Purpose: Using a queue because that's cool 👍
*/

#include "Queue.h"

// Input validation
int requireIntInput(int minRange = INT_MIN, int maxRange = INT_MAX, string invalidInputMessage = "Invalid input.") {
    int userInput = 0;
    bool validRange = false;
    do {
        int convertedInput;
        bool successfulConversion = false;
        do {
            try {
                string input;
                getline(cin, input);
                // Should fail if user did not input a number
                convertedInput = stoi(input);
                successfulConversion = true;
            } catch (...) {
                if (minRange == INT_MIN && maxRange == INT_MAX) {
                    cout << invalidInputMessage << " Please enter an integer." << endl;
                } else {
                    cout << invalidInputMessage << " Please enter an integer " << minRange << " to " << maxRange << endl;
                }
            };
        } while (!(successfulConversion));

        userInput = convertedInput;

        validRange = (userInput >= minRange && userInput <= maxRange);
        if (!validRange) {
            cout << invalidInputMessage << " Please enter " << minRange << " to " << maxRange << endl;
        }
    } while (!validRange);

    return userInput;
}

int main() {
    Queue regularPass;
    Queue instantPass;

    cout << "Welcome to the Terror Park." << endl
         << endl;

    bool endProgram = false;
    do {
        cout << endl;
        cout << "What to do?" << endl;
        cout << "1.\tAdd a rider to the waiting line (do it you won't)" << endl;
        cout << "2.\tRemove a rider from the queue (their turn to ride)" << endl;
        cout << "3.\tLeave the park (why?)" << endl;

        cout << "CHOICE: ";
        int menuChoice = requireIntInput(1, 3, "Wrong. You lose. Good day sir.");
        switch (menuChoice) {
        case 1: {
            cout << endl;
            cout << "What's your name?" << endl;
            string name;
            cin.ignore();
            getline(cin, name);

            // Any integer except 1 will be treated as a regular pass
            cout << "Do you have an InstantPass holder? (type 1 for yes)" << endl;
            int hasInstantPass = requireIntInput();

            if (hasInstantPass == 1) {
                instantPass.enqueue(name);
                break;
            }
            regularPass.enqueue(name);
            break;
        }

        case 2: {
            cout << endl;
            if (!instantPass.isEmpty()) {
                string rider = instantPass.dequeue();
                cout << "An InstantPass rider, " << rider << ", was boarded onto the ride." << endl;
                break;
            }
            if (!regularPass.isEmpty()) {
                string rider = regularPass.dequeue();
                cout << "A regular pass rider, " << rider << ", was boarded onto the ride." << endl;
                break;
            }
            cout << "There are no riders in line." << endl;
            break;
        }

        case 3: {
            cout << endl;
            cout << "Too many people died? That's a shame." << endl;
            cout << endl;
            endProgram = true;
            break;
        }

        // This would (should) never happen
        default: {
            cout << "what?" << endl;
            break;
        }
        }
    } while (!endProgram);

    cout << "See you soon." << endl;
    return 0;
}
