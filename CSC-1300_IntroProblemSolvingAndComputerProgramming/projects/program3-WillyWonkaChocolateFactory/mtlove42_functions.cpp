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
                // Should fail if user did not input a number
                convertedInput = stoi(input);
                successfulConversion = true;
            }
            catch (...)
            {
                cout << invalidInputMessage << " Please enter an integer " << minRange << " to " << maxRange << endl;
            };
        } while (!(successfulConversion));

        userInput = convertedInput;

        validRange = (userInput >= minRange && userInput <= maxRange);
        if (!validRange)
        {
            cout << invalidInputMessage << " Please enter " << minRange << " to " << maxRange << endl;
        }
    } while (!validRange);

    return userInput;
}

double requireDoubleInput(double minRange = INT_MIN, double maxRange = INT_MAX, string invalidInputMessage = "Invalid input.")
{
    double userInput = 0;
    bool validRange = false;
    do
    {
        double convertedInput;
        bool successfulConversion = false;
        do
        {
            try
            {
                string input;
                getline(cin, input);
                // Should fail if user did not input a number
                convertedInput = stod(input);
                successfulConversion = true;
            }
            catch (...)
            {
                cout << invalidInputMessage << " Please enter a number " << minRange << " to " << maxRange << endl;
            };
        } while (!(successfulConversion));

        userInput = convertedInput;

        validRange = (userInput >= minRange && userInput <= maxRange);
        if (!validRange)
        {
            cout << invalidInputMessage << " Please enter " << minRange << " to " << maxRange << endl;
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
    cout << "CHOOSE 1-5: ";

    int userChoice = requireIntInput(1, 5, "Whoops, that's not going to work.");
    return userChoice;
}

void addCandy(int &countCandies, int candyType[], string candyFlavor[], float costMaterials[], int numberOompas[], float askingPrice[])
{
    if (countCandies >= 50)
    {
        cout << "Error: Candy capactiy of 50 has been reached." << endl;
        return;
    }

    // The current number of candies is equal to the index of the new candy
    int iNewCandy = countCandies;

    cout << "What type of candy would you like to add?\n";
    cout << "\t1.\tWonka Bar\n";
    cout << "\t2.\tEverlasting Gobstoppers\n";
    cout << "\t3.\tHair Toffee\n";
    cout << endl;
    cout << "Choose 1-3: ";

    candyType[iNewCandy] = requireIntInput(1, 3, "What in the Wonka World?! That's not a type of candy.");

    cout << "What is the flavor of this new candy?" << endl;
    cout << "FLAVOR: ";
    getline(cin, candyFlavor[iNewCandy]);

    cout << "What is the cost of materials to make this new candy?" << endl;
    cout << "COST OF MATERIALS: ";
    costMaterials[iNewCandy] = requireDoubleInput(0, 500000, "Hold your horses, that's not right.");

    cout << "How many Oompa Loompas does it take to create this candy?" << endl;
    cout << "NUMBER OF OOMPA LOOMPAS: ";
    numberOompas[iNewCandy] = requireIntInput(0, 10000, "Are you eating as much as an elephant eats?");

    // TODO: Calculate Price and add to askingPrice

    cout << "A new candy has been added to the inventory!" << endl;
    countCandies++;
}
void calculateTotals(int candyTableType, int countCandies, int candyType[], string candyFlavor[], float costMaterials[], int numberOompas[], float askingPrice[]);
float calculatePrice(float costMaterials[], int numberOompas[]);
/*
The formula used for this function is:
Asking price = number of Oompa Loompas * cost per Oompa Loompa + cost of materials
*/
void calculateProfit(int candyTableType, int countCandies, int candyType[], float costMaterials[], float askingPrice);
// Profit = asking price - cost of materials
float getMaxPrice(int countCandies, float askingPrice[], int &maxPriceCandy);