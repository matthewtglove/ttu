// A C++ program to demonstrate common Binary Heap Operations
#include<iostream>
#include<cmath> 			//used for log2 & ceil
using namespace std;
 
// A class for Min Heap
class ArrayMinHeap
{
	private:
		int *heapArray; 	// pointer to array of elements in heap
		int capacity; 		// maximum possible size of min heap
		int heap_size; 		// Current number of elements in min heap
		
		void swap(int *x, int *y)
		{
			int temp = *x;
			*x = *y;
			*y = temp;
		}			
		
		int parent(int i) 			//get the parent of index i
		{ 
			return (i-1)/2; 
		}
		int left(int i) 			//get the left child of index i
		{ 
			return (2*i + 1); 
		}
		int right(int i) 			//get the right child of index i
		{ 
			return (2*i + 2); 
		}
		
	public:
		
		ArrayMinHeap(int capacity);	// Constructor
		~ArrayMinHeap();			// Destructor
		
		void minHeapify(int);		// heapify a subtree with root at given index
		
	 	int peek() 					// Returns root (minimum value)
		{ 
			if(isEmpty())
			{
				cout << "Error:  there is no nodes in the heap.\n";
				return -1;
			}
			else
				return heapArray[0]; 
		}
		
		int remove();				// remove the root (minimum element)
		
		void insert(int);			// Inserts a new node with value
		
		void resizeArray();			// Resizes array to twice capacity
		
		bool isEmpty()
		{
			if(heap_size == 0)
				return true;
			else
				return false;
		}
		
		int getNumberOfNodes()
		{
			return heap_size;
		}
		
		int getHeight()
		{
			/*
				ceil(x) - a cmath function that returns the value of x rounded up 
							Example:  ceil(2.3) is 3.0
							Example:  ceil(3.8) is 4.0
							Example:  ceil(-2.3) is 2.0
							Example:  ceil(-3.8) is -3.0
				log2(x) - a cmath function that returns the base-2 logarithm of x
							Example:  log2 (1024.000000) = 10.000000
			*/
			return ceil(log2(heap_size + 1));
		}
		

};
 

ArrayMinHeap::ArrayMinHeap(int cap)			// Constructor: Builds a heap from a given array a[] of given size
{
	heap_size = 0;
	capacity = cap;
	heapArray = new int[cap];
}

ArrayMinHeap::~ArrayMinHeap()
{
	delete [] heapArray;
}
 
void ArrayMinHeap::insert(int newValue)
{
	if (heap_size == capacity)
	{
		resizeArray();	//double the size of array & capacity
	}

	// First insert the new value at the end
	heapArray[heap_size] = newValue;
	heap_size++;
	int i = heap_size - 1;

	// Fix the min heap property if it is violated
	while (i != 0 && heapArray[parent(i)] > heapArray[i])
	{
		swap(&heapArray[i], &heapArray[parent(i)]);
		i = parent(i);
	}
}

void ArrayMinHeap::resizeArray()	//make an array 2 times as big as original
{
	int cap = capacity * 2; 
	int *newHeapArray = new int[cap];
	
	for(int x = 0; x < capacity; x++)
	{
		newHeapArray[x] = heapArray[x];
	}
	delete [] heapArray;
	heapArray = newHeapArray;
	capacity = cap;
}
 
// Method to remove minimum element (or root) from min heap
int ArrayMinHeap::remove()
{
    if (heap_size == 0)
	{
		cout << "Error:  there is no nodes in the heap.\n";
		return -1;
	}
    else if (heap_size == 1)
    {
        heap_size--;
        return heapArray[0];
    }

    int root = heapArray[0]; 				//remove the root (which will be returned from this function)
    heapArray[0] = heapArray[heap_size-1];	//take last element in array and move to first element (step 2 in remove process)
    heap_size--;							//reduce size of heap
    minHeapify(0);							//adjust heap - shift elements down as needed(step 3 in remove process)
    return root;
}
 
// A recursive method to adjust the heap to make sure all nodes follow the min-heap rule
void ArrayMinHeap::minHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && heapArray[l] < heapArray[i])
        smallest = l;
    if (r < heap_size && heapArray[r] < heapArray[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&heapArray[i], &heapArray[smallest]);
        minHeapify(smallest);
    }
}






















 