/*********************************************************************************
	Title:  	functions.cpp
	Author:  	April Crockett
	Date:		10/20/2021
	
	Purpose:  	All programmer-defined functions are defined in this file.
*********************************************************************************/

//we must include the header file here and since it is a file on our
//local computer, we use double quotes to enclose the filename instead of < >
#include "referenceVars.h"


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

