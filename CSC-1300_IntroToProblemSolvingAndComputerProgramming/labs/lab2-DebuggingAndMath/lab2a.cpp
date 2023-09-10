/*
    Filename: lab2a.cpp
    Author: Trey Gannod and Matthew Love
    Date: 2023-08-29, Tue
    Purpose: Practice debugging code
*/


#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    string name;
    double radius;
    const double PI = 3.14;
    double area;

    //print welcome message after getting user's name
    cout << "What is your name?";
    cin >> name;
    cout << "\nHi, " << name << ", welcome to this program!" << endl;

    //introduce lab partners and tell fun facts about yourselves
    cout << "Our names are Trey and Matthew.\n\n";
    cout << "A fun fact about Trey is he plays the drums.\n\n";
    cout << "A fun fact about Matthew is he has lived in Africa.\n\n";

    //calculate the area of user's circle
    cout << "What is the radius of your circle? ";
    cin >> radius;

    area = PI * pow(radius, 2.0);

    cout << "\nThe area of your circle is " << area << endl << endl;

    return 0;
}
