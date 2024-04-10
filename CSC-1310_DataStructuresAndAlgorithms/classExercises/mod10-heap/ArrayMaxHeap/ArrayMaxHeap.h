#ifndef _ARRAY_MAX_HEAP
#define _ARRAY_MAX_HEAP
#include <cmath> // for log2 & ceil
#include <iostream>
using namespace std;


template<typename ItemType>
class ArrayMaxHeap
{
	private:
						
		ItemType* items;                        // Array of heap items
		int heap_size;                          // Current count of heap items
		int capacity;                           // Maximum capacity of the heap

		void swap(ItemType *x, ItemType *y)
		{
			ItemType temp = *x;
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
		
		
		bool isLeaf(int nodeIndex)	// Tests whether this node is a leaf.
		{
			return (left(nodeIndex) >= heap_size);
		}

		// Converts a semiheap to a heap.
		void heapRebuild(int subTreeRootIndex);

		// Creates a heap from an unordered array.
		void heapCreate();

	public:
		ArrayMaxHeap(int);
		~ArrayMaxHeap();

		bool isEmpty() const;					// Checks to see if the heap is empty

		int getNumberOfNodes() const;			// Gets the number of nodes in this heap.

		int getHeight() const;					// Gets the height of this heap.

		ItemType peek() const;

		void insert(ItemType newData);			//Insert newData in the heap
		
		void resizeArray();

		ItemType remove();						//Remove the root (maximum value) & returns it

}; 

//******************************************************************
// 
// Private functions start here
//
//******************************************************************

template<typename ItemType>
void ArrayMaxHeap<ItemType>::heapRebuild(const int subTreeNodeIndex)
{
	if (!isLeaf(subTreeNodeIndex))
	{
		// Find larger child
		int leftChildIndex = left(subTreeNodeIndex);   	// A left child must exist
		int largerChildIndex = leftChildIndex;         	// Make assumption about larger child
		int rightChildIndex = right(subTreeNodeIndex); 	// A right child might not exist

		// Check to see whether a right child exists
		if (rightChildIndex < heap_size)
		{
			// A right child exists; check whether it is larger
			if (items[rightChildIndex] > items[largerChildIndex])
				largerChildIndex = rightChildIndex;		// Asssumption was wrong
		} 

		// If root value is smaller that the value in the larger child, swap values
		if (items[subTreeNodeIndex] < items[largerChildIndex])
		{
			swap(&items[largerChildIndex], &items[subTreeNodeIndex]);

			// Continue with the recursion at that child
			heapRebuild(largerChildIndex);
		}  
	}  
} 



template<typename ItemType>
void ArrayMaxHeap<ItemType>::heapCreate()
{
   for (int index = heap_size / 2; index >= 0; index--)
   {
      heapRebuild(index);  
   } 
}

//******************************************************************
// 
// Public functions start here
//
//******************************************************************

template<typename ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(int num)
{  
	heap_size = 0;
	capacity = num;
	items = new ItemType[capacity];
}

template<typename ItemType>
ArrayMaxHeap<ItemType>::~ArrayMaxHeap()
{  
   delete [] items;
} 

template<typename ItemType>
bool ArrayMaxHeap<ItemType>::isEmpty() const
{
	if(heap_size == 0)
		return true;
	else
		return false;
} 

template<typename ItemType>
int ArrayMaxHeap<ItemType>::getHeight() const
{
	return ceil(log2(heap_size + 1));
}  

template<typename ItemType>
int ArrayMaxHeap<ItemType>::getNumberOfNodes() const
{
	return heap_size;
}  

template<typename ItemType>
ItemType ArrayMaxHeap<ItemType>::peek() const
{
   return items[0];
} 

template<typename ItemType>
void ArrayMaxHeap<ItemType>::insert(ItemType newData)
{
	if (heap_size == capacity)
	{
		resizeArray();	//double the size of array & capacity
	}
	// First insert the new value at the end
	items[heap_size] = newData;
	heap_size++;

	// Fix the max heap property if it is violated
	int i = heap_size-1;
	while ((i != 0) && (items[parent(i)] < items[i]))
	{
		swap(&items[i], &items[parent(i)]);
		i = parent(i);
	} 
} 

template<typename ItemType>
void ArrayMaxHeap<ItemType>::resizeArray()	//make an array 2 times as big as original
{
	int cap = capacity * 2; 
	ItemType *newHeapArray = new ItemType[cap];
	
	for(int x = 0; x < capacity; x++)
	{
		newHeapArray[x] = items[x];
	}
	delete [] items;
	items = newHeapArray;
	capacity = cap;
}

template<typename ItemType>
ItemType ArrayMaxHeap<ItemType>::remove()
{
	ItemType temp;
	if (!isEmpty()) 
	{
		temp = items[0];						//Store the root value so it can be returned later
		items[0] = items[heap_size - 1];		//Set the root node (first element) to the last element (step 2 in remove process)
		heap_size--;							//Decrement the heap's size
		heapRebuild(0);							//adjust heap - shift elements down as needed(step 3 in remove process)
	}
	else
	{
		cout << "\nThe heap is empty so I can't remove any values.\n";
	}

	return temp;
} 


#endif
