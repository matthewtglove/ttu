/*********************************************
	Title: 		overloadedFunctions.cpp
	Author:  	April R Crockett
	Date:  		February1 9, 2009
	Purpose:  	This program uses overloaded
				functions
**********************************************/
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
int square(int);
double square(double);

int main()
{
	int userInt;
	double userFloat;

	// Get an int and a double.
	cout << fixed << showpoint << setprecision(2);
	cout << "Enter an integer and a floating-point value: ";
	cin >> userInt >> userFloat;

	// Display their squares.
	cout << "Here are their squares: ";
	cout << square(userInt) << " and " << square(userFloat);
	
	return 0;
}

/**********************************************************
	Function Name:  	square()
	Function Purpose:	This function uses an int parameter
						called number.  It returns the 
						square of number as an int.
***********************************************************/
int square(int number)
{
	return number * number;
}

double square(double number)
{
	return number * number;
}