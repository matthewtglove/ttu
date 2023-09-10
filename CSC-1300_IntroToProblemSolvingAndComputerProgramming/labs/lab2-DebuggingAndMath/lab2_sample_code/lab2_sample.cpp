/*
    Filename: lab2_sample.cpp
    Authors:  Colton Sellner and Revel Etheridge
    Date:     29 August 2023
    Purpose:  This code demonstrates the concepts needed for lab 2 of CSC 1300.
*/

#include <iostream>
using namespace std;

const int dozen = 12;

int main() {
    int boxes;

    //user input
    cout << "How many boxes of donuts do you want: ";
    cin >> boxes;

    //output
    cout << "You will have " << boxes * dozen << " donuts!";

    return 0;
}