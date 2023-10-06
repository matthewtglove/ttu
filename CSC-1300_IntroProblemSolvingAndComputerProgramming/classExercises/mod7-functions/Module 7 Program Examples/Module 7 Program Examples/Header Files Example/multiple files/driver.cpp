/*********************************************************************************
	Title:  	driver.cpp
	Author:  	April Crockett
	Date:		10/20/2021
	
	Purpose:  	To demonstrate using reference variables in a program
				and also to demonstrate taking a single source
				file and breaking it into several source
				files and a header file.
				
				The driver contains the main function
				
				For more information on header files, GeeksforGeeks
				has a good article:
				https://www.geeksforgeeks.org/header-files-in-c-cpp-and-its-uses/
*********************************************************************************/

//we must include the header file here and since it is a file on our
//local computer, we use double quotes to enclose the filename instead of < >
#include "referenceVars.h"

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