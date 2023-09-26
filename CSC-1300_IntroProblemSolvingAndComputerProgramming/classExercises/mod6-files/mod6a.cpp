/*
    Author: Matthew Love
    Date: 2023-09-25, Mon
    Purpose: Write to a file
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream myFile;

    myFile.open("myInfo-6a.txt");
    if (!myFile.is_open())
    {
        cout << "Could not open file myInfo-6a.txt." << endl;
        return 1;
    }

    myFile << "My nickname is " << endl;
    myFile << "I will graduate TTU in 2027." << endl;
    myFile << "I don't like green olives." << endl;

    myFile.close();

    return 0;
}