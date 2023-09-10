#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
    string favoriteColor;
    string favoriteNum;
    cout << "What is your favorite color?" << endl;
    cin >> favoriteColor;
    cout << endl;
    cout << "What is your favorite number?" << endl;
    cin >> favoriteNum;
    cout << endl;
    cout << "Your favorite color is " << favoriteColor << ". \n";

    bool successful = false;
    try
    {
        stod(favoriteNum); // Tries to convert to number (should only works if number was input)
        successful = true;
    }
    catch (...)
    {
        // default not successful
    };

    if (successful)
    {
        cout << "Your favorite number is " << favoriteNum << ". Thanks for inputing a number!";
    }
    else
    {
        cout << "Your favorite number is '" << favoriteNum << "'. Be sure to input a number next time (not text).";
    }
    cout << endl;
    return 0;
}