/********************************************************
 *	Title:  	lab2c.cpp								*
 *	Date:		8/20/2023								*
 *	Author:		Trey Gannod and Matthew Love            *
 *	Purpose:	Demonstarte string variables and output *
 ********************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() 
{
	string firstName1;
	string lastName1;
	string firstName2;
	string lastName2;

	// Gets two full names to generate combinations of the names a married couple
	cout << "What is the first person's first name?" << endl;
	getline(cin, firstName1);
	cout << "What is the first person's last name?" << endl;
	getline(cin, lastName1);

	cout << "What is the second person's first name?" << endl;
	getline(cin, firstName2);
	cout << "What is the second person's last name?" << endl;
	getline(cin, lastName2);

	// Prints all possible combinations of last names for married couples
	cout << "Here are some common married-couple names:" << endl;
	cout << firstName1 << " " << lastName1 << " and " << firstName2 << " " << lastName2 << endl;
	cout << firstName1 << " and " << firstName2 << " " << lastName1 << endl;
	cout << firstName1 << " and " << firstName2 << " " << lastName2 << endl;
	// Print two hyphenated last name options, with either last name appearing first. (A hyphen can be written as "-")
	cout << firstName1 << " " << lastName1 << " and " << firstName2 << " " << lastName1 << "-" << lastName2 << endl;
	cout << firstName1 << " " << lastName1 << " and " << firstName1 << " " << lastName2 << "-" << lastName2 << endl;

	return 0;
}