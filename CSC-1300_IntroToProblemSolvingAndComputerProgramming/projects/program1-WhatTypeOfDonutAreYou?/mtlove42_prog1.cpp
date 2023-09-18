/*
    Author: Matthew Love
    Date: 2023-09-08, Fri
    Purpose: Program will quiz user with 10 questions to determine what type of donut they are
*/
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

// Donut type set up to keep the points and type (donut flavor) values of a donut tied together
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

// Asks the user if they would like to run the program again. Validates response and only accepts a string begining in 'y' or 'n' (not case sensitive)
bool askRunAgain(string prompt = "Would you like to run this program again? (y/n) ")
{
    while (true)
    {
        cout << prompt;

        // Validates user input - reads only the first character they input
        string input;
        getline(cin, input);
        char runAgainResponse = tolower(input[0]);

        if (runAgainResponse == 'y')
        {
            return true;
            break; // Used to exit the while loop
        }
        else if (runAgainResponse == 'n')
        {
            return false;
            break; // Used to exit the while loop
        }
    }
}

int main()
{
    string indent = "    ";

    while (true)
    {
        Donut donuts[] = {
            Donut("Glazed"),
            Donut("Chocolate-Covered"),
            Donut("Cream Filled"),
            Donut("Peanut Butter and Jelly"),
            Donut("Blueberry"),
            Donut("Sprinkle")};
        char response;

        cout << endl;
        cout << setw(80) << setfill('-') << "" << endl;
        cout << setw(80) << setfill('-') << "" << endl;
        cout << setw(44) << setfill(' ') << "WELCOME!" << endl;
        cout << setw(74) << setfill(' ') << "ANSWER THE FOLLOWING QUESTIONS TO FIND OUT WHAT TYPE OF DONUT YOU ARE" << endl;
        cout << setw(80) << setfill('-') << "" << endl;

        int questionIndex = 1;

        while (questionIndex <= 10)
        {
            bool validInput = false;
            bool warning = false;
            string warningReponse = "NOTE: Please enter a, b, c, d, e, or f";

            while (!validInput)
            {
                cout << endl;

                if (warning)
                {
                    cout << warningReponse << endl;
                }

                cout << questionIndex << ". ";

                // switch statement used to walk through question indexes
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
                    cout << indent << "c. Noon\n";
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
                    cout << indent << "d. Tor Onion Browser\n";
                    cout << indent << "e. Brave / FireFox\n";
                    cout << indent << "f. Is that how get to internet?\n";

                    cout << endl;

                    break;
                }
                case 7:
                {
                    cout << "Which Star Wars character is the best?\n\n";

                    cout << indent << "a. Luke Skywalker\n";
                    cout << indent << "b. Darth Vader\n";
                    cout << indent << "c. R2-D2\n";
                    cout << indent << "d. Jar Jar Binks\n";
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
                getline(cin, input);
                response = tolower(input[0]);

                if (response == 'a' || response == 'b' || response == 'c' || response == 'd' || response == 'e' || response == 'f')
                {
                    validInput = true;
                }
                else
                {
                    warning = true;
                }
            }

            // Adds points to a certain donut depending on user's input a-f
            switch (tolower(response))
            {
            case 'a':
                donuts[0].points++;
                break;
            case 'b':
                donuts[1].points++;
                break;
            case 'c':
                donuts[2].points++;
                break;
            case 'd':
                donuts[3].points++;
                break;
            case 'e':
                donuts[4].points++;
                break;
            case 'f':
                donuts[5].points++;
                break;
            }

            questionIndex++;
        }

        // Number of donuts with the max score
        int maxCount = 0;

        // Finding max value
        int sortedDonutsPoints[] = {donuts[0].points, donuts[1].points, donuts[2].points, donuts[3].points, donuts[4].points, donuts[5].points};
        for (int i = 0; i < 6; i++)
        {
            if (sortedDonutsPoints[0] < sortedDonutsPoints[i])
            {
                sortedDonutsPoints[0] = sortedDonutsPoints[i];
            }
        }

        int maxPoints = sortedDonutsPoints[0];

        // Finds the number of donuts with the max score
        for (int i = 0; i < 6; i++)
        {
            if (donuts[i].points == maxPoints)
            {
                maxCount++;
            }
        }

        string donutTypeResult;

        // If there is more than one top donut, then it returns the first statement, else it prints their top donut
        if (!(maxCount == 1))
        {
            donutTypeResult = "Sorry, I don't know what type of donut you are. I think you're confused.";
        }
        else
        {
            for (int i = 0; i < 6; i++)
            {
                if (donuts[i].points == maxPoints)
                {
                    donutTypeResult = "You are a " + donuts[i].type + " donut!";
                }
            }
        }

        cout << endl;
        cout << setw(80) << setfill('-') << "" << endl;
        cout << setw(50) << setfill(' ') << "HERE ARE YOUR RESULTS" << endl;
        cout << setw(80) << setfill('-') << "" << endl;

        cout << endl;
        for (int i = 0; i < 6; i++)
        {
            cout << indent << donuts[i].type << ": " << donuts[i].points << "\n";
        }

        cout << endl;

        cout << setw(80) << setfill('-') << "" << endl;

        cout << donutTypeResult << endl;

        cout << setw(80) << setfill('-') << "" << endl;
        cout << setw(80) << setfill('-') << "" << endl;
        cout << endl;

        // Runs the questions again depending on the boolean value of askRunAgain()
        if (askRunAgain("Would you like to play again? (y/n) "))
        {
            continue;
        }
        else
        {
            break;
        }
    }
    return 0;
}

// *** BELOW IS NOT MY CODE. Credit: Andy Sloane https://gist.github.com/gcr/1075131 ***

/* Spinning donut

int k;
double sin(), cos();
void spinningDonut()
{
    float A = 0, B = 0, i, j, z[1760];
    char b[1760];
    printf("\x1b[2J");
    for (;;)
    {
        memset(b, 32, 1760);
        memset(z, 0, 7040);
        for (j = 0; 6.28 > j; j += 0.03)
        {
            for (i = 0; 6.28 > i; i += 0.0085)
            {
                float sini = sin(i),
                      cosj = cos(j),
                      sinA = sin(A),
                      sinj = sin(j),
                      cosA = cos(A),
                      cosj2 = cosj + 2,
                      mess = 1 / (sini * cosj2 * sinA + sinj * cosA + 5),
                      cosi = cos(i),
                      cosB = cos(B),
                      sinB = sin(B),
                      t = sini * cosj2 * cosA - sinj * sinA;
                int x = 40 + 30 * mess * (cosi * cosj2 * cosB - t * sinB),
                    y = 12 + 15 * mess * (cosi * cosj2 * sinB + t * cosB),
                    o = x + 80 * y,
                    N = 8 * ((sinj * sinA - sini * cosj * cosA) * cosB - sini * cosj * sinA - sinj * cosA - cosi * cosj * sinB);
                if (22 > y && y > 0 && x > 0 && 80 > x && mess > z[o])
                {
                    z[o] = mess;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }
        printf("\x1b[d");
        for (k = 0; 1761 > k; k++)
            putchar(k % 80 ? b[k] : 10);
        A += 0.04;
        B += 0.02;
    }
}

*/