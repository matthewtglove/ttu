/*
    Title: mod6c.cpp
    Author: Matthew Love
    Date: 2023-09-29, Fri
    Purpose: Output details from a file
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string title = "";
    int year = 0;
    string rottenTomatoScore = "";

    ifstream movieData;

    string fileName;
    bool fileFound;

    do
    {
        cout << "What is the name of your file?" << endl;
        cout << "FILE: ";
        getline(cin, fileName);

        movieData.open(fileName, ios::in);

        if (!movieData.is_open())
        {
            cout << "ERROR. Cannot open file: " << fileName << endl;
            continue;
        }
        else
        {
            fileFound = true;
        }

    } while (!fileFound);

    int iOutput = 1;
    while (!movieData.eof())
    {
        cout << setw(3) << right << iOutput << ") ";
        getline(movieData, title, '#');
        cout << "Title: " << title << ", ";

        string stringYear = "";
        getline(movieData, stringYear, '#');
        year = stoi(stringYear);
        cout << "Year: " << year << ", ";

        getline(movieData, rottenTomatoScore, '#');
        cout << "Rotten Tomatoes Score: " << rottenTomatoScore << endl;

        iOutput++;
    }

    movieData.close();

    return 0;
}