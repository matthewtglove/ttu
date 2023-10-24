/*
	Title:  strcatPrac.cpp
	Author: April Crockett
	Date:  8/2/2017
	Purpose:  demonstrate the c-string funciton strcat & strncat
*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char str1[70] = "April Crockett, "; //must be large enough to hold all three strings + null terminator (16+16+36+1)
	char str2[55] = "Dwight Schrute, "; //must be large enough to hold string 2 & 3 + null terminator (16+36+1)
	char str3[40] = "and Cosmo Kramer are awesome people."; //must be large enough to hold string 3 + null terminator (36+1)
	
	cout << endl;
	
	if(sizeof(str2) >= (strlen(str2) + strlen(str3) + 1))  //make sure str2 can hold str2 & str3
	{
		strcat(str2, str3);
	
		if(sizeof(str1) >= (strlen(str1) + strlen(str2) + 1)) //make sure str1 can hold str1 & str2
		{
			strcat(str1, str2);
			cout << str1 << endl;
			
			strcpy(str1, "Seinfeld, Heroes, House, and Star Trek are great TV shows!");
			cout << str1 << endl;
		}
		else
			cout << "str1 is not large enough for all three strings.\n";
	}
	else
		cout << "str2 is not large enough for str2 & str3.\n";
		
	cout << endl << endl;
	char str4[75] = "I call your name "; //must be large enough to hold all three strings + null terminator (17+21+32+1)
	char str5[55] = "but you'r not there. "; //must be large enough to hold string 2 & 3 + null terminator (21+32+1)
	char str6[35] = "Was I to blame for being unfair?"; //must be large enough to hold string 3 + null term
	
	strncat(str5, str6, 34);
	strncat(str4, str5, 54);
	cout << str4 << endl;
			
	strncpy(str4, "Oh I can't sleep at night, since you've been gone. I never Weep at night. I can't go on.", 74);
	cout << str4 << endl << endl;
	
	char str7[25] = "since you've been gone";
	
	
	cout << endl;
	
	
	return 0;
}
