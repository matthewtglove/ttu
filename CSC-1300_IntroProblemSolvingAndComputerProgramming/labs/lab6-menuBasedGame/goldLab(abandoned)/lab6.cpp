/*
    Title: lab6.cpp
    Author: Matthew Love - mtlove42
    Date: 2023-10-03, Tue
    Purpose: Create a menu-based game
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/*
TODO:
- what to do
*/

// Rooms
void roomEntrance();
void roomFinalDoor();
void roomUpstairs();
void roomConcertHall();
void roomDiningArea();

// Locations / Objects

// Puzzles
void puzzleMath();
void puzzleMusic();
void puzzleFood();

// ASCII Text
void asciiTest();

int main()
{
    // Global variables to track solved state of puzzles
    bool puzzle1Solved = false;
    bool puzzle2Solved = false;
    bool puzzle3Solved = false;

    asciiTest();

    return 0;
}

void asciiTest()
{
    string thisIsATest[8] = {
        "$$$$$$$$\\ $$\\       $$\\                 $$\\                                   $$\\                           $$\\     \n",
        "\\__$$  __|$$ |      \\__|                \\__|                                  $$ |                          $$ |    \n",
        "   $$ |   $$$$$$$\\  $$\\  $$$$$$$\\       $$\\  $$$$$$$\\        $$$$$$\\        $$$$$$\\    $$$$$$\\   $$$$$$$\\ $$$$$$\\   \n",
        "   $$ |   $$  __$$\\ $$ |$$  _____|      $$ |$$  _____|       \\____$$\\       \\_$$  _|  $$  __$$\\ $$  _____|\\_$$  _|  \n",
        "   $$ |   $$ |  $$ |$$ |\\$$$$$$\\        $$ |\\$$$$$$\\         $$$$$$$ |        $$ |    $$$$$$$$ |\\$$$$$$\\    $$ |    \n",
        "   $$ |   $$ |  $$ |$$ | \\____$$\\       $$ | \\____$$\\       $$  __$$ |        $$ |$$\\ $$   ____| \\____$$\\   $$ |$$\\ \n",
        "   $$ |   $$ |  $$ |$$ |$$$$$$$  |      $$ |$$$$$$$  |      \\$$$$$$$ |        \\$$$$  |\\$$$$$$$\\ $$$$$$$  |  \\$$$$  |\n",
        "   \\__|   \\__|  \\__|\\__|\\_______/       \\__|\\_______/        \\_______|         \\____/  \\_______|\\_______/    \\____/ \n",
    };

    for (int i = 0; i < 8; i++)
    {
        cout << thisIsATest[i];
    }
}
