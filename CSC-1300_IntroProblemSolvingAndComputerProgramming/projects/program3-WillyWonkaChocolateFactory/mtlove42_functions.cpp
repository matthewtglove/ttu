#include "mtlove42_prog3.h"

int requireIntInput(int minRange = INT_MIN, int maxRange = INT_MAX, string invalidInputMessage = "Invalid input.")
{
    int userInput = 0;
    bool validRange = false;
    do
    {
        int convertedInput;
        bool successfulConversion = false;
        do
        {
            try
            {
                string input;
                getline(cin, input);
                convertedInput = stoi(input);
                successfulConversion = true;
            }
            catch (...)
            {
                cout << invalidInputMessage << " Please enter an integer " << minRange << "-" << maxRange << endl;
            };
        } while (!(successfulConversion));

        userInput = convertedInput;

        validRange = (userInput >= minRange && userInput <= maxRange);
        if (!validRange)
        {
            cout << invalidInputMessage << " Please enter " << minRange << "-" << maxRange << endl;
        }
    } while (!validRange);

    return userInput;
}

int getMenuOption()
{
    cout << "Wonka's Candy Management System: \n";
    cout << "\t1.\tAdd a piece of candy to inventory\n";
    cout << "\t2.\tCalculate totals for candy\n";
    cout << "\t3.\tCalculate profits for candy\n";
    cout << "\t4.\tPrint candy with max price\n";
    cout << "\t5.\tQuit the program\n";

    cout << endl;
    cout << "Choose 1-5: ";

    int userChoice = requireIntInput(1, 5, "Whoops, that's not going to work.");
    return userChoice;
}

void addCandy(int &countCandies, int candyType[], string candyFlavor[], float costMaterials[], int numberOompas[], float askingPrice[]);
void calculateTotals(int candyTableType, int countCandies, int candyType[], string candyFlavor[], float costMaterials[], int numberOompas[], float askingPrice[]);
float calculatePrice(float costMaterials[], int numberOompas[]);
/*
The formula used for this function is:
Asking price = number of Oompa Loompas * cost per Oompa Loompa + cost of materials
*/
void calculateProfit(int candyTableType, int countCandies, int candyType[], float costMaterials[], float askingPrice);
// Profit = asking price - cost of materials
float getMaxPrice(int countCandies, float askingPrice[], int &maxPriceCandy);