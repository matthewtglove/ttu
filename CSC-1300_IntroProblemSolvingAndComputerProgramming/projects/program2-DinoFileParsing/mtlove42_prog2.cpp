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
        // printDino(...);

        cout << dinoName << endl; // TEST

        // Incrementing totals
        totalDinosaurs++;

        bool containsSaurus = (dinoName.find('s'));
    }

    /*
    while (getline(sourceFile, currentItem, '#'))
    {
        int dinoIndex = 0;
        do
        {
            dinoIndex = (fileIndex % 5) + 1;

            string dinoName = "";
            string dinoSize = "";
            string dinoMass = "";
            string dinoFood = "";
            string dinoDescription = "";

            switch (dinoIndex)
            {
            case 1:
            {
                cout << currentItem << endl; // TEST
                dinoName = currentItem;
                totalDinosaurs++;
                break;
            }

            case 2:
            {
            }
            }

            fileIndex++;
        } while (dinoIndex != 1);
    }
    */

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

void printDino(ofstream &outFile, ifstream &inFile, string inputDinoName, int totalCarnivores, int totalHerbivores, int totalNonDinosaurs, int &totalTenThousandPounds)
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
}