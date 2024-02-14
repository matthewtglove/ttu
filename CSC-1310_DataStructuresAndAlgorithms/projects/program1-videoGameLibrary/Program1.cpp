/*
    Title: Program 1
    Author: Matthew Love
    Date: 2024-02-10, Sat
    Purpose: Creating a user's video game library
*/
#include "VideoGameLibrary.h"

int main()
{
    cout << "Welcome, time to create your Video Game Library. How many video games can your library hold? ";
    int librarySize;
    cin >> librarySize;
    cin.ignore();
    cout << "Creating an empty library of size " << librarySize << "..." << endl;
    VideoGameLibrary *library = new VideoGameLibrary(librarySize);

    bool endProgram = false;
    do
    {
        cout << endl;
        cout << "---- What would you like to do? ----" << endl;
        cout << "1. Load video games from file" << endl;
        cout << "2. Save video games to a file" << endl;
        cout << "3. Add a video game" << endl;
        cout << "4. Remove a video game" << endl;
        cout << "5. Display all video games" << endl;
        cout << "6. Remove ALL video games from this library and end program" << endl;
        cout << "CHOICE: ";

        int menuChoice;
        cin >> menuChoice;
        cin.ignore();
        switch (menuChoice)
        {
        case 1:
            cout << endl;
            cout << "What is the filename you would like to load from?" << endl;
            char inputFilename[1000];
            cin >> inputFilename;
            cin.ignore();

            library->loadVideoGamesFromFile(inputFilename);
            break;

        case 2:
            cout << endl;
            cout << "What is the filename you would like to save to?" << endl;
            char outputFilename[1000];
            cin >> outputFilename;
            cin.ignore();

            library->saveToFile(outputFilename);
            break;

        case 3:
            cout << endl;
            library->addVideoGameToArray();
            break;

        case 4:
            cout << endl;
            library->removeVideoGameFromArray();
            break;

        case 5:
            cout << endl;
            library->displayVideoGames();
            break;

        case 6:
            cout << endl;
            cout << "Data will be lost unless you have already saved it to a file. Are you sure you want to quit? (y/n)" << endl;
            cout << "CONFIRM QUIT? ";
            char userConfirmDelete;
            cin >> userConfirmDelete;
            bool confirmDelete = (userConfirmDelete == 'y');

            if (!confirmDelete)
            {
                break;
            }

            // Moves on to the outside of the while loop
            endProgram = true;
            break;
        }
    } while (!endProgram);

    delete library;
    cout << "Goodbye!" << endl;

    return 0;
}