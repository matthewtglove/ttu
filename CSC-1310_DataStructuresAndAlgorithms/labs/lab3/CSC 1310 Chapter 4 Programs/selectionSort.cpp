#include <iostream>
using namespace std;

void displayArray(int*, int);
void selectionSort(int*, int);

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
	int temp;  //temporary variable for swap
	cout << "\nSorting the array with the Selection Sort algorithm.\n\n";
	
	for(int start = 0; start < (size-1); start++)
	{
		minIndex = start;
		minValue = arr[start];
		
		//find the minimum value in the array starting from start and going through the end of the array
		for(int i=start+1; i<size; i++) //using i for "index"
		{
			if(arr[i] < minValue) 
			{
				minValue = arr[i];
				minIndex = i;
			}
		}
		//now we have the index of the smallest value so swap
		temp = arr[minIndex];
		arr[minIndex] = arr[start];
		arr[start] = temp;

	}
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