/*********************************************
	Title:  	functionExample_3.cpp
	Author: 	April Crockett
	Date:  		9/14/2014
	Purpose:	to demonstrate a function
				prototype
**********************************************/
#include <iostream>
using namespace std;

void displayMessage(); //function prototype

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