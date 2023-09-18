/*
    Date: 2023-09-10, Sun
    Purpose: Replace all alphanumeric characters and spaces in a string with an underscore
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string userString;

    getline(cin, userString);

    for (int i = 0; i < userString.size(); i++)
    {
        if (isalpha(userString.at(i)) || isspace(userString.at(i)))
        {
            userString.at(i) = '_';
        }
    }

    cout << userString << endl;

    return 0;
}