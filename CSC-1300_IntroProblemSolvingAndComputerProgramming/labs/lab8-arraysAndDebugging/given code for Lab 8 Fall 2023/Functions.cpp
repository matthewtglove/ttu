/*******************************************************************
	Title:   Functions.cpp
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

// For getting the elephant name and amount of food eaten by it
void getElephantData(float food[], string names[])
{
	cout << "\n\nEnter the name and how many pounds of food each elephant ate last month.\n";
	for (int i = 0; i < SIZE; i++)
	{
		cout << "ELEPHANT " << i + 1 << ":\n";
		cout << "\tNAME - ";
		getline(cin, names[i]);
		cout << "\tFOOD AMOUNT - ";
		cin >> food[i];
		cin.ignore();
	}
}

/*
For generating stats based on input food amounts:
- Total food amount consumed at the zoo
- Average food amount consumed by an elephant
- The array index of the highest food amount
*/
void getStats(float food[], float &total, float &average, int &highestIndex)
{
	float highestAmt = 0.0;
	highestIndex = 0;
	total = 0.0;
	for (int i = 0; i < SIZE; i++)
	{
		if (food[i] > highestAmt)
		{
			highestAmt = food[i];
			highestIndex = i;
		}
		total += food[i];
	}

	average = total / SIZE;
}