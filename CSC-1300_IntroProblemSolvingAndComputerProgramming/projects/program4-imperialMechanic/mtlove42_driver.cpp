#include "mtlove42_prog4.h"

int main()
{
    int countVehicles = 0;
    Vehicles vehicle[GARAGE_SIZE];

    cout << endl;
    cout << "--- Imperial Mechanic Vehicle Management ---" << endl;
    cout << endl;

    // To run until the user decides to exit
    bool exitManagementSoftware = false;
    do
    {
        cin >> tempInt;
        switch (tempInt)
        {
        case 1:
        {
            cout << endl;
            countVehicles = enterVehicles(countVehicles, vehicle);
            cout << endl;
            break;
        }
        case 2:
        {
            cout << endl;
            if (countVehicles > 0)
            {
                countVehicles = deleteVehicle(countVehicles, vehicle);
            }
            else
            {
                cout << "❗ There are no vehicles in the garage." << endl;
            }
            cout << endl;
            break;
        }
        case 3:
        {
            cout << endl;
            if (countVehicles > 0)
            {
                printVehicles(countVehicles, vehicle);
            }
            else
            {
                cout << "❗ There are no vehicles in the garage." << endl;
            }
            cout << endl;
            break;
        }
        case 4:
        {
            cout << endl;
            if (countVehicles > 0)
            {
                printStatistics(countVehicles, vehicle);
            }
            else
            {
                cout << "❗ There are no vehicles in the garage." << endl;
            }
            cout << endl;
            break;
        }
        case 5:
        {
            if (countVehicles > 0)
            {
                if (requireYNInput("Would you like to save your vehicle data? All data will be lost if quit without saving"))
                {
                    saveVehiclesToFile(countVehicles, vehicle);
                }
            }
            else
            {
                cout << "No vehicles? Very sad" << endl;
            }

            exitManagementSoftware = true;
            break;
        }
        }
    } while (!exitManagementSoftware);

    return 0;
}