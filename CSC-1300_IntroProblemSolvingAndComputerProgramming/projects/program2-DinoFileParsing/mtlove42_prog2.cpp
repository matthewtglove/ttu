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

    // Start the loop to read from the file. I recommend your loop header be the following line:
    // while(getline(dinoDirFile, tempString, ‘#’))

    sourceFile.close();
    return 0;
}