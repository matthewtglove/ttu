/*
    Author: Matthew Love
    Date: 2023-09-08, Fri
    Purpose: Program will quiz user with 10 questions to determine what type of donut they are
*/
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class Donut
{
public:
    int points;
    string type;
    Donut(string donutType)
    {
        points = 0;
        type = donutType;
    }
};

int main()
{
    // string donutType[] = {"Glazed", "Chocolate-Covered", "Cream Filled", "Peanut Butter and Jelly", "Blueberry", "Sprinkle", ""};
    // Donut glazed("Glazed"), chocolate, cream, pbj, blueberry, sprinkle;
    Donut donuts[] = {
        Donut("Glazed"),
        Donut("Chocolate-Covered"),
        Donut("Cream Filled"),
        Donut("Peanut Butter and Jelly"),
        Donut("Blueberry"),
        Donut("Sprinke")};
    char response;

    donuts[0];

    string indent = "    ";

    bool playAgain = true;

    // TODO:
    // - Debug max expecting expression
    // - Fix answering with multiple words (spaces) causing multiple entries
    // - Get rid of warning
    // - Anything else?

    while (playAgain)
    {
        cout << endl;
        cout << setw(80) << setfill('-') << "" << endl;
        cout << setw(80) << setfill('-') << "" << endl;
        cout << setw(44) << setfill(' ') << "WELCOME!" << endl;
        cout << setw(74) << setfill(' ') << "ANSWER THE FOLLOWING QUESTIONS TO FIND OUT WHAT TYPE OF DONUT YOU ARE" << endl;
        cout << setw(80) << setfill('-') << "" << endl;

        int questionIndex = 1;
        playAgain = false;
        glazed.points = chocolate.points = cream.points = pbj.points = blueberry.points = sprinkle.points = 0;

        while (questionIndex <= 10)
        {
            bool validInput = false;
            bool warning = false;
            string warningReponse = "";

            while (!validInput)
            {
                cout << endl;

                if (warning)
                {
                    cout << warningReponse << endl;
                }

                cout << questionIndex << ". ";

                switch (questionIndex)
                {
                case 1:
                {
                    cout << "What is your favorite color?\n\n";

                    cout << indent << "a. Pink\n";
                    cout << indent << "b. Green\n";
                    cout << indent << "c. Yellow\n";
                    cout << indent << "d. Red\n";
                    cout << indent << "e. Blue\n";
                    cout << indent << "f. ALL OF THEM\n";
                    cout << endl;

                    break;
                }
                case 2:
                {
                    cout << "What is your favorite genre of music?\n\n";

                    cout << indent << "a. Classical\n";
                    cout << indent << "b. Country\n";
                    cout << indent << "c. Rock-n-Roll\n";
                    cout << indent << "d. Rap\n";
                    cout << indent << "e. Blues\n";
                    cout << indent << "f. Pop\n";
                    cout << endl;

                    break;
                }
                case 3:
                {
                    cout << "What do you dislike most about Tech?\n\n";

                    cout << indent << "a. Construction\n";
                    cout << indent << "b. Parking\n";
                    cout << indent << "c. 8am Classes\n";
                    cout << indent << "d. The Cafeteria Food\n";
                    cout << indent << "e. Nothing, I love Tech\n";
                    cout << indent << "f. Deadlines\n";
                    cout << endl;

                    break;
                }
                case 4:
                {
                    cout << "What time of day do you prefer classes\n\n";

                    cout << indent << "a. Afternoon\n";
                    cout << indent << "b. Night Classes\n";
                    cout << indent << "c. Mid-Day\n";
                    cout << indent << "d. Morning\n";
                    cout << indent << "e. Any Time\n";
                    cout << indent << "f. Online\n";
                    cout << endl;

                    break;
                }
                case 5:
                {
                    cout << "What is your preferred desktop operating system?\n\n";

                    cout << indent << "a. Windows\n";
                    cout << indent << "b. ChromeOS\n";
                    cout << indent << "c. MacOS\n";
                    cout << indent << "d. Linux\n";
                    cout << indent << "e. I work well in any of them\n";
                    cout << indent << "f. What's an operating system?\n";
                    cout << endl;

                    break;
                }
                case 6:
                {
                    cout << "What is your preferred browser?\n\n";

                    cout << indent << "a. Edge\n";
                    cout << indent << "b. Chrome\n";
                    cout << indent << "c. Safari\n";
                    cout << indent << "d. DuckDuckGo and Tor\n";
                    cout << indent << "e. Brave / FireFox\n";
                    cout << indent << "f. Is that how get to internet?\n";
                    cout << endl;

                    break;
                }
                case 7:
                {
                    cout << "Which Star Wars character is the best?\n\n";

                    cout << indent << "a. Luke Skywalker\n";
                    cout << indent << "b. Han Solo\n";
                    cout << indent << "c. Princess Leia\n";
                    cout << indent << "d. Boba Fett\n";
                    cout << indent << "e. Yoda\n";
                    cout << indent << "f. Baby Yoda\n";
                    cout << endl;

                    break;
                }
                case 8:
                {
                    cout << "Which historical US President are you most alike?\n\n";

                    cout << indent << "a. George Washington\n";
                    cout << indent << "b. Abraham Lincoln\n";
                    cout << indent << "c. John F. Kennedy\n";
                    cout << indent << "d. Franklin D. Roosevelt\n";
                    cout << indent << "e. Teddy Roosevelt\n";
                    cout << indent << "f. Myself when I become president\n";
                    cout << endl;

                    break;
                }
                case 9:
                {
                    cout << "What's your favorite soda/pop/coke?\n\n";

                    cout << indent << "a. Coca-Cola / Pepsi\n";
                    cout << indent << "b. Dr. Pepper\n";
                    cout << indent << "c. Sprite\n";
                    cout << indent << "d. Root Beer\n";
                    cout << indent << "e. Blue Berry Fanta\n";
                    cout << indent << "f. Diet Mountain Dew\n";
                    cout << endl;

                    break;
                }
                case 10:
                {
                    cout << "Who makes the best donuts?\n\n";

                    cout << indent << "a. Ralph's\n";
                    cout << indent << "b. Big O Donuts\n";
                    cout << indent << "c. Walmart\n";
                    cout << indent << "d. Dunkin Donuts\n";
                    cout << indent << "e. Coffee shops\n";
                    cout << indent << "f. Krispy Kreme\n";
                    cout << endl;

                    break;
                }
                }

                cout << "Your answer: ";

                string input;
                cin >> input;
                response = tolower(input[0]);

                if (response == 'a' || response == 'b' || response == 'c' || response == 'd' || response == 'e' || response == 'f')
                {
                    validInput = true;
                }
                else
                {
                    warning = true;
                    warningReponse = "NOTE: Please enter a, b, c, d, e, or f";
                }
            }

            switch (tolower(response))
            {
            case 'a':
                glazed.points++;
                break;
            case 'b':
                chocolate.points++;
                break;
            case 'c':
                cream.points++;
                break;
            case 'd':
                pbj.points++;
                break;
            case 'e':
                blueberry.points++;
                break;
            case 'f':
                sprinkle.points++;
                break;
            }

            questionIndex++;
        }

        // map<int, int> donutMap;

        // donutMap[0] = glazed.points;
        // donutMap[1] = chocolate.points;
        // donutMap[2] = cream.points;
        // donutMap[3] = pbj.points;
        // donutMap[4] = blueberry.points;
        // donutMap[5] = sprinkle.points;

        // array findMaxDonutPoint[] = {donutPoints};

        for (int i = 1; i < 6; ++i)
        {
            if (donutPoints[0] < donutPoints[i])
            {
                donutPoints[0] = donutPoints[i];
            }
        }

        // cout << findMaxDonutPoint[1] << endl;

        int maxPoints = donutPoints[0];

        // Fix this

        // donutPoints[0] = glazed.points;
        // donutPoints[1] = chocolate.points;
        // donutPoints[2] = cream.points;
        // donutPoints[3] = pbj.points;
        // donutPoints[4] = blueberry.points;
        // donutPoints[5] = sprinkle.points;

        int maxCount;
        int iMax;

        string donutTypeResponse;

        for (int i; i < 6; i++)
        {
            if (donutPoints[i] == maxPoints)
            {
                maxCount++;
            }
        }

        cout << endl;
        cout << setw(80) << setfill('-') << "" << endl;
        cout << setw(50) << setfill(' ') << "HERE ARE YOUR RESULTS" << endl;
        cout << setw(80) << setfill('-') << "" << endl;

        cout << endl;
        for (int i; i < 6; i++)
        {
            cout << indent << donutType[i] << ": " << donutPoints[i] << "\n";
        }
        // cout << indent << ": " << glazed.points << "\n";
        // cout << indent << ": " << chocolate.points << "\n";
        // cout << indent << ": " << cream.points << "\n";
        // cout << indent << ": " << pbj.points << "\n";
        // cout << indent << ": " << blueberry.points << "\n";
        // cout << indent << ": " << sprinkle.points << "\n";
        cout << endl;

        if (!(maxCount == 1))
        {
            donutType[6] = "Sorry, I don't know what type of donut you are. I think you're confused.";
            donutTypeResponse = donutType[6];
        }
        else
        {
            for (int i; i < 6; i++)
            {
                if (donutPoints[i] == maxPoints)
                {
                    donutType[i];
                }
            }
        }

        cout << setw(80) << setfill('-') << "" << endl;

        // cout << "You are a " << donutType << " donut!" << endl; --- This whole response should change

        cout << setw(80) << setfill('-') << "" << endl;
        cout << setw(80) << setfill('-') << "" << endl;
        cout << endl;
    }

    bool validInput = false;
    while (!validInput)
    {
        cout << "Would you like to play again? (y/n) ";

        string input;
        cin >> input;
        char playAgainResponse = tolower(input[0]);

        if (playAgainResponse == 'y')
        {
            validInput = true;
            playAgain = true;
        }
        else if (playAgainResponse == 'n')
        {
            validInput = true;
            playAgain = false;
        }
    }
    return 0;
}
