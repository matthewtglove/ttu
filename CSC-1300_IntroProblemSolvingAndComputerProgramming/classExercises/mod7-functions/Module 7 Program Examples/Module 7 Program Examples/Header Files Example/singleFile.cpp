/*********************************************************************************
	Title:  	singleFile.cpp
	Author:  	April Crockett
	Date:		10/20/2021
	
	Purpose:  	To demonstrate using reference variables in a program
				and also to demonstrate taking a single source
				file and breaking it into several source
				files and a header file.
				
				For more information on header files, GeeksforGeeks
				has a good article:
				https://www.geeksforgeeks.org/header-files-in-c-cpp-and-its-uses/
*********************************************************************************/


#include <iostream>
using namespace std;

// Function Prototypes
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

