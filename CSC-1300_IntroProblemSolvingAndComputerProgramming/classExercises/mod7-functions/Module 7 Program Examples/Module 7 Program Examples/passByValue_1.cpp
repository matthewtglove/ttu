/*********************************************
	Title: 		passByValue_1.cpp
	Author:  	April R Crockett
	Date:  		February1 9, 2009
	Purpose:  	To demonstrate a function with
				a parameter.  Data is passed
				by value.
**********************************************/
#include <iostream>
using namespace std;

// Function Prototype
void displayValue(int);

int main()
{
   cout << "I am passing 5 to displayValue by value.\n";
   displayValue(5);  // Call displayValue with argument 5
   cout << "Now I am back in main.\n";
   return 0;
}

/**********************************************************
	Function Name:  	displayValue()
	Function Purpose:	Uses an integer parameter whose 
						value is displayed. 
***********************************************************/
void displayValue(int num) //num is a parameter
{
   cout << "The value is " << num << endl;
}







