/*
    Author: Matthew Love
    Date: 2023-09-25, Mon
    Purpose: Append to a file
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    ofstream myFile;

    myFile.open("thisRandomFile.txt", ios::app);
    if (!myFile.is_open())
    {
        cout << "Could not open file thisRandomFile.txt." << endl;
        return 1;
    }

    string input;
    do
    {
        getline(cin, input);

        myFile << input;
    } while (input != "stop");

    myFile.close();

    return 0;
}