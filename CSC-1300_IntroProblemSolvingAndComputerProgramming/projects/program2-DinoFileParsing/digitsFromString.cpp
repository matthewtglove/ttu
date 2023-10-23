#include <iostream>
#include <string>
using namespace std;

int main()
{
    string thisString = "Wow 349 sddkfj 7,800 djfj";

    // for (int i = 0; i < thisString.size(); i++)
    // {
    //     if (isdigit(thisString.at(i)))
    //     {
    //     }
    // }

    // For the important second number because it's the bigger one we care about
    int indexLastDigit = thisString.find_last_of("0123456789");
    int indexFirstDigit;

    for (int i = 0; i < thisString.size(); i++)
    {
        if (!isdigit(thisString.at(indexLastDigit - i)) || !(((thisString.at(indexLastDigit - i))) == ','))
        {
            indexFirstDigit = (indexLastDigit - i) + 1;
        }
    }

    string parsedString = thisString.substr(indexFirstDigit, indexLastDigit - indexFirstDigit);

    cout << thisString << endl;
    cout << parsedString << endl;
}