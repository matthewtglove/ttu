/*
    Title: mod10b.cpp
    Author: Matthew Love
    Date: 2023-11-08, Wed
    Purpose: Array of structs
*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct CarInfo
{
    string make;
    string model;
    int year;
};

struct Car
{
    string color;
    float cost;
};

int main()
{
    CarInfo carInfo[3];
    Car car[3];
    cout << "Tell us about ye cars" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter data for car " << i + 1 << endl;

        cout << "Make: ";
        getline(cin, carInfo[i].make);
        cout << "Model: ";
        getline(cin, carInfo[i].model);
        cout << "Year: ";
        cin >> carInfo[i].year;
        cin.ignore();

        cout << "Color: ";
        getline(cin, car[i].color);
        cout << "Cost: ";
        cin >> car[i].cost;
        cin.ignore();

        cout << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "Your car " << i + 1 << ":" << endl;
        cout << left;
        cout << setw(8) << "Make: " << setw(40) << carInfo[i].make << endl;
        cout << setw(8) << "Model: " << setw(40) << carInfo[i].model << endl;
        cout << setw(8) << "Year: " << setw(40) << carInfo[i].year << endl;
        cout << setw(8) << "Color: " << setw(40) << car[i].color << endl;
        cout << setw(8) << "Cost: " << setw(40) << car[i].cost << endl;

        cout << endl;
    }

    return 0;
}