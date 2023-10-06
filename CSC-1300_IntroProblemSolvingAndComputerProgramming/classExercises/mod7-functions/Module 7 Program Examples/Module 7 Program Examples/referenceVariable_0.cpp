/*
	File:    referenceVariable_0.cpp
	Author:  April R Crockett
	Date:    10/13/2022
	Purpose: Demonstrate purpose and syntax
	         of using reference variables
*/
#include <iostream>
using namespace std;

//function prototypes
void getDimensions(double&, double&);
double calculateArea(double, double);

int main()
{
	double length, width, area;
	
	//get data from user
	getDimensions(length, width);
	
	//calculate area
	area = calculateArea(length, width);
	
	//print results
	cout << "\nThe area of the rectangle with length " << length
	     << "and width " << width << " is " << area << endl << endl;
		 
	return 0;
}

/*
	Function: getDimensions
	Purpose:  get the length & width of a rectangle from the user
*/
void getDimensions(double& len, double& wid)
{
	cout << "\nWhat is the length of the rectangle? ";
	cin >> len;
	while(len <= 0)
	{
		cout << "\nSorry, you must enter a positive value.";
		cout << "\nWhat is the length of the rectangle? ";
		cin >> len;
	}
	cout << "\nWhat is the width of the rectangle? ";
	cin >> wid;
	while(wid <= 0)
	{
		cout << "\nSorry, you must enter a positive value.";
		cout << "\nWhat is the width of the rectangle? ";
		cin >> wid;
	}
}

/*
	Function: calculateArea
	Purpose:  calculate the area of a rectangle
*/
double calculateArea(double len, double wid)
{
	return len * wid;
}





