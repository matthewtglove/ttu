#include <iostream>
using namespace std;

void displayArray(int*, int);
void selectionSort(int*, int);
void swap(int*, int*);

int main()
{
	int myArr[5] = {85, 42, 7, 186, 18};
	
	//display the array
	displayArray(myArr, 5);
	//sort the array
	selectionSort(myArr, 5);
	//display the array
	displayArray(myArr, 5);
	
	return 0;
}

void selectionSort(int *arr, int size)
{
	int minIndex, minValue;
	cout << "\nSorting the array with the Selection Sort algorithm.\n\n";
	
	for(int start = 0; start < (size-1); start++)
	{
		cout << "\n\nTRAVERSAL NUMBER " << start+1 << "-------------------------------------------------\n";
		minIndex = start;
		minValue = arr[start];
		
		//find the minimum value in the array starting from start and going through the end of the array
		for(int i=start+1; i<size; i++) //using i for "index"
		{
			cout << "Comparing the current minimum (" << minValue << ") with  element at index " << i << " with value " << arr[i] << endl;
			if(arr[i] < minValue) 
			{
				minValue = arr[i];
				minIndex = i;
			}
		}
		cout << "\nThe minimum is " << minValue << " at index " << minIndex;
		cout << "\nSwapping " << arr[minIndex] << " and " << arr[start];
		//now we have the index of the smallest value so swap
		swap(arr[minIndex], arr[start]);
		displayArray(arr, 5);
	}
}

//swap a & b in memory
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	
}


void displayArray(int *arr, int size)
{
	cout << "\n--------------------The array:  ";
	for(int i=0; i<size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "--------------------\n";
}