/*
    Title: mod10a.cpp
    Author: Matthew Love
    Date: 2023-11-08, Wed
    Purpose: Use structs
*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Song
{
    string name;
    string artist;
    double length;
};

int main()
{
    Song song;
    cout << "Please enter the details of your favorite song, or else..." << endl;
    cout << "NAME: ";
    getline(cin, song.name);
    cout << "ARTIST: ";
    getline(cin, song.artist);
    cout << "LENGTH: ";
    cin >> song.length;
    cin.ignore();

    cout << "Well done. You will live.\nThe song you entered is..." << endl;
    cout << left;
    cout << setw(12) << "Name: " << setw(40) << song.name << endl;
    cout << setw(12) << "Artist: " << setw(40) << song.artist << endl;
    cout << setw(12) << "Length: " << setw(40) << song.length << endl;

    return 0;
}