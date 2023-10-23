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
        sourceFileIsOpen = sourceFile.is_open();

        if (!sourceFile.is_open())
        {
            cout << "Could not open file " << userFile << endl;
        }
    } while (!sourceFileIsOpen);

    // Running totals
    int totalDinosaurs = 0;
    int totalCarnivores = 0;
    int totalHerbivores = 0;
    int totalNonDinosaurs = 0;
    int totalSaurusInName = 0;
    int totalTenThousandPounds = 0;

    string dinoName;
    while (getline(sourceFile, dinoName, '#'))
    {
        size_t containsSaurus = dinoName.find("saurus");
        if (containsSaurus != string::npos)
        {
            totalSaurusInName++;
        }

        // cout << dinoName << endl; // test

        // cout << carnOrHerb(dinoName) << endl; // test

        switch (carnOrHerb(dinoName))
        {
        case 1:
        {
            totalCarnivores++;
            cout << dinoName << " is being printed to the CARNIVORE file!" << endl;

            ofstream carnivoresFile;
            carnivoresFile.open("carnOutFile.txt", ios::app);

            printDino(carnivoresFile, sourceFile, dinoName, totalCarnivores, totalTenThousandPounds);

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
        case -1:
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
    }

    totalDinosaurs = totalCarnivores + totalHerbivores;

    sourceFile.close();

    // Outputting to user
    cout << setw(50) << setfill('-') << "\n";
    cout << "TOTAL DINOS: " << totalDinosaurs << "\n";
    cout << "TOTAL CARNIVORE DINOS: " << totalCarnivores << "\n";
    cout << "TOTAL HERBIVORE DINOS: " << totalHerbivores << "\n";
    cout << "DINOS OVER 10,000 LBS: " << totalTenThousandPounds << "\n";
    cout << "DINO NAMES END IN 'SAURUS': " << totalSaurusInName << "\n";
    cout << "ANIMALS NOT DINOS: " << totalNonDinosaurs << "\n";
    cout << setw(50) << setfill('-') << endl;

    return 0;
}

// To check if an animal is a carnivore
bool searchCarnivore(string dinoName)
{
    ifstream carnivoreSource;
    carnivoreSource.open("carnivores.txt");

    if (!carnivoreSource.is_open())
    {
        cout << "ERROR: Could not open carnivores.txt" << endl;
        return false;
    }

    string carnivore;
    while (getline(carnivoreSource, carnivore, '#'))
    {
        if (dinoName == carnivore)
        {
            carnivoreSource.close();
            return true;
        }
    }

    carnivoreSource.close();
    return false;
}

// To check if an animal is a herbivore
bool searchHerbivore(string dinoName)
{
    ifstream herbivoreSource;
    herbivoreSource.open("herbivores.txt");

    if (!herbivoreSource.is_open())
    {
        cout << "ERROR: Could not open herbivores.txt" << endl;
        return false;
    }

    string herbivore;
    while (getline(herbivoreSource, herbivore, '#'))
    {
        if (dinoName == herbivore)
        {
            herbivoreSource.close();
            return true;
        }
    }

    herbivoreSource.close();
    return false;
}

// To return whether an animal is a carnivore, herbivore, or neither
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

// To print out the data from the source file to individual files based on the animal type
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
    outFile << "\tFOOD: " << dinoFood << "\n";
    outFile << "\tDESCRIPTION: " << dinoDescription << "\n";
    outFile << endl;
}

bool overTenGrand(string dinoMass)
{
    // Unfortunately, I ran out of time to figure out how to do this corrently
    size_t isTenthousand = dinoMass.find("10," || "11," || "30," || "31," || "17,");
    return isTenthousand;
}