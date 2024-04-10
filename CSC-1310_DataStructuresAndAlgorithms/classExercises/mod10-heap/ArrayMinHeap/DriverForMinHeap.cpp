// A C++ program to demonstrate common Binary Heap Operations
#include <iostream>
#include "ArrayMinHeap.h"
using namespace std;
 
int main()
{
    ArrayMinHeap myHeap(2);
		
    myHeap.insert(3);
	cout << "\n\nInserted " << myHeap.peek() << endl;
	
	cout << "\nNow inserting 2, 15, 5, 4, and 45.\n";
	
    myHeap.insert(2);
    myHeap.insert(15);
    myHeap.insert(5);
    myHeap.insert(4);
    myHeap.insert(45);
	
	//                    2
	//					/   \
	//				   3     15
	//                / \   / 
	//               5   4 45 

	
	cout << "\nThere are now " << myHeap.getNumberOfNodes() << " nodes in the heap.\n";
	cout << "The height of the heap is " << myHeap.getHeight() << ".\n\n";
	
	cout << "Now removing the minimum value, which is " << myHeap.remove() << ".\n"; //2
	//                    3
	//					/   \
	//				   4     15
	//                / \    
	//               45  5  	
	
	cout << "Now removing the next minimum value, which is " << myHeap.remove() << ".\n"; //3
	//                    4
	//					/   \
	//				   5     15
	//                /     
	//               45 
   	
	cout << "Now removing the next minimum value, which is " << myHeap.remove() << ".\n"; //4
	//                    5
	//					/   \
	//				   45    15    	
	
	
	cout << "\nThere are now " << myHeap.getNumberOfNodes() << " nodes in the heap.\n";
	
	cout << "The height of the heap is " << myHeap.getHeight() << ".\n\n";
	
    return 0;
}