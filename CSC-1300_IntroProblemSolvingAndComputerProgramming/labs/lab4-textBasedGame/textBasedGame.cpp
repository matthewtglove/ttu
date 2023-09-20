/*
    Title: Lab4Gold_ctsmith49+mtlove42
    Author: Coby Smith and Matthew Love
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
- Use .ctype
- Username code at beginning
*/

#include <iostream>
#include <cstring>
#include <cctype>
#include <iomanip>
using namespace std;

int main()
{
    bool firstPirateDefeated = false;
    bool secondPirateDefeated = false;
    bool thirdPirateDefeated = false;

    int userResponse;
    int correctResponse;

    // Intro
    cout << endl;
    cout << setw(80) << setfill('-') << "" << endl;
    cout << setw(80) << setfill('-') << "" << endl;
    cout << "" << endl;
    cout << setw(80) << setfill('-') << "" << endl;

    // Enter username flow

    // Pirate 1
    {
        cout << endl;
        cout << "> Pirate 1 approaches." << endl;

        cout << endl;
        cout << "Pirate 1: ";
        cout << "\"YARRR! I've come to defeat you - through the utilization of insults!\"\n";
        cout << "\"Yer ship be slower than a snail with a limp!\"\n"
             << endl;

        cout << "\t1. But at least it not be slow as yer ship.\n";
        cout << "\t2. Aye? A snail with a limp?\n";
        cout << "\t3. Aye, but it's still faster than your wit!\n";
        cout << endl;

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
            cout << "> ARRRRR, Pirate 1 deftly swings his blade and drives you off the ship!\n";
            cout << "> You were defeated by Pirate 1!" << endl;

            cout << endl;
            cout << setw(80) << setfill('-') << "" << endl;

            firstPirateDefeated = false;
        }
        else
        {
            cout << "> YARR! You deal a hard blow, but Pirate 1 stands strong." << endl
                 << endl;
            cout << "Pirate 1: ";
            cout << "\"Ye fight like a dairy farmer!\"" << endl
                 << endl;

            cout << "\t1. And ye smell like a stable, mate!\n";
            cout << "\t2. At least I not be a dairy farmer, unlike ye.\n";
            cout << "\t3. At least I not lactose intolerant.\n";
            cout << endl;

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
                cout << "> ARRRRR, Pirate 1 deftly swings his blade and drives you off the ship!\n";
                cout << "> You were defeated by Pirate 1!" << endl;

                cout << endl;
                cout << setw(80) << setfill('-') << "" << endl;

                firstPirateDefeated = false;
            }
            else
            {
                cout << "> YARRRR! You deal a powerful blow, knocking Pirate 1 off the ship!\n";
                cout << "> You defeated Pirate 1!" << endl;

                cout << endl;
                cout << setw(80) << setfill('-') << "" << endl;

                firstPirateDefeated = true;
            }
        }
    }

    // Pirate 2
    {
        cout << endl;
        cout << "> Pirate 2 approaches." << endl;

        cout << endl;
        cout << "Pirate 2: ";
        cout << "\"YARRRR! Say yer last words!\"\n";
        cout << "\"Ye be lookin' like a landlubber who's lost at sea!\"\n"
             << endl;

        cout << "\t1. Least I be not a sailor lost at sea!\n";
        cout << "\t2. Well, at least I'm not as lost as your treasure map!\n";
        cout << "\t3. Yet ye be the one who wrecked their ship against the land.\n";
        cout << endl;

        correctResponse = 2;
        userResponse = 0;

        do
        {
            cout << "Choose response (1-3): ";
            cin >> userResponse;
            cout << endl;
        } while (userResponse < 1 || userResponse > 3);

        if (userResponse != correctResponse)
        {
            cout << "> ARRRRRR, you fail to block Pirate 2's attacks and fall to your demise.\n";
            cout << "> You were defeated by Pirate 2!" << endl;

            cout << endl;
            cout << setw(80) << setfill('-') << "" << endl;

            secondPirateDefeated = false;
        }
        else
        {
            cout << "> YARRRR! Pirate 2 is clearly insulted but stands firm." << endl
                 << endl;
            cout << "Pirate 2: ";
            cout << "\"Ye be more clueless than a ship without a captain!\"" << endl
                 << endl;

            cout << "\t1. Ye be more clueless than a captain without a ship!\n";
            cout << "\t2. Aye, but ye be gluten free!\n";                      // Yeah I ran out of ideas
            cout << "\t3. Better clueless than heartless like ye, me mate.\n"; // Not very strong comeback
            cout << endl;

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
                cout << "> ARRRRRR, you fail to block Pirate 2's attacks and fall to your demise.\n";
                cout << "> You were defeated by Pirate 2!" << endl;

                cout << endl;
                cout << setw(80) << setfill('-') << "" << endl;

                secondPirateDefeated = false;
            }
            else
            {
                cout << "> YARRRR! Pirate 2 is caught off guard and you throw him off the ship!\n";
                cout << "> You defeated Pirate 2!" << endl;

                cout << endl;
                cout << setw(80) << setfill('-') << "" << endl;

                secondPirateDefeated = true;
            }
        }
    }

    // Pirate 3
    {
        cout << endl;
        cout << "> Pirate 3 approaches." << endl;

        cout << endl;
        cout << "Pirate 3: ";
        cout << "\"YARRRR! This is the end for ye!\"\n";
        cout << "\"Ye call that a sword? It's more like a toothpick!\"\n"
             << endl;

        cout << "\t1. ARR! That must make your sword a feather!\n";
        cout << "\t2. Aye, but it'll still be sharp enough to deal with the likes of ye!\n";
        cout << "\t3. Yet you be cuttin' less with yer cutlass!\n";
        cout << endl;

        correctResponse = 2;
        userResponse = 0;

        do
        {
            cout << "Choose response (1-3): ";
            cin >> userResponse;
            cout << endl;
        } while (userResponse < 1 || userResponse > 3);

        if (userResponse != correctResponse)
        {
            cout << "> ARRRRRRRRR, Pirate 3 disarms you and kicks you overboard!\n";
            cout << "> You were defeated by Pirate 3!" << endl;

            cout << endl;
            cout << setw(80) << setfill('-') << "" << endl;

            thirdPirateDefeated = false;
        }
        else
        {
            cout << "> YARRRRRRR! Pirate 3 is weakened but persists in his attaacks." << endl
                 << endl;
            ;
            cout << "Pirate 3: ";
            cout << "\"Yer aim be so bad, ye couldn't hit water if ye fell out of a boat!\"" << endl
                 << endl;

            cout << "\t1. Aye, but I can hit the broadside of yer ego!\n"; // Not very strong comeback
            cout << "\t2. Aye, but when you jump on land it's still a belly flop.\n";
            cout << "\t3. But ye be the one who will fall in the water!\n";
            cout << endl;

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
                cout << "> ARRRRRRRRR, Pirate 3 disarms you and kicks you overboard!\n";
                cout << "> You were defeated by Pirate 3!" << endl;

                cout << endl;
                cout << setw(80) << setfill('-') << "" << endl;

                thirdPirateDefeated = false;
            }
            else
            {
                cout << "> YARRRRRRRR! You parry Pirate 3, and drive him off the ship!\n";
                cout << "> You defeated Pirate 3!" << endl;

                cout << endl;
                cout << setw(80) << setfill('-') << "" << endl;

                thirdPirateDefeated = true;
            }
        }
    }

    // Final score display with name

    cout << endl;
    cout << setw(80) << setfill('-') << "" << endl;
    cout << setw(80) << setfill('-') << "" << endl;

    return 0;
}