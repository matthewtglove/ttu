#include "mtlove42_prog4.h"

// Given function
float convertToFloat(string s)
{
    istringstream i(s);
    float x;
    if (!(i >> x))
        x = 0;
    return x;
}

// For validating input - Checks both type (should be integer) and range
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
                cout << invalidInputMessage << " Please enter an integer ";
                if (!(minRange == INT_MIN && maxRange == INT_MAX))
                {
                    cout << minRange << " to " << maxRange;
                }
                cout << endl;
            };
        } while (!successfulConversion);

        userInput = convertedInput;

        validRange = (userInput >= minRange && userInput <= maxRange);
        if (!validRange)
        {
            cout << invalidInputMessage;
            if (!(minRange == INT_MIN && maxRange == INT_MAX))
            {
                cout << " Please enter " << minRange << " to " << maxRange;
            }
            cout << endl;
        }
    } while (!validRange);

    return userInput;
}

// For validating input - Checks both type (should be float) and range
float requireFloatInput(float minRange = -1000000000, float maxRange = 1000000000, string invalidInputMessage = "Invalid input.")
{
    float userInput = 0;
    bool validRange = false;
    do
    {
        float convertedInput;
        bool successfulConversion = false;
        do
        {
            try
            {
                string input;
                getline(cin, input);
                // Should fail if user did not input a number
                convertedInput = stof(input);
                successfulConversion = true;
            }
            catch (...)
            {
                cout << invalidInputMessage << " Please enter a number ";
                if (!(minRange == -1000000000 && maxRange == 1000000000))
                {
                    cout << minRange << " to " << maxRange;
                }
                cout << endl;
            };
        } while (!successfulConversion);

        userInput = convertedInput;

        validRange = (userInput >= minRange && userInput <= maxRange);
        if (!validRange)
        {
            cout << invalidInputMessage;
            if (!(minRange == -1000000000 && maxRange == 1000000000))
            {
                cout << " Please enter " << minRange << " to " << maxRange;
            }
            cout << endl;
        }
    } while (!validRange);

    return userInput;
}

// For validating input - Ensures user gave a yes/no answer ('y' or 'n')
bool requireYNInput(string prompt)
{
    bool response = false;
    bool validInput;
    while (!validInput)
    {
        cout << prompt << " (y or n): ";

        // Validates user input - reads only the first character they input
        string input;
        getline(cin, input);
        char responseYN = tolower(input[0]);

        if (responseYN == 'y')
        {
            validInput = true;
            response = true;
        }
        else if (responseYN == 'n')
        {
            validInput = true;
            response = false;
        }
        else
        {
            cout << "Please input 'y' or 'n'" << endl;
        }
    }

    return response;
}

// For validing input - double type and within range
int getMenuOption()
{
    cout << "What would you like to do?\n";
    cout << "\t1.\tAdd Vehicles\n";
    cout << "\t2.\tDelete a Vehicle\n";
    cout << "\t3.\tPrint Vehicles\n";
    cout << "\t4.\tPrint statistics on Vehicle cost\n";
    cout << "\t5.\tEnd program\n";

    cout << endl;
    cout << "CHOOSE 1-5: ";
    int userChoice = requireIntInput(1, 5, "Good try, but this input is validated.");
    return userChoice;
}

// For adding vehicles to the vehicle array, either by importing a file or manually adding a vehicle
int enterVehicles(int countVehicles, Vehicles vehicle[])
{
    if (countVehicles >= GARAGE_SIZE)
    {
        cout << "❗ The garage is at full capacity." << endl;
        return countVehicles;
    }

    cout << "How would you like to add vehicle data?\n";
    cout << "\t1.\tImport vehicles from a file\n";
    cout << "\t2.\tEnter vehicles manually\n";

    cout << endl;
    cout << "CHOOSE 1-2: ";

    switch (requireIntInput(1, 2))
    {
    // Import file
    case 1:
    {
        ifstream vehicleFile;

        cout << endl;
        bool fileFound = false;
        do
        {
            string userFileLocation = "";
            cout << "FILENAME: ";
            getline(cin, userFileLocation);

            vehicleFile.open(userFileLocation);

            if (vehicleFile.is_open())
            {
                cout << endl;
                cout << "📂 Opened " << userFileLocation << endl;
                fileFound = true;
            }
            else
            {
                cout << "Could not open file " << userFileLocation << ". Please try again" << endl;
            }
        } while (!fileFound);

        bool endOfFile = false;
        while (!endOfFile)
        {
            if (countVehicles >= GARAGE_SIZE)
            {
                cout << "❌ Error importing vehicle: Garage is at full capacity" << endl;
                return countVehicles;
            }

            string name = "";
            getline(vehicleFile, name, '#');
            if (name == "stop")
            {
                cout << "❌ Error importng vehicle: Vehicle name can not be \"stop\"" << endl;
                return countVehicles;
            }
            vehicle[countVehicles].name = name;

            getline(vehicleFile, vehicle[countVehicles].description, '#');

            string hasWeapons = "0";
            getline(vehicleFile, hasWeapons, '#');
            vehicle[countVehicles].hasWeapons = hasWeapons == "1" ? true : false;

            string numRepairHours = "";
            getline(vehicleFile, numRepairHours, '#');
            vehicle[countVehicles].cost.numRepairHours = convertToFloat(numRepairHours);

            string repairHour = "";
            getline(vehicleFile, repairHour, '#');
            vehicle[countVehicles].cost.repairHour = convertToFloat(repairHour);

            string parts = "";
            getline(vehicleFile, parts, '#');
            vehicle[countVehicles].cost.parts = convertToFloat(parts);

            string materials = "";
            getline(vehicleFile, materials, '#');
            vehicle[countVehicles].cost.materials = convertToFloat(materials);

            cout << "⬇ Imported " << vehicle[countVehicles].name << endl;

            countVehicles++;
            endOfFile = vehicleFile.eof();
        }

        vehicleFile.close();
        cout << "✅ Successfully imported vehicle data from file" << endl;
        break;
    }
    // Manually add
    case 2:
    {
        bool addAgain = true;
        do
        {
            cout << endl;
            string name = "";
            bool validName = false;
            do
            {
                cout << "NAME: ";
                getline(cin, name);
                if (name == "stop")
                {
                    cout << "❌ Error: Vehicle name can not be \"stop\"" << endl;
                }
                else
                {
                    validName = true;
                }
            } while (!validName);
            vehicle[countVehicles].name = name;

            cout << "DESCRIPTION: ";
            getline(cin, vehicle[countVehicles].description);

            vehicle[countVehicles].hasWeapons = requireYNInput("DOES THIS VEHICLE HAVE WEAPONS?");

            cout << "How many hours do you spend repairing the " << vehicle[countVehicles].name << "?" << endl;
            cout << "NUM HOURS: ";
            vehicle[countVehicles].cost.numRepairHours = requireFloatInput(0, 1000);

            cout << "What is the cost per hour for repairing the " << vehicle[countVehicles].name << "?" << endl;
            cout << "COST PER HOUR: $";
            vehicle[countVehicles].cost.repairHour = requireFloatInput(0, 1000000000);

            cout << "How much money do you spend on parts to repair the " << vehicle[countVehicles].name << "?" << endl;
            cout << "PART COST: $";
            vehicle[countVehicles].cost.parts = requireFloatInput(0, 1000000000);

            cout << "How much money do you spend on supplies to repair the " << vehicle[countVehicles].name << "?" << endl;
            cout << "SUPPLY COST: $";
            vehicle[countVehicles].cost.materials = requireFloatInput(0, 1000000000);

            cout << endl;
            cout << "✅ Successfully added " << vehicle[countVehicles].name << endl;
            cout << endl;

            countVehicles++;

            if (countVehicles >= GARAGE_SIZE)
            {
                cout << "❗ Garage is at full capacity" << endl;
                return countVehicles;
            }

            addAgain = requireYNInput("Would you like to add more vehicles?");
        } while (addAgain);

        break;
    }
    }

    return countVehicles;
}

// For removing vehicles from the vehicle array
int deleteVehicle(int countVehicles, Vehicles vehicle[])
{
    cout << "The following is a list of all the vehicles you take care of:" << endl;
    cout << endl;

    for (int i = 0; i < countVehicles; i++)
    {
        cout << "- " << vehicle[i].name << "\n";
    }

    cout << endl;
    cout << "What vehicle do you wish to remove? (Type \"stop\" to cancel)" << endl;

    string removedVehicle = "";
    bool userConfirmDelete = false;
    bool validVehicle = false;
    do
    {
        cout << "VEHICLE NAME: ";
        getline(cin, removedVehicle);

        if (removedVehicle == "stop")
        {
            return countVehicles;
        }

        validVehicle = moveArrayElements(removedVehicle, userConfirmDelete, countVehicles, vehicle);

        if (!validVehicle)
        {
            cout << "❌ Vehicle not found. Please enter the exact vehicle name" << endl;
        }
    } while (!validVehicle);

    if (userConfirmDelete)
    {
        cout << endl;
        cout << "💥 " << removedVehicle << " was removed from the garage. " << countVehicles - 1 << " vehicle(s) remain" << endl;
        return countVehicles - 1;
    }
    else
    {
        cout << endl;
        cout << "✔️ " << removedVehicle << " was not removed" << endl;
        return countVehicles;
    }
}

// For shifting an entire array to overwrite the deleted index
bool moveArrayElements(string removedVehicle, bool &userConfirmDelete, int countVehicles, Vehicles vehicle[])
{
    bool validVehicle = false;
    int iRemovedVehicle = 0;
    for (int i = 0; i < countVehicles; i++)
    {
        if (removedVehicle == vehicle[i].name)
        {
            iRemovedVehicle = i;
            validVehicle = true;
        }
    }

    if (!validVehicle)
    {
        return false;
    }

    cout << endl;
    cout << "Are you sure you want to remove " << vehicle[iRemovedVehicle].name << "?" << endl;
    if (!requireYNInput("Remove vehicle from garage?"))
    {
        userConfirmDelete = false;
        return true;
    }
    else
    {
        userConfirmDelete = true;
        for (int i = 0; i < countVehicles; i++)
        {
            vehicle[iRemovedVehicle + i] = vehicle[iRemovedVehicle + i + 1];
        }
        return true;
    }
}

// For printing the vehicles with all their data to the console or to a file
void printVehicles(int countVehicles, Vehicles vehicle[])
{
    cout << "How would you like to print vehicle data?\n";
    cout << "\t1.\tPrint vehicles to the screen\n";
    cout << "\t2.\tPrint vehicles to a file\n";

    cout << endl;
    cout << "CHOOSE 1-2: ";

    switch (requireIntInput(1, 2))
    {
    case 1:
    {
        streamsize defaultPrecision = cout.precision();
        cout << endl;
        for (int i = 0; i < countVehicles; i++)
        {
            cout << setw(80) << setfill('-') << "" << endl;
            cout << "VEHICLE " << i + 1 << ":" << endl;
            cout << setfill(' ');

            cout << left << setw(26) << "Name: ";
            cout << left << setw(120) << vehicle[i].name << "\n";
            cout << left << setw(26) << "Description: ";
            cout << left << setw(120) << vehicle[i].description << "\n";
            cout << endl;

            cout << left << setw(26) << "Has weapons: ";
            cout << left << setw(120) << (vehicle[i].hasWeapons ? "Yes" : "No") << "\n";

            cout << setprecision(2) << fixed;
            cout << left << setw(26) << "Hours needed for repair: ";
            cout << left << setw(120) << vehicle[i].cost.numRepairHours << "\n";
            cout << left << setw(26) << "Cost per hour: ";
            cout << left << setw(1) << "$";
            cout << left << setw(119) << vehicle[i].cost.repairHour << "\n";
            cout << left << setw(26) << "Cost for parts: ";
            cout << left << setw(1) << "$";
            cout << left << setw(119) << vehicle[i].cost.parts << "\n";
            cout << left << setw(26) << "Cost for supplies: ";
            cout << left << setw(1) << "$";
            cout << left << setw(119) << vehicle[i].cost.materials << "\n";
        }
        cout << setw(80) << setfill('-') << "" << endl;
        cout << setfill(' ');
        cout << setprecision(defaultPrecision) << defaultfloat;
        break;
    }
    case 2:
    {
        cout << endl;
        cout << "What is the name of the file you want to print to?" << endl;

        ofstream printFile;
        string userFileLocation = "";
        cout << "FILENAME: ";
        getline(cin, userFileLocation);

        printFile.open(userFileLocation);

        cout << endl;
        cout << "📂 Opened " << userFileLocation << endl;

        streamsize defaultPrecision = printFile.precision();
        printFile << endl;
        for (int i = 0; i < countVehicles; i++)
        {
            printFile << setw(80) << setfill('-') << "" << endl;
            printFile << "VEHICLE " << i + 1 << ":" << endl;
            printFile << setfill(' ');

            printFile << left << setw(26) << "Name: ";
            printFile << left << setw(120) << vehicle[i].name << "\n";
            printFile << left << setw(26) << "Description: ";
            printFile << left << setw(120) << vehicle[i].description << "\n";
            printFile << endl;

            printFile << left << setw(26) << "Has weapons: ";
            printFile << left << setw(120) << (vehicle[i].hasWeapons ? "Yes" : "No") << "\n";

            printFile << setprecision(2) << fixed;
            printFile << left << setw(26) << "Hours needed for repair: ";
            printFile << left << setw(120) << vehicle[i].cost.numRepairHours << "\n";
            printFile << left << setw(26) << "Cost per hour: ";
            printFile << left << setw(1) << "$";
            printFile << left << setw(119) << vehicle[i].cost.repairHour << "\n";
            printFile << left << setw(26) << "Cost for parts: ";
            printFile << left << setw(1) << "$";
            printFile << left << setw(119) << vehicle[i].cost.parts << "\n";
            printFile << left << setw(26) << "Cost for supplies: ";
            printFile << left << setw(1) << "$";
            printFile << left << setw(119) << vehicle[i].cost.materials << "\n";

            cout << "✏️  Wrote " << vehicle[i].name << "\n";
        }
        printFile << setw(80) << setfill('-') << "" << endl;
        printFile << setfill(' ');
        printFile << setprecision(defaultPrecision) << defaultfloat;

        printFile.close();
        cout << "✅ Vehicles successfully written to " << userFileLocation << "\n";
        break;
    }
    }
}

// For printing the overall cost of each vehicle to the screen
void printStatistics(int countVehicles, Vehicles vehicle[])
{
    float cost = 0;
    float totalCost = 0;

    streamsize defaultPrecision = cout.precision();
    cout << setprecision(2) << fixed;
    cout << endl;
    cout << left << setw(32) << "VEHICLE";
    cout << right << setw(16) << "COST" << endl;
    for (int i = 0; i < countVehicles; i++)
    {
        cost = (vehicle[i].cost.numRepairHours * vehicle[i].cost.repairHour) + vehicle[i].cost.parts + vehicle[i].cost.materials;
        totalCost += cost;

        cout << left << setw(32) << vehicle[i].name;
        cout << left << setw(1) << "$";
        cout << right << setw(15) << cost << "\n";
    }
    cout << endl;
    cout << left << setw(32) << "TOTAL COST:";
    cout << left << setw(1) << "$";
    cout << right << setw(15) << totalCost << "\n";

    cout << setprecision(defaultPrecision) << defaultfloat;
}

void saveVehiclesToFile(int countVehicles, Vehicles vehicle[])
{
    cout << endl;
    cout << "What is the name of the file you want to save to?" << endl;

    ofstream saveFile;
    string userFileLocation = "";
    cout << "FILENAME: ";
    getline(cin, userFileLocation);

    saveFile.open(userFileLocation);

    cout << endl;
    cout << "📂 Opened " << userFileLocation << endl;

    for (int i = 0; i < countVehicles; i++)
    {
        if (i > 0)
        {
            saveFile << "#";
        }
        saveFile << vehicle[i].name;
        saveFile << "#" << vehicle[i].description;
        saveFile << "#" << vehicle[i].hasWeapons;
        saveFile << "#" << vehicle[i].cost.numRepairHours;
        saveFile << "#" << vehicle[i].cost.repairHour;
        saveFile << "#" << vehicle[i].cost.parts;
        saveFile << "#" << vehicle[i].cost.materials;

        cout << "💾 Saved " << vehicle[i].name << "\n";
    }

    saveFile.close();
    cout << "✅ All vehicles have been saved to " << userFileLocation << "\n";
}