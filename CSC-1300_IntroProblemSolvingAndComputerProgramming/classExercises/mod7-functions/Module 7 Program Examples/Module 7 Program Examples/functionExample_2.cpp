/*********************************************
	Title:  	functionExample_2.cpp
	Author: 	April Crockett
	Date:  		9/14/2014
	Purpose:	to demonstrate calling 
				functions
**********************************************/
#include <iostream>
using namespace std;

//will this work?

int main()
{
   cout << "Hello from main.\n";
   displayMessage(); //function call statement
   cout << "Back in function main again.\n";
   
   return 0;
} 

void displayMessage()
{
   cout << "Hello from the function displayMessage.\n";
}

/*
	NOTE:  The compiler must know the following 
	about a function BEFORE it is called:
	-	function name
	-	return type
	-	number of parameters
	-	data type of each parameters
*/