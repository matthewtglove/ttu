/**********************************************************
	Title: 		mod9c_given.cpp
	Author:  	April Crockett (Edited by Matthew Love)
	Date:  		10/25/2022 (Edited on 11/5/2023)
	Purpose:   	This program practices pointers, arrays,
				and functions
**********************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void getAnimals(string *);
void printAnimals(string *);
void sortStrings(string *);

const int SIZE = 5;

int main()
{
	string animalsArray[SIZE];
	// Get the user's favorite animals
	getAnimals(animalsArray);

	// Display animals
	printAnimals(animalsArray);

	return 0;
}

/*
	getAnimals - gets user's data and stores in array
*/
void getAnimals(string *animalsArray)
{
	cout << "\n\nPlease enter your favorite animals:\n";
	for (int i = 0; i < SIZE; i++)
	{
		cout << "ANIMAL " << i + 1 << ": ";
		getline(cin, *(animalsArray + i));
	}
	cout << endl;
}

/*
	sort - first calls the sort function to sort the array
	and then prints the string array.
*/
void printAnimals(string *inputArray)
{
	// call the function to sort the animals in alphabetical ascending order
	sortStrings(inputArray);

	cout << "\nHere are your favorite animals printed back out:\n";
	for (int i = 0; i < SIZE; i++)
		cout << "ANIMAL " << i + 1 << ": " << *(inputArray + i) << endl;
}

/*
	YOU WILL NOT NEED TO MODIFY THIS FUNCTION!!
	sortStrings - sorts an array of strings in alphabetical
	ascending order using the insertion sort
	algorithm
*/
void sortStrings(string *arr)
{
	int i, j;
	string key;
	for (i = 1; i < SIZE; i++)
	{
		key = *(arr + i);
		j = i - 1;

		/* Move elements of arr[0..i-1], that are greater than
			the key, to one position ahead of their current position
			to move them out of the way for the insert
		*/
		while (j >= 0 && *(arr + j) > key)
		{
			*(arr + (j + 1)) = *(arr + j);
			j = j - 1;
		}
		*(arr + (j + 1)) = key;
	}
}
