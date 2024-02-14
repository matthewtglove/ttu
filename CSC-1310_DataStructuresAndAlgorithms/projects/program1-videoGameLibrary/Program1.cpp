/*
    Title: Program 1
    Author: Matthew Love
    Date: 2024-02-10, Sat
    Purpose: Handling a user's video game library
*/
#include "VideoGameLibrary.h"

int main()
{
    // TEST
    VideoGameLibrary *library = new VideoGameLibrary(50);
    // library->loadVideoGamesFromFile("three_games.txt");
    library->addVideoGameToArray();

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    library->displayVideoGameTitles();
    library->displayVideoGames();
    library->saveToFile("COOLTESTFILE.txt");

    return 0;
}