#include "mtlove42_prog3.h"

int main()
{
    // Type of the candy (1 = Wonka Bar, 2 = Everlasting Gobstoppers, 3 = Hair Toffee)
    int candyType[50] = {0};
    // Holds a custom flavor for the candy
    string candyFlavor[50] = {""};
    // Holds the cost for the candy
    float costMaterials[50] = {0.0};
    // Number of Oompa Loompas it took to create the candy
    int numOompas[50] = {0};
    // Asking price of the candy
    float askingPrice[50] = {0.0};

    cout << "TEST: " << getMenuOption() << endl; // TEST

    return 0;
}