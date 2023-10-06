/*********************************************
	Title: 		return_1.cpp
	Author:  	April R Crockett
	Date:  		February1 9, 2009
	Purpose:  	This program uses a function 
				to perform division. If 
				division by zero is detected, 
				the function returns.
**********************************************/
#include <iostream>
using namespace std;

// Function prototype.
void divide(double, double);

int main()
{
   double num1, num2;

   cout << "Enter two numbers and I will divide the first\n";
   cout << "number by the second number: ";
   cin >> num1 >> num2;
   divide(num1, num2);
   return 0;
}

/**********************************************************
	Function Name:  	divide()
	Function Purpose:	Uses two parameters: arg1 and arg2. 
						The function divides arg1 by arg2 
						and shows the result. If arg2 is 
						zero, however, the function returns.
***********************************************************/
void divide(double arg1, double arg2)
{
   if (arg2 == 0.0)
   {
      cout << "Sorry, I cannot divide by zero.\n";
      return;  //makes the function immediately end
   }
   cout << "The quotient is " << (arg1 / arg2) << endl;
}

