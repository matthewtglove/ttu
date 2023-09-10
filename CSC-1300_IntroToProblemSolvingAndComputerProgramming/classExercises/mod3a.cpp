/*
    Author: Matthew Love
    Date: 2023-08-30, Wed
    Purpose: Write a program that does math operations and prints result to screen
*/

#include <iostream>
using namespace std;

int main()
{
    int result;

    result = 6 - 3 * 2 + 7 - 1 + 17 % 2;
    cout << result << endl;
    
    result = (6 - 3) * 2 + (7 - 1) + 17 % 2;
    cout << result << endl;

    return 0;
}