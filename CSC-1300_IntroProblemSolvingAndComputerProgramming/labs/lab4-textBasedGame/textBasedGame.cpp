/*
    Title: Lab4Gold_ctsmith49+mtlove42
    Author: Cody Smith and Matthew Love
    Date: 2023-09-19, Tue
    Purpose: Creating a text-based video game
*/

/*
Idea: A text-based game where you have to choose the right insule reponse against a pirate. Aka "A roast battle against pirates"

*/

/*
TODO:
- Intro
- Add indents to strings
*/

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
    bool firstPirateDefeated = false;
    bool secondPirateDefeated = false;
    bool thirdPirateDefeated = false;

    int userResponse;
    int correctResponse;

    // Pirate 1
    {
        cout << "Pirate 1: ";
        cout << "YARRR! I've come to defeat you - through the utilization of insults.\n";
        cout << "Yer ship be slower than a snail with a limp!\n"
             << endl;

        cout << "1. But at least it not be slow as yer ship.\n";
        cout << "2. Aye? A snail with a limp?\n";
        cout << "3. Aye, but it's still faster than your wit!\n";

        correctResponse = 3;
        userResponse = 0;

        do
        {
            cout << "Choose response (1-3): ";
            cin >> userResponse;
            cout << endl;
        } while (userResponse < 1 || userResponse > 3);

        if (userResponse != correctResponse)
        {
            cout << "ARRRRR, Pirate 1 swings deftly swings his blade and coerses you off the ship!\n";
            cout << "You were defeated by Pirate 1!" << endl;
            firstPirateDefeated = false;
        }
        else
        {
            cout << "YARR! You deal a hard blow, but Pirate 1 stands strong." << endl;
            cout << "Pirate 1: ";
            cout << "Ye fight like a dairy farmer!" << endl
                 << endl;

            cout << "1. And ye smell like a stable, mate!\n";
            cout << "2. At least I not be a dairy farmer, unlike ye.\n";
            cout << "3. At least I'm not lactose intolerant.\n";

            correctResponse = 1;
            userResponse = 0;

            do
            {
                cout << "Choose response (1-3): ";
                cin >> userResponse;
                cout << endl;
            } while (userResponse < 1 || userResponse > 3);

            if (userResponse != correctResponse)
            {
                cout << "ARRRRR, Pirate 1 swings deftly swings his blade and coerses you off the ship!\n";
                cout << "You were defeated by Pirate 1!" << endl;
                firstPirateDefeated = false;
            }
            else
            {
                cout << "YARRRR! You deal a powerful blow, knocking Pirate 1 off the ship!\n";
                cout << "You defeated Pirate 1!" << endl;
                firstPirateDefeated = true;
            }
        }
    }
}