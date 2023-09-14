/*
    Title: lab3a.cpp
    Author: Matthew Love
    Date: 2023-09-12, Tue
    Purpose: Receive the user's screen and study time then return advice
*/

#include <iostream>
using namespace std;

/*
TODO:
- Validate user input
-

*/
int main()
{
    int screenTime;
    int studyTime;

    // Intro
    cout << "Welcome! I am the Wizard of Advice. Be warned, my advice is strict and responses are blunt." << endl;
    cout << "Today I will give you advice based on your average daily screen and study time." << endl;
    cout << endl;

    // Receives user's input
    cout << "Please enter your average daily screen time: ";
    cin >> screenTime;
    cout << "Please enter your average daily study time: ";
    cin >> studyTime;

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