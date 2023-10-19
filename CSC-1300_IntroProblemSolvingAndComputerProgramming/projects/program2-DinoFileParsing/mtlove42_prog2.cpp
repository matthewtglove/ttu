/*
    Title: mtlove42_prog2.cpp
    Author: Matthew Love
    Date: 2023-10-15, Sun
    Purpose: Parsing data on dinosaurs into output files and to the console
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int carnOrHerb(string);
bool searchCarnivore(string);
bool searchHerbivore(string);
void printDino(ofstream &, ifstream &, string, int, int &);
bool overTenGrand(string);

/* TODO
- Validate the printDino for whitespace
- Place a comment above each function telling the function name & purpose.
- Name your variables where they describe what they hold.  Accumulator variables should have the word “total” or
“sum” in them
*/

int main()
{
    ifstream sourceFile;

    bool sourceFileIsOpen = false;
    do
    {
        cout << "Please input the dinosaur file you would like to parse: ";
        string userFile;
        getline(cin, userFile);

        sourceFile.open(userFile);
        sourceFileIsOpen = !sourceFile.is_open();

        if (!sourceFile.is_open())
        {
            cout << "Could not open file " << userFile << endl;
        }
    } while (sourceFileIsOpen);

    // Running totals
    int totalDinosaurs;
    int totalCarinvores;
    int totalHerbivores;
    int totalTenThousandPounds;
    int totalSaurusInName;
    int totalNonDinosaurs;

    while (!sourceFile.eof())
    {
        string dinoName = "";

        getline(sourceFile, dinoName, '#');

        // Incrementing totals
        size_t containsSaurus = dinoName.find("saurus");
        if (!(containsSaurus = string::npos))
        {
            totalSaurusInName++;
        }

        switch (carnOrHerb(dinoName))
        {
        case 1:
        {
            totalCarinvores++;
            cout << dinoName << " is being printed to the CARNIVORE file!" << endl;

            ofstream carnivoresFile;
            carnivoresFile.open("carnOutFile.txt", ios::app);

            printDino(carnivoresFile, sourceFile, dinoName, totalCarinvores, totalTenThousandPounds);

            carnivoresFile.close();

            break;
        }
        case 2:
        {
            totalHerbivores++;
            cout << dinoName << " is being printed to the HERBIVORE file!" << endl;

            ofstream herbivoresFile;
            herbivoresFile.open("herbOutFile.txt", ios::app);

            printDino(herbivoresFile, sourceFile, dinoName, totalHerbivores, totalTenThousandPounds);

            herbivoresFile.close();

            break;
        }
        case 3:
        {
            totalNonDinosaurs++;
            cout << dinoName << " is being printed to the OTHER file!" << endl;

            ofstream nonDinosaursFile;
            nonDinosaursFile.open("otherOutFile.txt", ios::app);

            printDino(nonDinosaursFile, sourceFile, dinoName, totalNonDinosaurs, totalTenThousandPounds);

            nonDinosaursFile.close();

            break;
        }
        }

        // Printing to file

        // printDino()
    }

    totalDinosaurs = totalCarinvores + totalHerbivores;

    sourceFile.close();
    return 0;
}

bool searchCarnivore(string dinoName)
{
    ifstream carnivoreSource;
    carnivoreSource.open("carinvores.txt");

    bool isCarnivore;
    while (!carnivoreSource.eof() || isCarnivore)
    {
        string carnivore;
        getline(carnivoreSource, carnivore);
        isCarnivore = (dinoName == carnivore);
    }

    return isCarnivore;
}

bool searchHerbivore(string dinoName)
{
    ifstream herbivoreSource;
    herbivoreSource.open("carinvores.txt");

    bool isHerbivore;
    while (!herbivoreSource.eof() || isHerbivore)
    {
        string herbivore;
        getline(herbivoreSource, herbivore);
        isHerbivore = (dinoName == herbivore);
    }

    return isHerbivore;
}

int carnOrHerb(string dinoName)
{
    if (searchCarnivore(dinoName))
    {
        return 1;
    }
    else if (searchHerbivore(dinoName))
    {
        return 2;
    }
    else
    {
        return -1;
    }
}

void printDino(ofstream &outFile, ifstream &inFile, string inputDinoName, int totalOfAnimalAccumulator, int &totalTenThousandPounds)
{
    string dinoName = inputDinoName;
    string dinoSize = "";
    string dinoMass = "";
    string dinoFood = "";
    string dinoDescription = "";

    getline(inFile, dinoSize, '#');
    getline(inFile, dinoMass, '#');
    getline(inFile, dinoFood, '#');
    getline(inFile, dinoDescription, '#');

    outFile << setw(50) << setfill('-') << "\n";
    outFile << totalOfAnimalAccumulator << "\n";
    outFile << "\tNAME: " << dinoName << "\n";
    outFile << "\tHEIGHT/LENGTH: " << dinoSize << "\n";
    outFile << "\tMASS: " << dinoMass << "\n";
    outFile << "\tANIMAL FOOD: " << dinoFood << "\n";
    outFile << "\tDESCRIPTION: " << dinoDescription << "\n";
    outFile << endl;
}

bool overTenGrand(string dinoMass)
{
    // Check the STRING, getting rid of the commas then converting to int
}