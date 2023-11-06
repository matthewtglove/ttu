/*
    Date: 2023-11-04, Sat
    Purpose: To easily calculate math without having to change each variable location on my calculator
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // float x = -3;
    // float calculation = 6 * pow(x, 3) - 9 * pow(x, 2) - 216 * x + 5;

    float x = -2;
    float calculation = log(pow(x, 2) + 3 * x + 4);

    cout << fixed << setprecision(50);
    cout << calculation << endl;
    return 0;
}