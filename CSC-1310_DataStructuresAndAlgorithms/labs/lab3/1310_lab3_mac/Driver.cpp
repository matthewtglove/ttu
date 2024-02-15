/*
	LAB 3
	Editor: Matthew Love
	Date: 2024-02-8, Wed
*/

#include "Song.h"
#include "Timer.h"
#include <iostream>
#include <fstream>
using namespace std;

// LOOK!!  ENTER YOUR FUNCTION PROTOTYPES HERE
void insertionSort(Song *array, int size);
void reverseBubbleSort(Song *array, int size);
void quickSort(Song *array, int low, int high);
int partition(Song *array, int left, int right);

int main()
{
	Song *mySongArray;
	mySongArray = new Song[150000];
	int numSongs = 0;
	float length;
	string temp;

	ofstream outFile;
	ifstream inFile;

	time_t start, end;
	char filename[50];
	cout << "\n\nWhat is the name of the file with songs? (example.txt)\n";
	cin >> filename;
	inFile.open(filename);

	if (!inFile)
	{
		cout << "\n\nSorry, I can't open the file songs.txt\n\n";
		exit(1);
	}

	while (getline(inFile, temp) && numSongs != 150000)
	{
		mySongArray[numSongs].setTitle(temp);
		getline(inFile, temp);
		mySongArray[numSongs].setArtist(temp);
		inFile >> length;
		inFile.ignore();
		mySongArray[numSongs].setLength(length);
		numSongs++;
	}
	cout << "\n\nYou have created " << numSongs << " Song objects.\n\n";

	// sort the songs using insertion sort and print them out to the text file sortFileInsertion.txt
	start = getTime(); // Starts timer.

	// LOOK!!!!  CALL THE INSERTION SORT ALGORITHM HERE
	insertionSort(mySongArray, numSongs);

	end = getTime(); // Ends timer.
	outFile.open("sortFileInsertion.txt");
	cout << "\nInsertion sort: " << totalTime(start, end) << " seconds\n\n";
	for (int x = 0; x < numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();

	// sort the songs in reverse order using bubble sort & print them out to the text file sortFileReverseBubble.txt
	start = getTime(); // Starts timer.

	// LOOK!!!!  CALL THE REVERSE BUBBLE SORT ALGORITHM HERE

	end = getTime(); // Ends timer.
	outFile.open("sortFileReverseBubble.txt");
	cout << "\nReverse bubble sort: " << totalTime(start, end) << " seconds\n\n";
	for (int x = 0; x < numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();

	// sort the songs with quick sort & print them out to sortFileQuick.txt
	start = getTime(); // Starts timer.

	// LOOK!!!!  CALL THE QUICKSORT ALGORITHM HERE

	end = getTime(); // Ends timer.
	cout << "\nQuicksort: " << totalTime(start, end) << " seconds\n\n";
	outFile.open("sortFileQuick.txt");
	for (int x = 0; x < numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();

	delete[] mySongArray;
	return 0;
}

// LOOK!  WRITE YOUR INSERTION SORT FUNCTION HERE
void insertionSort(Song *array, int size)
{
	string key;
	string j;

	for (int i = 1; i < size; i++)
	{
		key = array[i].getTitle();
		j = i - 1;
		while (j >= 0 && array[j].getTitle() > key)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
	}
}

// LOOK!  WRITE YOUR REVERSE BUBBLE SORT FUNCTION HERE
void reverseBubbleSort(Song *array, int size)
{
	int tempForSwap;

	// TODO: THe below is Bubble Sort. Change it to be Reverse Bubble Sort
	for (int maxElement = (size - 1); maxElement > 0; maxElement--)
	{
		for (int i = 0; i < maxElement; i++)
		{
			if (array[i] > array[i + 1])
			{
				tempForSwap = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tempForSwap;
			}
		}
	}
}

// LOOK!  WRITE YOUR RECURSIVE QUICK SORT FUNCTION HERE
void quickSort(Song *array, int low, int high)
{
	int pivotLocation = 0;

	if (low >= high)
	{
		return;
	}

	pivotLocation = partition(array, low, high);
	cout << endl
		 << endl;
	quickSort(array, low, pivotLocation);
	cout << endl
		 << endl;
	quickSort(array, pivotLocation + 1, high);
}

// LOOK!  WRITE YOUR PARTITION FUNCTION HERE
int partition(int *array, int left, int right)
{
	int pivot;
	int temp;

	pivot = array[left];
	int l = left - 1;
	int r = right + 1;

	while (l < r)
	{
		do
		{
			r--;
		} while (array[r] > pivot);

		do
		{
			l++;
		} while (array[l] < pivot);

		if (l < r)
		{
			int temp = array[l];
			array[l] = array[r];
			array[r] = array[l];
		}
	}
	return r;
}
