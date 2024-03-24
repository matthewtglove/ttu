// Implementation file for the StackLinkedList class

#include <iostream>  
#include "StackLinkedList.h"
using namespace std;

// isEmpty returns true if the stack has no nodes and false if it does
bool StackLinkedList::isEmpty()
{
	if(!top)
		return true;
	else
		return false;
}

// getLength returns the number of nodes in the Stack
int StackLinkedList::getLength()
{
	int counter = 0;
	ListNode *nodePtr;
	
	nodePtr = top;
	
	while(nodePtr)
	{
		counter++;
		nodePtr = nodePtr->next;
	}
	return counter;
}

//push this number item on the top of the stack
void StackLinkedList::push(double num)
{
	ListNode *newNode;  // To point to a new node

	// Allocate a new node and store num there.
	newNode = new ListNode;
	newNode->value = num;
	if(!top)
		newNode->next = NULL;
	else
		newNode->next = top;
	
	top = newNode;
}

//remove and return the item on the top of the stack
double StackLinkedList::pop()
{
	ListNode *nodePtr;
	double temp;
	
	if(!top) //if the stack is empty
		return -1;
	else
	{
		nodePtr = top;
		if(top->next != NULL) //then there is another item in the stack
		{
			top = top->next; //top is now the next item in stack
		}
		else
			top = NULL;
		
		temp = nodePtr->value;
		delete nodePtr; //delete the top of the stack
		
		return temp; //return the value that was in the top of the stack
	}
}

//display all stack items
void StackLinkedList::displayStack() const
{
	ListNode *nodePtr;  // To move through the list

	// Position nodePtr at the top of the list.
	nodePtr = top;

	// While nodePtr points to a node, traverse the list.
	while (nodePtr)
	{
		// Display the value in this node.
		cout << nodePtr->value << endl;

		// Move to the next node.
		nodePtr = nodePtr->next;
	}
}

// Destructor -  deletes every node in the stack.  
StackLinkedList::~StackLinkedList()
{
	ListNode *nodePtr;   // To traverse the list
	ListNode *nextNode;  // To point to the next node

	// Position nodePtr at the top of the list.
	nodePtr = top;

	// While nodePtr is not at the end of the list...
	while (nodePtr)
	{
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
	cout << "\n\nDeleted all the nodes in the stack!!\n\n";
}