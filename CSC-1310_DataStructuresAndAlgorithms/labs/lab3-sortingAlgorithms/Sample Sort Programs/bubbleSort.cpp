#include <iostream>
using namespace std;

void displayArray(int*, int);
void bubbleSort(int*, int);

int main()
{
	int myArr[5] = {85, 42, 7, 186, 18};
	
	//display the array
	displayArray(myArr, 5);
	//sort the array
	bubbleSort(myArr, 5);
	//display the array
	displayArray(myArr, 5);
	
	return 0;
}

void bubbleSort(int *arr, int size)
{
	int tempForSwap;
	cout << "\nSorting the array with the Bubble Sort algorithm.\n\n";
	//maxElement will hold the subscript of the last element 
	//that is to be compared to its immediate neighbor
	for(int maxElement=(size-1); maxElement > 0; maxElement--)
	{
		for(int i=0; i<maxElement; i++) //using i for "index"
		{
			//swap the two adjacent elements if the one on the left is greater than the one on the right
			if(arr[i] > arr[i+1]) 
			{
				tempForSwap = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = tempForSwap;
			}
		}
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