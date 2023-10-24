/*******************************************************************
	Title:   Functions.cpp
	Author:  April R. Crockett
	Date:    October 20, 2023
	Purpose: This program allows the user to enter in
	         10 elephant's names and consumption of each elephant
	         per month.  The program finds & prints the total
	         and average number of pounds eaten by all the 
			 elephants as well as the name & consumption amount of
	         the elephant that eats the most.
********************************************************************/
#include Elephant.h"

void getElephantData(float food, string names)
{
	cout << "\n\nEnter the name and how many pounds of food each elephant ate last month.\n";
	for(int i=0; i<=SIZE; i++)
	{
		cout << "ELEPHANT " << i+1 << ":\n";
		cout << "\tNAME - ";
		getline(cin, names[i]);
		cout << "\tFOOD AMOUNT - ";
		cin >> food[i];
	}
}

void getStats()
{
	float highestAmt = 0.0;
	highestIndex = 0;
	total = 0.0;
	for(int i=0; i<SIZE; i++)
	{
		if(food[i] < highestAmt)
		{
			highestAmt = food[i];
			highestIndex = i;
		}
	}
	average = total/SIZE;
}