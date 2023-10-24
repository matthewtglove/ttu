/*
	Title: strlenPrac.cpp
	Author:  April Crockett
	Date:  8/2/2017
	Purpose:  demonstrate the c-string function strlen
*/
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char name[50] = "Bram Crockett";
	int length;
	
	length = strlen(name);
	cout << "The length of " << name << " is: " << length << endl;
	
	length = strlen("Cletus Yella Cat Crockett");
	cout << "The length of Cletus Yella Cat Crockett is: " << length << endl;
	
	strncpy(name, "Jill", 1);
	
	cout << "\nI copied this " << name << endl;
	
	
	strcat(name, " Ross");
	
	cout << name << " is painting a happy little tree.\n";
	
	char name2[] = "Bob Ross";
	
	if(strcmp(name, name2) == 0)
	{
		cout << "\nThe strings are the same.\n";
	}
	else
		cout << "\nThe strings are not the same.\n";
	
	return 0;
}










