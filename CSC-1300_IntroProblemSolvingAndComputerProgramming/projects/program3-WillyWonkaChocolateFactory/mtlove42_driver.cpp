#include "mtlove42_prog3.h"

int main()
{
    // Type of the candy (1 = Wonka Bar, 2 = Everlasting Gobstoppers, 3 = Hair Toffee)
    int candyType[50] = {0};
    string candyTypeName[3] = {"Wonka Bar", "Everlasting Gobstoppers", "Hair Toffee"};
    // Holds a custom flavor for the candy
    string candyFlavor[50] = {""};
    float costMaterials[50] = {0.0};
    int numOompas[50] = {0};
    float askingPrice[50] = {0.0};

    int totalCountCandy = 0;

    cout << "A very Willy Wonka Welcome to you!" << endl;
    cout << endl;

    bool exitManagementSoftware = false;
    do
    {
        switch (getMenuOption())
        {
        case 1:
        {
            cout << endl;
            addCandy(totalCountCandy, candyType, candyFlavor, costMaterials, numOompas, askingPrice);
            break;
        }
        case 2:
        {
            if (totalCountCandy < 1)
            {
                cout << endl;
                cout << "No candy found in inventory. Please add candy to calculate totals." << endl;
                cout << endl;
                break;
            }

            cout << endl;
            cout << "What type of candy would you like to see the totals for?\n";
            cout << "\t1.\tWonka Bar\n";
            cout << "\t2.\tEverlasting Gobstoppers\n";
            cout << "\t3.\tHair Toffee\n";
            cout << "\t4.\tAll candy\n";
            cout << endl;
            cout << "Choose 1-4: ";
            int calculateOption = requireIntInput(1, 4, "Do you eat as much as an elephant eats?");
            calculateTotals(calculateOption, totalCountCandy, candyType, candyTypeName, candyFlavor, costMaterials, numOompas, askingPrice);
            break;
        }
        case 3:
        {
            if (totalCountCandy < 1)
            {
                cout << endl;
                cout << "No candy found in inventory. Please add candy to calculate profit." << endl;
                cout << endl;
                break;
            }

            cout << endl;
            cout << "What type of candy would you like to see the profit for?\n";
            cout << "\t1.\tWonka Bar\n";
            cout << "\t2.\tEverlasting Gobstoppers\n";
            cout << "\t3.\tHair Toffee\n";
            cout << "\t4.\tAll candy\n";
            cout << endl;
            cout << "Choose 1-4: ";
            int calculateOption = requireIntInput(1, 4, "The Suspense Is Terrible. I Hope It'll Last.");
            calculateProfit(calculateOption, totalCountCandy, candyType, candyTypeName, costMaterials, askingPrice);
            break;
        }
        case 4:
        {
            if (totalCountCandy < 1)
            {
                cout << endl;
                cout << "No candy found in inventory. Please add candy to return the max price." << endl;
                cout << endl;
                break;
            }

            int iMaxPrice = 0;
            double maxPrice = getMaxPrice(totalCountCandy, askingPrice, iMaxPrice);
            cout << endl;
            cout << fixed << setprecision(2);
            cout << "The candy with the highest price is the " << candyFlavor[iMaxPrice] << " flavored " << candyTypeName[candyType[iMaxPrice] - 1] << " for $" << maxPrice << endl;
            cout << endl;
            break;
        }
        case 5:
        {
            exitManagementSoftware = true;
        }
        }
    } while (!exitManagementSoftware);

    if (totalCountCandy < 1)
    {
        cout << endl;
        cout << "You Lose! Good Day, Sir." << endl;
        cout << endl;
    }
    else
    {
        cout << endl;
        cout << "Goodbye now!" << endl;
        cout << endl;
    }

    return 0;
}