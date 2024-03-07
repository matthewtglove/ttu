/*
    Lab: Lab 1
    Author: Matthew Love
    Date: 2024-01-24, Wed
    Purpose: Creating a structure with functions
*/
#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
using namespace std;

struct Course
{
    string name;
    string location;
    string *pSections;
    int numSections;
    int numCredits;
};

Course *createCourse(string name, string location, int numSections, int numCredits);
void destroyCourse(Course *myCourse);
void printCourse(Course *myCourse);

#endif
