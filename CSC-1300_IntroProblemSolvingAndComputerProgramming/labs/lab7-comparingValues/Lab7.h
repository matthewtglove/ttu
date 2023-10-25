/*
    Title: Lab 7
    Author: Matthew Love
    Date: 2023-10-17, Tue
    Purpose: Check whether two superheros would be compatable as roommates
*/

#ifndef LAB7_H
#define LAB7_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void getData(string &hero1Name, string &hero2Name, int &hero1Age, int &hero2Age, string &hero1Pet, string &hero2Pet);
bool calculateResults(string hero1Name, string hero2Name, int hero1Age, int hero2Age, string hero1Pet, string hero2Pet);

#endif