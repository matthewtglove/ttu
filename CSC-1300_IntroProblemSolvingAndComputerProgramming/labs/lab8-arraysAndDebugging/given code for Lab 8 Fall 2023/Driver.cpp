/*******************************************************************
	Title:   Driver.cpp
	Author:  April R. Crockett - Edited by: Matthew Love
	Date:    October 20, 2023 - Edited on: 2023-10-24, Tue
	Purpose: This program allows the user to enter in
			 10 elephant's names and consumption of each elephant
			 per month.  The program finds & prints the total
			 and average number of pounds eaten by all the
			 elephants as well as the name & consumption amount of
			 the elephant that eats the most.
********************************************************************/
#include "Elephant.h"

int main()
{
	// Character array
	char zooName[100];
	float elephantFood[SIZE];
	string elephantNames[SIZE];
	float total, average;
	int highestIndex;

	cout << "\n\nHello!  What is the name of your elephant zoo?\n";
	// Using a character array
	cin.getline(zooName, 100);

	getElephantData(elephantFood, elephantNames);
	getStats(elephantFood, total, average, highestIndex);

	cout << "-----------------------------------------------------------------";
	cout << "\nThe total amount of food consumed by all " << SIZE << " elephants\nat ";
	cout << zooName << " is " << total << " pounds in one month.\n\n";
	cout << "The average amount of food consumed at\n"
		 << zooName;
	cout << " is " << average << " pounds.";
	cout << "\n\nThe elephant who eats the most (" << elephantFood[highestIndex];
	cout << " pounds) is " << elephantNames[highestIndex];
	cout << "!!\n";
	cout << "-----------------------------------------------------------------";
	cout << "\n\n";
	return 0;
}