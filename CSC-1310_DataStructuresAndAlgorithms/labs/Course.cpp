/*
    Lab: Lab 1
    Author: Matthew Love
    Date: 2024-01-24, Wed
    Purpose: Creating a structure with functions
*/

#include "Course.h"

Course *createCourse(string name, string location, int numSections, int numCredits)
{
    Course *pNewCourse;
    pNewCourse = new Course;
    pNewCourse->name = name;
    pNewCourse->location = location;
    pNewCourse->numSections = numSections;
    pNewCourse->numCredits = numCredits;

    pNewCourse->pSections = new string[numSections];

    // Fill out the sections

    return pNewCourse;
}

Course *destroyCourse(Course *myCourse)
{
    delete[] myCourse->pSections;
    delete myCourse;
}

Course *printCourse(Course *myCourse)
{
    cout << "Course name: " << myCourse->name << endl;
    cout << "Course location: " << myCourse->location << endl;
    cout << "Course credit hours: " << myCourse->numCredits << endl;
    for (int i = 0; i < myCourse->numSections; i++)
    {
        cout << "Course sections: " << myCourse->pSections[i] << endl;
    }
}
