/*********************************************
	Title: 		passByValue_4.cpp
	Author:  	April R Crockett
	Date:  		February1 9, 2009
	Purpose:  	This program demonstrates that 
				changes to a function 
				parameter that is passed by 
				value have no affect on the 
				original argument.
**********************************************/
#include <iostream>
using namespace std;

// Function Prototype
void changeMe(int);

int main()
{
   int number = 12;

   // Display the value in number.
   cout << "number is " << number << endl;
   
   // Call changeMe, passing the value in number
   // as an argument.
   changeMe(number);
   
   // Display the value in number again.  
   cout << "Now back in main again, the value of ";
   cout << "number is " << number << endl;
   return 0;
}
void changeMe(int number)
{
   // Change the value of myValue to 0.
   number = 0;
   
   // Display the value in myValue.
   cout << "Now the value is " << number << endl;
}