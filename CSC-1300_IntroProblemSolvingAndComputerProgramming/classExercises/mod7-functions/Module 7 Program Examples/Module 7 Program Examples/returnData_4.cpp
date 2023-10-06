/*********************************************
	Title: 		returnData_4.cpp
	Author:  	April R Crockett
	Date:  		February1 9, 2009
	Purpose:  	This program converts cups 
				to fluid ounces.
**********************************************/
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void showIntro();
double getCups();
double cupsToOunces(double);

int main()
{
   // Variables for the cups and ounces.
   double cups, ounces;

   // Set up numeric output formatting.
   cout << fixed << showpoint << setprecision(1);

   // Display an intro screen.
   showIntro();

   // Get the number of cups.
   cups = getCups();

   // Convert cups to fluid ounces.
   ounces = cupsToOunces(cups);

   // Display the number of ounces.
   cout << cups << " cups equals " << ounces << " ounces.\n";

   return 0;
}

/**********************************************************
	Function Name:  	showIntro()
	Function Purpose:	displays introduction
***********************************************************/
void showIntro()
{
	cout 	<< "This program converts measurements\n"
			<< "in cups to fluid ounces. For your\n"
			<< "reference the formula is:\n"
			<< "    1 cup = 8 fluid ounces\n\n";
}

/**********************************************************
	Function Name:  	getCups()
	Function Purpose:	This function prompts the user to
						enter the # of cups and then
						returns that value as a double.
***********************************************************/
double getCups()
{
	double numCups;

	cout << "Enter the number of cups: ";
	cin >> numCups;
	return numCups;
}

/**********************************************************
	Function Name:  	cupsToOunces()
	Function Purpose:	This function accepts a number of
						cups as an argument and returns
						the equivalent number of fluid
						oz as a double.
***********************************************************/
double cupsToOunces(double numCups)
{
	return numCups * 8.0;
}

