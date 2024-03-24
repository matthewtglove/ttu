/*
	Title:  functionTemplates.cpp
	Author: April Crockett
	Date:  8/14/2017
	Purpose:  To demonstrate function templates
*/
#include <iostream>
using namespace std;

template<typename Llama>
void getData(Llama scores[], int size)
{
	// Loop counter
	int index;

	// Get each test score.
	for(index = 0; index < size; index++)
	{
		cout << "Enter score number " << (index + 1) << ": ";
		cin >> scores[index];
	}
}

template<typename Llama>
Llama getTotal(const Llama array[], int size)
{
	Llama total = 0; // Accumulator

	// Add each element to total.
	for (int count = 0; count < size; count++)
		total += array[count];

	// Return the total.
	return total;
}

template<typename Llama>
Llama getLowest(const Llama array[], int size)
{
	Llama lowest;  // To hold the lowest value

	// Get the first array's first element.
	lowest = array[0];

	// Step through the rest of the array. When a
	// value less than lowest is found, assign it
	// to lowest.
	for (int count = 1; count < size; count++)
	{
		if (array[count] < lowest)
			lowest = array[count];
	}

	// Return the lowest value.
	return lowest;
}

template<typename Llama>
Llama getHighest(const Llama array[], int size)
{
	Llama highest;  // To hold the highest value

	// Get the first array's first element.
	highest = array[0];

	// Step through the rest of the array. When a
	// value less than highest is found, assign it
	// to highest.
	for (int count = 1; count < size; count++)
	{
		if (array[count] > highest)
			highest = array[count];
	}

	// Return the highest value.
	return highest;
}


int main()
{
	const int TEST_SIZE = 4;
	const int GAME_SIZE = 10;
	double 	testScores[TEST_SIZE],total, lowest, highest, avg;
	int		gameScores[GAME_SIZE], totalInt, lowestInt, highestInt;
	
	//first do the test scores array
	getData(testScores, TEST_SIZE);
	total = getTotal(testScores, TEST_SIZE);
	avg = total / TEST_SIZE;
	lowest = getLowest(testScores, TEST_SIZE);
	highest = getHighest(testScores, TEST_SIZE);
	cout << "\n\n\tTOTAL: " << total << endl;
	cout << "\tAVERAGE: " << avg << endl;
	cout << "\tLOWEST: " << lowest << endl;
	cout << "\tHIGHEST: " << highest << endl << endl;
	
	//next do the game scores array
	getData(gameScores, GAME_SIZE);
	totalInt = getTotal(gameScores, GAME_SIZE);
	avg = static_cast<double>(totalInt) / GAME_SIZE;
	lowestInt = getLowest(gameScores, GAME_SIZE);	
	highestInt = getHighest(gameScores, GAME_SIZE);
	cout << "\n\n\tTOTAL: " << totalInt << endl;
	cout << "\tAVERAGE: " << avg << endl;
	cout << "\tLOWEST: " << lowestInt << endl;
	cout << "\tHIGHEST: " << highestInt << endl << endl;

	return 0;
}

