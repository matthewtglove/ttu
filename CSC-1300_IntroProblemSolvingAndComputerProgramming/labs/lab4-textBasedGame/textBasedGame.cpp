/*
    Title: Lab4Gold_ctsmith49+mtlove42
    Author: Coby Smith and Matthew Love
    Date: 2023-09-19, Tue
    Purpose: Creating a text-based video game
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
    int totalDefeated = 0;

    int userResponse;
    int correctResponse;

    string username;

    // Intro
    cout << endl;
    cout << setw(130) << setfill('-') << "" << endl;
    cout << setw(130) << setfill('-') << "" << endl;
    cout << R"(
               ______                                           ______             _             ______       _   _   _      
               | ___ \                                          | ___ \           | |            | ___ \     | | | | | |     
               | |_/ /_   _  ___ ___ __ _ _ __   ___  ___ _ __  | |_/ / __ _ _ __ | |_ ___ _ __  | |_/ / __ _| |_| |_| | ___ 
               | ___ \ | | |/ __/ __/ _` | '_ \ / _ \/ _ \ '__| | ___ \/ _` | '_ \| __/ _ \ '__| | ___ \/ _` | __| __| |/ _ \
               | |_/ / |_| | (_| (_| (_| | | | |  __/  __/ |    | |_/ / (_| | | | | ||  __/ |    | |_/ / (_| | |_| |_| |  __/
               \____/ \__,_|\___\___\__,_|_| |_|\___|\___|_|    \____/ \__,_|_| |_|\__\___|_|    \____/ \__,_|\__|\__|_|\___|
                                                                                                                                )"
         << endl;
    cout << setw(130) << setfill('-') << "" << endl;

    // Gets the users name
    cout << endl;
    cout << "\n\nARRRRR!!! What's ye Name Pirate: ";
    getline(cin, username);
    cout << endl
         << endl;

    // Loops through the given username and gets rid of non alapha characters
    for (int i = 0; username.size() > i; i++)
    {
        if (!isalpha(username.at(i)))
        {
            username.replace(i, 1, "");
            --i;
        }
    }
    cout << endl;
    cout << setw(130) << setfill('-') << "" << endl;

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

        // Loops through till the user gives a valid response
        do
        {
            cout << "Choose response (1-3): ";
            cin >> userResponse;
            cout << endl;
        } while (userResponse < 1 || userResponse > 3);

        // Determines if the user has been defeated or not
        if (userResponse != correctResponse)
        {
            cout << "> ARRRRR, Pirate 1 deftly swings his blade and drives you off the ship!\n";
            cout << "> You were defeated by Pirate 1!" << endl;
            cout << endl;

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

            // Loops through till the user gives a valid response
            do
            {
                cout << "Choose response (1-3): ";
                cin >> userResponse;
                cout << endl;
            } while (userResponse < 1 || userResponse > 3);

            // Determines if the user defeated the pirate
            if (userResponse != correctResponse)
            {
                cout << "> ARRRRR, Pirate 1 deftly swings his blade and drives you off the ship!\n";
                cout << "> You were defeated by Pirate 1!" << endl;
                cout << endl;

                firstPirateDefeated = false;
            }
            else
            {
                cout << "> YARRRR! You deal a powerful blow, knocking Pirate 1 off the ship!\n";
                cout << "> You defeated Pirate 1!" << endl;
                cout << endl;

                firstPirateDefeated = true;
                totalDefeated++;
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

        // Loops through till the user gives a valid response
        do
        {
            cout << "Choose response (1-3): ";
            cin >> userResponse;
            cout << endl;
        } while (userResponse < 1 || userResponse > 3);

        // Determines if the user has been defeated or not
        if (userResponse != correctResponse)
        {
            cout << "> ARRRRRR, you fail to block Pirate 2's attacks and fall to your demise.\n";
            cout << "> You were defeated by Pirate 2!" << endl;
            cout << endl;

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
            cout << "\t2. Aye, but ye be gluten free!\n"; // Yeah I ran out of ideas
            cout << "\t3. Better clueless than heartless like ye, me mate.\n";
            cout << endl;

            correctResponse = 3;
            userResponse = 0;

            // Loops through till the user gives a valid response
            do
            {
                cout << "Choose response (1-3): ";
                cin >> userResponse;
                cout << endl;
            } while (userResponse < 1 || userResponse > 3);

            // Determines if the user defeated the pirate
            if (userResponse != correctResponse)
            {
                cout << "> ARRRRRR, you fail to block Pirate 2's attacks and fall to your demise.\n";
                cout << "> You were defeated by Pirate 2!" << endl;
                cout << endl;

                secondPirateDefeated = false;
            }
            else
            {
                cout << "> YARRRR! Pirate 2 is caught off guard and you throw him off the ship!\n";
                cout << "> You defeated Pirate 2!" << endl;
                cout << endl;

                secondPirateDefeated = true;
                totalDefeated++;
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

        // Loops through till the user gives a valid response
        do
        {
            cout << "Choose response (1-3): ";
            cin >> userResponse;
            cout << endl;
        } while (userResponse < 1 || userResponse > 3);

        // Determines if the user has been defeated or not
        if (userResponse != correctResponse)
        {
            cout << "> ARRRRRRRRR, Pirate 3 disarms you and kicks you overboard!\n";
            cout << "> You were defeated by Pirate 3!" << endl;
            cout << endl;

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

            cout << "\t1. Aye, but I can hit the broadside of yer ego, me mate!\n";
            cout << "\t2. Aye, but when you fall on land the earth trembles.\n";
            cout << "\t3. But ye be the one who will fall in the water!\n";
            cout << endl;

            correctResponse = 1;
            userResponse = 0;

            // Loops through till the user gives a valid response
            do
            {
                cout << "Choose response (1-3): ";
                cin >> userResponse;
                cout << endl;
            } while (userResponse < 1 || userResponse > 3);

            // Determines if the user defeated the pirate
            if (userResponse != correctResponse)
            {
                cout << "> ARRRRRRRRR, Pirate 3 disarms you and kicks you overboard!\n";
                cout << "> You were defeated by Pirate 3!" << endl;
                cout << endl;

                thirdPirateDefeated = false;
            }
            else
            {
                cout << "> YARRRRRRRR! You parry Pirate 3, and drive him off the ship!\n";
                cout << "> You defeated Pirate 3!" << endl;
                cout << endl;

                thirdPirateDefeated = true;
                totalDefeated++;
            }
        }
    }

    cout << setw(130) << setfill('-') << "" << endl;

    // Determines how many pirates were defeated
    if (firstPirateDefeated)
        cout << "Pirate 1 was plundered!\n";
    if (secondPirateDefeated)
        cout << "Pirate 2 kicked the bucket!\n";
    if (thirdPirateDefeated)
        cout << "Pirate 3 visited Davy Jone's Locker!\n";
    cout << endl;

    cout << username << " defeated " << totalDefeated << " out of 3 pirates." << endl;

    cout << endl;
    cout << setw(130) << setfill('-') << "" << endl;
    cout << endl
         << endl;

    // Gives the user a pirate name
    cout << username << "'s new pirate name is:\n";
    cout << setw(130) << setfill('-') << "" << endl;

    if (totalDefeated == 0)
    {
        cout << R"(
                     _____           _ _                                    __   _____ _                          
                    /  ___|         | | |                                  / _| /  ___| |                         
                    \ `--.  ___ __ _| | |_   ___      ____ _  __ _    ___ | |_  \ `--.| |__   __ _ _ __ ___   ___ 
                     `--. \/ __/ _` | | | | | \ \ /\ / / _` |/ _` |  / _ \|  _|  `--. \ '_ \ / _` | '_ ` _ \ / _ \
                    /\__/ / (_| (_| | | | |_| |\ V  V / (_| | (_| | | (_) | |   /\__/ / | | | (_| | | | | | |  __/
                    \____/ \___\__,_|_|_|\__, | \_/\_/ \__,_|\__, |  \___/|_|   \____/|_| |_|\__,_|_| |_| |_|\___|
                                          __/ |               __/ |                                               
                                          |___/               |___/                                                )"
             << endl;
    }
    else if (totalDefeated == 1)
    {
        cout << R"(
                     _           _     _                        __   _                            _     _                 
                    | |         | |   | |                      / _| | |                          | |   (_)                
                    | |    _   _| |__ | |__   ___ _ __    ___ | |_  | |     __ _ _ __ ___   ___  | |    _ _ __   ___  ___ 
                    | |   | | | | '_ \| '_ \ / _ \ '__|  / _ \|  _| | |    / _` | '_ ` _ \ / _ \ | |   | | '_ \ / _ \/ __|
                    | |___| |_| | |_) | |_) |  __/ |    | (_) | |   | |___| (_| | | | | | |  __/ | |___| | | | |  __/\__ \
                    \_____/\__,_|_.__/|_.__/ \___|_|     \___/|_|   \_____/\__,_|_| |_| |_|\___| \_____/_|_| |_|\___||___/
                                                                                                      )"
             << endl;
    }
    else if (totalDefeated == 2)
    {
        cout << R"(
                     _____             _        _         _____       _   _   _                     _   
                    /  __ \           | |      (_)       /  __ \     | | | | | |                   | |  
                    | /  \/ __ _ _ __ | |_ __ _ _ _ __   | /  \/_   _| |_| |_| |__  _ __ ___   __ _| |_ 
                    | |    / _` | '_ \| __/ _` | | '_ \  | |   | | | | __| __| '_ \| '__/ _ \ / _` | __|
                    | \__/\ (_| | |_) | || (_| | | | | | | \__/\ |_| | |_| |_| | | | | | (_) | (_| | |_ 
                    \____/\__,_| .__/ \__\__,_|_|_| |_|  \____/\__,_|\__|\__|_| |_|_|  \___/ \__,_|\__|
                               | |                                                                     
                               |_|                                                                     )"
             << endl;
    }
    else if (totalDefeated == 3)
    {
        cout << R"(
                    ___  ___          _                     __  ___  ___           _                   
                    |  \/  |         | |                   / _| |  \/  |          | |                  
                    | .  . | __ _ ___| |_ ___ _ __    ___ | |_  | .  . | ___   ___| | _____ _ __ _   _ 
                    | |\/| |/ _` / __| __/ _ \ '__|  / _ \|  _| | |\/| |/ _ \ / __| |/ / _ \ '__| | | |
                    | |  | | (_| \__ \ ||  __/ |    | (_) | |   | |  | | (_) | (__|   <  __/ |  | |_| |
                    \_|  |_/\__,_|___/\__\___|_|     \___/|_|   \_|  |_/\___/ \___|_|\_\___|_|   \__, |
                                                                                                  __/ |
                                                                                                  |___/ )"
             << endl;
    }

    cout << setw(130) << setfill('-') << "" << endl;

    return 0;
}