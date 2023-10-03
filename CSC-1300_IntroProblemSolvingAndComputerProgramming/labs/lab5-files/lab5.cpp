/*
    Title: lab5.cpp
    Author: Matthew Love
    Date: 2023-09-26, Tue
    Purpose: Learn how to create a program that receives input and writes it to a file
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    // Food and cost totals
    int totalPizzaCount = 0;
    int totalPizzaToppingsCount = 0;
    int totalBurgerCount = 0;
    int totalSandwichCount = 0;

    // Food item prices
    const double pizzaPrice = 20.00;
    const double pizzaToppingPrice = 2.00;
    const double burgerPrice = 15.00;
    const double sandwichPrice = 10.00;

    // Discounts off first item
    const double pizzaDiscountPercenage = 0.20;
    const double burgerDiscountPercenage = 0.15;
    const double sandwichDiscountPercenage = 0.10;

    // Running total that is output
    double updatedTotalPrice = 0.00;

    double totalPizzaPrice = 0;
    double totalBurgerPrice = 0;
    double totalSandwichPrice = 0;

    cout << setw(80) << setfill('-') << "" << endl;
    cout << setw(80) << setfill('-') << "" << endl;
    cout << "Welcome to The Cauldron Restaurant!" << endl;
    cout << endl;
    cout << "Grand opening discounts:" << endl;
    cout << "\t 20% off first pizza" << endl;
    cout << "\t 15% off first burger" << endl;
    cout << "\t 10% off first sandwich" << endl;
    cout << setw(80) << setfill('-') << "" << endl;

    // Decide what item to order based on user input
    int orderChoice = 0;
    do
    {
        cout << endl;
        cout << "Please choose one of the following options:\n"
             << endl;
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
                cout << "Whoops! That's not a valid input. Please enter a number 0-3." << endl;
            }
        } while (!validOrderChoice);

        switch (orderChoice)
        {
        // Pizza and toppings
        case 1:
        {
            int pizzaCount = 0;
            double pizzaCost = 0;

            // Validate user input
            bool validPizzaCount = false;
            do
            {
                cout << "How many pizzas would you like to order? ";
                cin >> pizzaCount;

                if (pizzaCount >= 0)
                {
                    validPizzaCount = true;
                }
                else
                {
                    cout << "Unfortunately we do not serve negative pizzas." << endl;
                }
            } while (!validPizzaCount);

            // For each topping
            for (int i = 1; i <= pizzaCount; i++)
            {
                double indvidualPizzaCost = 0;
                int pizzaToppingCount = 0;

                // Validate user input
                bool validPizzaToppingCount = false;
                do
                {
                    cout << "How many toppings would you like on pizza " << i << "? ";
                    cin >> pizzaToppingCount;

                    if (pizzaToppingCount >= 0)
                    {
                        validPizzaToppingCount = true;
                    }
                    else
                    {
                        cout << "Unfortunately we do not serve negative toppings." << endl;
                    }
                } while (!validPizzaToppingCount);

                // Applying discount on 1st item
                if (totalPizzaCount == 0 && i == 1)
                {
                    indvidualPizzaCost = ((pizzaPrice + (pizzaToppingCount * pizzaToppingPrice)) * (1 - pizzaDiscountPercenage));
                    cout << fixed << setprecision(2) << "This pizza costs $" << indvidualPizzaCost << endl;
                }
                else
                {
                    indvidualPizzaCost = (pizzaPrice + (pizzaToppingCount * pizzaToppingPrice));
                    cout << fixed << setprecision(2) << "This pizza costs $" << indvidualPizzaCost << endl;
                }

                totalPizzaPrice += indvidualPizzaCost;
                updatedTotalPrice += indvidualPizzaCost;
            }

            totalPizzaCount += pizzaCount;

            // Item add and price update statement
            cout << endl;
            if (pizzaCount == 0)
            {
                cout << "No pizzas added to order.";
            }
            else if (pizzaCount == 1)
            {
                cout << fixed << setprecision(2) << "Added a pizza to your order and the total is now $" << updatedTotalPrice;
            }
            else
            {
                cout << fixed << setprecision(2) << pizzaCount << " pizzas added to your order and the total is now $" << updatedTotalPrice;
            }
            cout << endl;

            break;
        }

        // Burger
        case 2:
        {
            int burgerCount = 0;

            // Validate user input
            bool validBurgerCount = false;
            do
            {
                cout << "How many burgers would you like to order? ";
                cin >> burgerCount;

                if (burgerCount >= 0)
                {
                    validBurgerCount = true;
                }
                else
                {
                    cout << "Unfortunately we do not serve negative burgers." << endl;
                }
            } while (!validBurgerCount);

            // Applying discount on 1st item
            if (totalBurgerCount == 0)
            {
                totalBurgerPrice += ((burgerCount * burgerPrice) - (burgerPrice * burgerDiscountPercenage));
                updatedTotalPrice += ((burgerCount * burgerPrice) - (burgerPrice * burgerDiscountPercenage));
            }
            else
            {
                totalBurgerPrice += (burgerCount * burgerPrice);
                updatedTotalPrice += (burgerCount * burgerPrice);
            }

            totalBurgerCount += burgerCount;

            // Item add and price update statement
            cout << endl;
            if (burgerCount == 0)
            {
                cout << "No burgers added to order.";
            }
            else if (burgerCount == 1)
            {
                cout << fixed << setprecision(2) << "Added a burger to your order and the total is now $" << updatedTotalPrice;
            }
            else
            {
                cout << fixed << setprecision(2) << burgerCount << " burgers added to your order and the total is now $" << updatedTotalPrice;
            }
            cout << endl;

            break;
        }

        // Sandwich
        case 3:
        {
            int sandwichCount = 0;

            // Validate user input
            bool validSandwichCount = false;
            do
            {
                cout << "How many sandwiches would you like to order? ";
                cin >> sandwichCount;

                if (sandwichCount >= 0)
                {
                    validSandwichCount = true;
                }
                else
                {
                    cout << "Unfortunately we do not serve negative sandwiches." << endl;
                }
            } while (!validSandwichCount);

            // Applying discount on 1st item
            if (totalSandwichCount == 0)
            {
                totalSandwichPrice += ((sandwichCount * sandwichPrice) - (sandwichPrice * sandwichDiscountPercenage));
                updatedTotalPrice += ((sandwichCount * sandwichPrice) - (sandwichPrice * sandwichDiscountPercenage));
            }
            else
            {
                totalSandwichPrice += (sandwichCount * sandwichPrice);
                updatedTotalPrice += (sandwichCount * sandwichPrice);
            }

            totalSandwichCount += sandwichCount;

            // Item add and price update statement
            cout << endl;
            if (sandwichCount == 0)
            {
                cout << "No sandwiches added to order.";
            }
            else if (sandwichCount == 1)
            {
                cout << fixed << setprecision(2) << "Added a sandwich to your order and the total is now $" << updatedTotalPrice;
            }
            else
            {
                cout << fixed << setprecision(2) << sandwichCount << " sandwiches added to your order and the total is now $" << updatedTotalPrice;
            }
            cout << endl;

            break;
        }
        }

    } while (orderChoice != 0);

    double totalPrice = {
        totalPizzaPrice +
        totalBurgerPrice +
        totalSandwichPrice};

    // Receipt output to user
    cout << endl;
    cout << setw(80) << setfill('-') << "" << endl;
    cout << endl;
    cout << fixed << setprecision(2);
    cout << "- " << totalPizzaCount << " Pizzas - "
         << "$" << totalPizzaPrice << endl;
    cout << "- " << totalBurgerCount << " Burgers - "
         << "$" << totalBurgerPrice << endl;
    cout << "- " << totalSandwichCount << " Sandwiches - "
         << "$" << totalSandwichPrice << endl;
    cout << endl;

    cout << "The total for your order is $" << totalPrice << endl;

    if (totalPrice == 0)
    {
        cout << "Wow, you really didn't order anything." << endl;
    }
    else
    {
        cout << "Thank you for dining at The Cauldron Restaurant!" << endl;
    }
    cout << endl;
    cout << setw(80) << setfill('-') << "" << endl;
    cout << setw(80) << setfill('-') << "" << endl;

    // Writing receipt to file
    ofstream receiptArchive;

    receiptArchive.open("restaurant.txt", ios::app);
    if (!receiptArchive.is_open())
    {
        cout << "Could not save receipt to archive. Unable to open restaurant.txt" << endl;
        return 1;
    }

    receiptArchive << endl;
    receiptArchive << setw(80) << setfill('-') << "" << endl;
    receiptArchive << fixed << setprecision(2);
    receiptArchive << "- " << totalPizzaCount << " Pizzas - "
                   << "$" << totalPizzaPrice << endl;
    receiptArchive << "- " << totalBurgerCount << " Burgers - "
                   << "$" << totalBurgerPrice << endl;
    receiptArchive << "- " << totalSandwichCount << " Sandwiches - "
                   << "$" << totalSandwichPrice << endl;
    receiptArchive << endl;
    receiptArchive << "The total for your order is $" << totalPrice << endl;
    receiptArchive << setw(80) << setfill('-') << "" << endl;

    receiptArchive.close();

    return 0;
}