/*********************************************
	Title: 		passByValue_3.cpp
	Author:  	April R Crockett
	Date:  		February1 9, 2009
	Purpose:  	To demonstrate a function with
				three parameters.  Data is 
				passed by value.
**********************************************/
#include <iostream>
using namespace std;

// Function Prototype
void showSum(int, int, int);

int main()
{
   int value1, value2, value3;
   
   // Get three integers.
   cout << "Enter three integers and I will display ";
   cout << "their sum: ";
   cin >> value1 >> value2 >> value3;
   
   // Call showSum passing three arguments.
   showSum(value1, value2, value3);
   
   return 0;
}

/**********************************************************
	Function Name:  	showSum()
	Function Purpose:	Uses three integer parameters. 
						Their sum is displayed. 
***********************************************************/
void showSum(int num1, int num2, int num3)
{
   cout << (num1 + num2 + num3) << endl;
}


