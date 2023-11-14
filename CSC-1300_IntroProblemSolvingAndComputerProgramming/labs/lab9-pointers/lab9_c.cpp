/*
    Title: lab9_c.cpp
    Author: Matthew Love
    Date: 2023-11-13, Mon
    Purpose: Very basic algorithm using vectors
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // C++98
    vector<int> coolNumber(10);
    coolNumber.at(0) = 7;
    coolNumber.at(1) = 4;
    coolNumber.at(2) = 36;
    coolNumber.at(3) = 1;
    coolNumber.at(4) = 3;
    coolNumber.at(5) = 6;
    coolNumber.at(6) = 2;
    coolNumber.at(7) = 99;
    coolNumber.at(8) = 77;
    coolNumber.at(9) = 10;

    /* C++11
    vector<int> coolNumber = {7, 4, 36, 1, 3, 6, 2, 99, 77, 10};
    */

    cout << "All vector elements multiplied by 2 are: ";
    for (int i = 0; i < coolNumber.size(); i++)
    {
        coolNumber.at(i) *= 2;
        cout << coolNumber.at(i) << " ";
    }
    cout << endl
         << endl;

    int sum = 0;
    for (int i = 0; i < coolNumber.size() - 2; i++)
    {
        sum += coolNumber.at(i);
    }
    cout << "Sum of all numbers in the vector: " << sum << endl;

    for (int i = 0; i < coolNumber.size() - 1; i++)
    {
        int iMin = i;
        for (int j = i + 1; j < coolNumber.size(); j++)
        {
            if (coolNumber.at(j) < coolNumber.at(iMin))
            {
                iMin = j;
            }
        }

        int temp = coolNumber.at(i);
        coolNumber.at(i) = coolNumber.at(iMin);
        coolNumber.at(iMin) = temp;
    }

    cout << endl;
    cout << "The sorted vector elements are: ";
    for (int i = 0; i < coolNumber.size(); i++)
    {
        cout << coolNumber.at(i) << " ";
    }
    cout << endl;

    return 0;
}