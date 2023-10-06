/*********************************************
	Title: 		referenceVariable_2.cpp
	Author:  	April R Crockett
	Date:  		February1 9, 2009
	Purpose:  	This program uses reference
				variables as a funciton 
				parameters.
**********************************************/

#include <iostream>
using namespace std;

// Function prototypes. 
//Both functions use reference variables as parameters.
void doubleNum(int &);
void getNum(int &);

int main()
{
	int value;

	// Get a number and store it in value.
	getNum(value);

	// Double the number stored in value.
	doubleNum(value);

	// Display the resulting number.
	cout << "That value doubled is " << value << endl;
	
	return 0;
}

/**********************************************************
	Function Name:  	getNum()
	Function Purpose:	The parameter userNum is a 
						reference variable.  The user is
						asked to enter a number, which is
						stored in userNum.
***********************************************************/
void getNum(int &userNum)
{
   cout << "Enter a number: ";
   cin >> userNum;
}

/**********************************************************
	Function Name:  	doubleNum()
	Function Purpose:	The parameter refVar is a 
						reference variable.  The value
						refVar is doubled.
***********************************************************/
void doubleNum (int &refVar)
{
   refVar *= 2;
}

