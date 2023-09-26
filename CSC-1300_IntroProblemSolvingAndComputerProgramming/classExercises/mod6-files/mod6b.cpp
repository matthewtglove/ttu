/*
    Author: Matthew Love
    Date: 2023-09-25, Mon
    Purpose: Input from a file
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream myFile;

    myFile.open("myText-6b.txt");
    if (!myFile.is_open())
    {
        cout << "Could not open file myInfo.txt." << endl;
        return 1;
    }
    string name;
    int number[] = {};

    getline(myFile, name);
    cout << name << endl;

    for (int i = 0; i < 5; i++)
    {
        myFile >> number[i];
        cout << number[i] << endl;
    }

    myFile.close();

    return 0;
}