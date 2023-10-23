#include <iostream>
#include <string>
using namespace std;

int requireIntFromUser()
{
    int convertedInput;
    bool successfulConversion = false;
    do
    {
        try
        {
            string input;
            getline(cin, input);
            convertedInput = stoi(input);
            successfulConversion = true;
        }
        catch (...)
        {
            cout << "Please enter an integer: ";
        };
    } while (!successfulConversion);
    return convertedInput;
}
