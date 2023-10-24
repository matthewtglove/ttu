/*
	Title:   charAssignment.cpp
	Author:  April Crockett
	Date:  	 5/6/2022
	Purpose: This program shows that character assignment will not work
				and what you should do instead.
*/
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char fullName[25];
	
	//assignment - will not work - syntax error
	fullName = "Bob Ross";
	
	//must use a c-string function instead called string copy strcpy()
	strcpy(fullname, "Bob Ross");	
}







