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

    movieData.open("movieData1_mac.txt");

    if (!movieData.is_open())
    {
        cout << "Cannot open file: movieData1_mac.txt" << endl;
        return 1;
    }

    int iOutput = 1;
    while (!movieData.eof())
    {
        cout << setw(3) << right << iOutput << ") ";
        getline(movieData, title);
        cout << "Title: " << title << ", ";

        string stringYear = "";
        getline(movieData, stringYear);
        year = stoi(stringYear);
        cout << "Year: " << year << ", ";

        getline(movieData, rottenTomatoScore);
        cout << "Rotten Tomatoes Score: " << rottenTomatoScore << endl;

        iOutput++;
    }

    movieData.close();

    return 0;
}