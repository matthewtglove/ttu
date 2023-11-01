#include "mtlove42_prog3.h"

int main()
{
    // Type of the candy (1 = Wonka Bar, 2 = Everlasting Gobstoppers, 3 = Hair Toffee)
    int candyType[50] = {0};
    // Holds a custom flavor for the candy
    string candyFlavor[50] = {""};
    float costMaterials[50] = {0.0};
    int numOompas[50] = {0};
    float askingPrice[50] = {0.0};

    int totalCountCandy = 0;

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
        break;
    }
    }

    // TEST
    cout << totalCountCandy << endl;
    cout << candyType[totalCountCandy - 1] << endl;
    cout << candyFlavor[totalCountCandy - 1] << endl;
    cout << costMaterials[totalCountCandy - 1] << endl;
    cout << numOompas[totalCountCandy - 1] << endl;
    cout << askingPrice[totalCountCandy - 1] << endl;

    return 0;
}