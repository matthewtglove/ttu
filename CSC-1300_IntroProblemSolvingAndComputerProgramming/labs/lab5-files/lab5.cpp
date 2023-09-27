/*
    Title: lab5.cpp
    Author: Matthew Love
    Date: 2023-09-26, Tue
    Purpose: Learn how to create a program that receives input and writes it to a file
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/*
TODO:
- Following assignment sheet, determine output (to user and file) after user has selected menu choice
*/

int main()
{
    // Food item prices
    const double pizzaPirce = 20;
    const double pizzaToppingPrice = 2;
    const double burgerPrice = 2;
    const double sandwichPrice = 2;

    // Food and cost totals
    int totalPizzaCount = 0;
    int totalPizzaToppingsCount = 0;
    int totalBurgerCount = 0;
    int totalSandwichCount = 0;

    cout << setw(80) << setfill('-') << "" << endl;
    cout << setw(80) << setfill('-') << "" << endl;
    cout << "Welcome to The Cauldron Restaurant!" << endl;
    cout << setw(80) << setfill('-') << "" << endl;

    int orderChoice = 0;
    while (orderChoice != 0)
    {
        cout << "Please choose one of the following options:\n";
        cout << "\t 1 - Pizza\n";
        cout << "\t 2 - Burger\n";
        cout << "\t 3 - Sandwich\n";
        cout << "\nEnter 0 if you are done orderering\n";

        // Validate user input
        bool validOrderChoice = false;
        do
        {
            cout << "CHOICE: ";
            cin >> orderChoice;

            if (orderChoice >= 0 && orderChoice <= 3)
            {
                validOrderChoice = true;
            }
            else
            {
                cout << "Whoops! That's not a valid input. Please enter a number 1-4." << endl;
            }
        } while (!validOrderChoice);

        switch (orderChoice)
        {
        // Pizza
        case 1:
        {

            break;
        }

        // Burger
        case 2:
        {
            int burgerCount = 0;
            cout << "How many burgers do you want to order? ";
            do
            {
                cin >> burgerCount;

                if (burgerCount >= 0)
                {
                    validOrderChoice = true;
                }
                else
                {
                    cout << "Whoops! That's not a valid input. Please enter a number 1-4." << endl;
                }
            } while (!validOrderChoice);

            // cin >> orderCount;
            break;
        }

        // Sandwich
        case 3:
        {
            break;
        }
        }

        return 0;
    }
}