/*
    Title: lab7.cpp
    Author: Matthew Love
    Date: 2024-03-20, Wed
    Purpose: Using a queue because that's cool 👍
*/

#include "queue.h"

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

        int menuChoice;
        cout << "CHOICE: ";
        cin >> menuChoice;
        cin.ignore();
        switch (menuChoice) {
        case 1: {
            cout << endl;
            cout << "What's your name?" << endl;
            string name;
            getline(cin, name);

            cout << "Do you have an InstantPass holder? (type 1 for yes)" << endl;
            int hasInstantPass;
            cin >> hasInstantPass;
            cin.ignore();

            if (hasInstantPass == 1) {
                instantPass.endqueue(name);
                break;
            }
            regularPass.endqueue(name);
            break;
        }

        case 2: {
            cout << endl;
            if (!instantPass.isEmpty()) {
                instantPass.dequeue();
                cout << "An InstantPass rider was boarded onto the ride." << endl;
                break;
            }
            if (!regularPass.isEmpty()) {
                regularPass.dequeue();
                cout << "A regular pass rider was boarded onto the ride." << endl;
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

        default: {
            cout << "what?" << endl;
            break;
        }
        }
    } while (!endProgram);

    cout << "See you soon." << endl;
    return 0;
}
