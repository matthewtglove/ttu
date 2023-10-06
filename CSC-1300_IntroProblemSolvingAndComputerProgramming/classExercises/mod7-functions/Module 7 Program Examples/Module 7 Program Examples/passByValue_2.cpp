/*********************************************
	Title: 		passByValue_2.cpp
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
   cout << "I am passing several values to displayValue.\n";
   displayValue(5);  // Call displayValue with argument 5
   displayValue(10); // Call displayValue with argument 10
   displayValue(2);  // Call displayValue with argument 2
   displayValue(16); // Call displayValue with argument 16
   cout << "Now I am back in main.\n";
   return 0;
}

/**********************************************************
	Function Name:  	displayValue()
	Function Purpose:	Uses an integer parameter whose 
						value is displayed. 
***********************************************************/
void displayValue(int num)
{
   cout << "The value is " << num << endl;
}

