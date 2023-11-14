/*
    Title: mod10c.cpp
    Author: Matthew Love
    Date: 2023-11-08, Wed
    Purpose: Passing structs into a function
*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int NUM_PHONES = 3;

struct Phone
{
    string type;
    string color;
    float storage;
};

void addPhone(Phone phone[]);
void printPhone(Phone phone[]);

int main()
{
    Phone phone[NUM_PHONES];
    addPhone(phone);
    printPhone(phone);

    return 0;
}

void addPhone(Phone phone[])
{
    for (int i = 0; i < NUM_PHONES; i++)
    {
        cout << "Enter details for phone " << i + 1 << endl;
        cout << "Type: ";
        getline(cin, phone[i].type);
        cout << "Color: ";
        getline(cin, phone[i].color);
        cout << "Storage Capacity (in GB): ";
        cin >> phone[i].storage;
        cin.ignore();
        cout << endl;
    }
}

void printPhone(Phone phone[])
{
    for (int i = 0; i < NUM_PHONES; i++)
    {
        cout << "--------Details for phone " << i + 1 << "--------" << endl;
        cout << left;
        cout << setw(30) << "Type: " << setw(60) << phone[i].type << endl;
        cout << setw(30) << "Color: " << setw(60) << phone[i].color << endl;
        cout << setw(30) << "Storage Capacity (in GB): " << setw(60) << phone[i].storage << endl;
        cout << endl;
    }
}