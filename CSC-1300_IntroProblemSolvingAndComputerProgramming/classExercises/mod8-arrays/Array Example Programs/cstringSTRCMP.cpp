/*
	Title:  cstringSTRCMP.cpp
	Author:  April Crockett
	Date:  8/2/2017
	Purpose:  This program tests two C-strings for equality using the strcmp function.
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
   // Two arrays for two strings.
   const int SIZE = 40;
   char firstString[SIZE], secondString[SIZE];

   // Read two strings.
   cout << "Enter a string: ";
   cin.getline(firstString, SIZE);
   cout << "Enter another string: ";
   cin.getline(secondString, SIZE);

   // Compare the strings for equality with strcmp.
   if (strcmp(firstString, secondString) == 0)
      cout << "You entered the same string twice.\n";
   else
      cout << "The strings are not the same.\n";

   return 0;
}