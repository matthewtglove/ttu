/*********************************************
	Title: 		returnData_1.cpp
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
   int value1 = 20, value2 = 40, total;  

   // Call the sum function, passing the contents of
   // value1 and value2 as arguments. Assign the return
   // value to the total variable.
   total = sum(value1, value2);

   // Display the sum of the values.
   cout << "The sum of " << value1 << " and ";
   cout << value2 << " is " << total << endl;
		
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
	int t;
	t = num1+num2;
	return t;
}





