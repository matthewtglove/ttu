/*
	Title:  charArrays_2.cpp
	Author:  Gaddis, modified by Crockett
	Date:  8/2/2017
	Purpose:  This program has a partially initialized array.
*/
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	string myName = "April";
	string anotherName = "NotApril";

	

	int arrayName[] = {2, 4, 6, 7, 3, 9};
	
	if(myName == anotherName)
		cout << "\n\nSAME!\n\n";
	else
		cout << "\n\nmyName & anotehrName strings are not the same.\n";
	
	char name[100] = "Ruth";
	char anotherAnotherName[] = "Ruth";
	
	strncpy(name, "Ralph", 3);
	cout << name;
	
	//char A[50] = "Thank God It\'s";
	//char B[50] = " Friday";
	
	//strncpy(A,B,3);
	//cout << "\nA:  " << A;
	//cout << "\nB:  " << B;
	
	if(name == anotherAnotherName)
		cout << "\n\nSAME!\n\n";
	else
		cout << "\n\nname & anotherAnotherName c-strings are not the same.\n";
	
	if(strcmp(name,anotherAnotherName) == 0)
		cout << "\n\nSAME!\n\n";
	
	strncat(name, " Smith", 4);
	strcat(anotherAnotherName, " Smith");

	//demonstrate that the array elements are not printed out with single cout statement
	//unless it is a c-string
	cout << arrayName << endl;
	cout << name << endl;
	
	cout << "\nThe length of name is " << strlen(name) << endl;
	

	for(int x=0; x<5; x++)
		cout << arrayName[x] << endl;

	//this will work for c-strings too
	for(int x=0; x<5; x++)
		cout << name[x] << endl;
	
	return 0;
}







