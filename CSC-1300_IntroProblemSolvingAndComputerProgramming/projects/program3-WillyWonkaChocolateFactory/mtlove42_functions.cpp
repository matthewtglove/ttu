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
        } while (!successfulConversion);

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

    cout << "What type of candy would you like to add?\n";
    cout << "\t1.\tWonka Bar\n";
    cout << "\t2.\tEverlasting Gobstoppers\n";
    cout << "\t3.\tHair Toffee\n";
    cout << endl;
    cout << "Choose 1-3: ";

    cout << fixed << setprecision(0);

    candyType[countCandies] = requireIntInput(1, 3, "What in the Wonka World?! That's not a type of candy.");

    cout << "What is the flavor of this new candy?" << endl;
    cout << "FLAVOR: ";
    getline(cin, candyFlavor[countCandies]);

    cout << "What is the cost of materials to make this new candy?" << endl;
    cout << "COST OF MATERIALS: ";
    costMaterials[countCandies] = requireDoubleInput(0, 5000000, "Hold your horses, that's not right.");

    cout << "How many Oompa Loompas does it take to create this candy?" << endl;
    cout << "NUMBER OF OOMPA LOOMPAS: ";
    numberOompas[countCandies] = requireIntInput(0, 100000, "Are you eating as much as an elephant eats?");

    askingPrice[countCandies] = calculatePrice(countCandies, costMaterials, numberOompas);

    cout << endl;
    cout << "A new candy has been added to the inventory!" << endl;
    cout << endl;
    countCandies++;
}

void calculateTotals(int candyTableType, int countCandies, int candyType[], string candyTypeName[], string candyFlavor[], float costMaterials[], int numberOompas[], float askingPrice[])
{

    bool returnAllCandy = (candyTableType == 4);

    double totalCost = 0;
    double totalPrice = 0;

    // Formatting
    int widthColumnType = 24;
    int widthColumnFlavor = 24;
    int widthColumnCost = 12;
    int widthColumnOompas = 16;
    int widthColumnPrice = 12;
    int widthLine = widthColumnType + widthColumnFlavor + widthColumnCost + widthColumnOompas + widthColumnPrice;

    cout << fixed;
    cout << left << setw(widthColumnType) << "TYPE";
    cout << right << setw(widthColumnFlavor) << "FLAVOR";
    cout << right << setw(widthColumnCost) << setprecision(2) << "COST";
    cout << right << setw(widthColumnOompas) << setprecision(0) << "NUM-OOPMAS";
    cout << right << setw(widthColumnPrice) << setprecision(2) << "PRICE" << endl;
    cout << setw(widthLine) << setfill('-') << "" << endl;
    cout << setfill(' ');

    for (int i = 0; i < countCandies; i++)
    {
        if (candyType[i] == candyTableType || returnAllCandy)
        {
            cout << left << setw(widthColumnType) << candyTypeName[candyType[i] - 1];
            cout << right << setw(widthColumnFlavor) << candyFlavor[i];
            cout << right << setw(widthColumnCost) << setprecision(2) << costMaterials[i];
            cout << right << setw(widthColumnOompas) << setprecision(0) << numberOompas[i];
            cout << right << setw(widthColumnPrice) << setprecision(2) << askingPrice[i] << endl;
            totalCost += costMaterials[i];
            totalPrice += askingPrice[i];
        }
    }

    cout << setw(widthLine) << setfill('-') << "" << endl;
    cout << setfill(' ');
    cout << endl;
    cout << left << setw(widthColumnType) << "TOTALS:";
    cout << right << setw(widthColumnFlavor) << "$";
    cout << right << setw(widthColumnCost) << setprecision(2) << totalCost;
    cout << right << setw(widthColumnOompas) << setprecision(0) << "$";
    cout << right << setw(widthColumnPrice) << setprecision(2) << totalPrice << endl;
    cout << endl;
}

float calculatePrice(int countCandies, float costMaterials[], int numberOompas[])
{
    return numberOompas[countCandies] * COST_OOMPAS + costMaterials[countCandies];
}

void calculateProfit(int candyTableType, int countCandies, int candyType[], string candyTypeName[], float costMaterials[], float askingPrice[])
{
    bool returnAllCandy = (candyTableType == 4);

    double totalProfit = 0;

    // Formatting
    int widthColumnType = 30;
    int widthColumnProfit = 12;
    int widthLine = widthColumnType + widthColumnProfit;
    cout << fixed;
    cout << left << setw(widthColumnType) << "CANDY TYPE";
    cout << right << setw(widthColumnProfit) << "PROFIT" << endl;
    cout << setw(widthLine) << setfill('-') << "" << endl;
    cout << setfill(' ');

    for (int i = 0; i < countCandies; i++)
    {
        double candyProfit = askingPrice[i] - costMaterials[i];

        if (candyType[i] == candyTableType || returnAllCandy)
        {
            cout << left << setw(widthColumnType) << candyTypeName[candyType[i] - 1];
            cout << right << setw(widthColumnProfit) << setprecision(2) << candyProfit << endl;
            totalProfit += candyProfit;
        }
    }

    cout << setw(widthLine) << setfill('-') << "" << endl;
    cout << setfill(' ');
    cout << endl;
    cout << left << setw(widthColumnType - 1) << "TOTAL PROFIT:";
    cout << right << setw(1) << "$";
    cout << right << setw(widthColumnProfit) << setprecision(2) << totalProfit << endl;
    cout << endl;
}

float getMaxPrice(int countCandies, float askingPrice[], int &iMaxPrice)
{
    int maxPrice = askingPrice[0];
    for (int i = 0; i < countCandies; i++)
    {
        if (askingPrice[i] > maxPrice)
        {
            maxPrice = askingPrice[i];
            iMaxPrice = i;
        }
    }
    return maxPrice;
}
