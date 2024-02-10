#include <iostream>
using namespace std;

void displayArray(int*, int);
void quickSort(int*, int, int);
int partition(int*, int, int);
void swap(int& one, int& two);

int main()
{
	const int SIZE = 5;
	int myArr[SIZE] = {85, 42, 7, 186, 18};
	
	//display the array
	cout << endl << endl;
	displayArray(myArr, SIZE);
	cout << endl;
	//sort the array
	quickSort(myArr, 0, SIZE-1);
	//display the array
	cout << endl;
	displayArray(myArr, SIZE);
	cout << endl << endl;
	
	return 0;
}

void quickSort(int *arr, int low, int high) 
{
	int pivot_location = 0;

	/* Base case: If there are 1 or zero elements to sort,
	partition is already sorted */
	if (low >= high) {
		return;
	}

	/* Partition the data within the array. */
	pivot_location = partition(arr, low, high); //returns location of last element in low partition
	cout << endl << endl;
	quickSort(arr, low, pivot_location); //recursively sort low partition
	cout << endl << endl;
	quickSort(arr, pivot_location + 1, high); //recursively sort high partition
}

//Hoare Partition algorithm
int partition(int *arr, int left, int right) {

   int pivot, temp;
   
   //pivot starts at left
   pivot = arr[left];
   cout << "\nPivot:  " << pivot;
   int l = left-1;
   int r = right+1;
   cout << "\nLeft:  " << l << " & Right: " << r;
   while(l < r)
   {
	   do{
		   cout << "\nright is larger than pivot, decrement right";
		   r--;
	   } while(arr[r] > pivot);
	   do{
		   cout << "\nleft is smaller than pivot, increment left";
		   l++;
	   }while(arr[l] < pivot);
	  
	   if(l < r)
		swap(arr[l], arr[r]);
   }
   return r;
   
   
}

void swap(int& one, int& two)
{
	cout << "\nSwapping " << one << " & " << two;
	int temp = one;
	one = two;
	two = temp;
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