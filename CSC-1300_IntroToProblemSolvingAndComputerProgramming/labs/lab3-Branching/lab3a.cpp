/*
    Title: lab3a.cpp
    Author: Matthew Love
    Date: 2023-09-12, Tue
    Purpose: Receive the user's screen and study time then return advice
*/

#include <iostream>
#include <cstring>
using namespace std;

// Requires the user to input an integer
int reqIntFromUser()
{
    // Keeps prompting the user to input an integer until they do
    while (true)
    {
        try
        {
            string input;
            getline(cin, input);
            return stoi(input); // Tries to convert to number (should only works if input is number)
            break;              // Used to exit the while loop
        }
        catch (...)
        {
            cout << "Please enter an integer: ";
            continue; // Repeats the while loop
        };
    }
}

int main()
{
    int screenTime = 0;
    int studyTime = 0;

    // Intro
    cout << "Welcome! I am the Wizard of Advice. Be warned, my advice is strict and responses are blunt." << endl;
    cout << "Today I will give you advice based on your average daily screen and study time." << endl;
    cout << endl;

    // Receives user's input, using above function for int validation
    cout << "Please enter your average daily screen time: ";
    screenTime = reqIntFromUser();
    cout << "Please enter your average daily study time: ";
    studyTime = reqIntFromUser();

    cout << endl;

    // Returns a response based on user's input
    if (screenTime <= 2 && studyTime >= 6)
    {
        cout << "You need to socialize with people more often." << endl;
    }
    else if (screenTime > 2 && studyTime >= 6)
    {
        cout << "You need to socialize with people more often and get off that phone." << endl;
    }
    else if (screenTime <= 2 && studyTime >= 2)
    {
        cout << "You manage your time well." << endl;
    }
    else if (screenTime > 2 && studyTime < 6)
    {
        cout << "What are you going to do if you lose that phone? It is interfering with your ability to have a real life." << endl;
    }

    // Using a ternary operator
    /*
    string advice;
    (screenTime <= 2 && studyTime >= 6)   ? advice = "You need to socialize with people more often."
    : (screenTime > 2 && studyTime >= 6)  ? advice = "You need to socialize with people more often and get off that phone."
    : (screenTime <= 2 && studyTime >= 2) ? advice = "You manage your time well."
    : (screenTime > 2 && studyTime < 6)   ? advice = "What are you going to do if you lose that phone? It is interfering with your ability to have a real life."
                                          : advice = "I have no words";
    cout << advice << endl;
    */
}