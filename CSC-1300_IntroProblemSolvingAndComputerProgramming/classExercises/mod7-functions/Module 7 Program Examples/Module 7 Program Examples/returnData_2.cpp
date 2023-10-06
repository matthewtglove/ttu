/*********************************************
	Title: 		returnData_2.cpp
	Author:  	April R Crockett
	Date:  		February1 9, 2009
	Purpose:  	This program uses a function 
				that returns a value.
**********************************************/

#include <iostream>
using namespace std;

// Function prototype
int sum(int, int);

int main()
{
   int value1 = 20, value2 = 40;  

   // Print out the sum   
   cout << "The sum of " << value1 << " and ";
   cout << value2 << " is " << sum(value1, value2);
		
   return 0;
}

/**********************************************************
	Function Name:  	sum()
	Function Purpose:	Uses two parameters: num1 and num2. 
						The function adds & returns the 
						sum of num1 + num2
***********************************************************/
int sum(int num1, int num2)
{
	return (num1+num2);
}





