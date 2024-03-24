/*****************************************************************
	Title:  	LinkedList.cpp - Class Implementation File for 
				LinkedList Class
	Date:  		2-8-2019
	Author: 	April Crockett
	Purpose:	A Doubly-Linked List implemented in a
				LinkedList class that contains a ListNode
				structure variable
******************************************************************/
#include <iostream>  
#include "LinkedList.h"
using namespace std;

// isEmpty returns true if the list has no nodes and false if it does
bool LinkedList::isEmpty()
{
	if(!head)
		return true;
	else
		return false;
}

int LinkedList::getLength()
{
	int counter = 0;
	ListNode *nodePtr;
	
	nodePtr = head;
	
	//list traversal
	while(nodePtr != tail)
	{
		counter++;
		nodePtr = nodePtr->next;
		if (nodePtr == tail)
			counter++;
	}
	return counter;
}

//returns the node value at a given integer position
double LinkedList::getNodeValue(int position)
{
	ListNode *nodePtr;
	if(!head)
		return -1;
	else
	{
		if(position == 0)
			return head->value;
		nodePtr = head;
		int currentPos = 0;
		
		//list traversal
		while(nodePtr != NULL && position >= currentPos)
		{
			if(position == currentPos)
				return nodePtr->value;
			currentPos++;
			nodePtr = nodePtr->next;				
		}
	}
	return -1;
}
//**************************************************
// appendNode appends a node containing the        *
// value passed into num, to the end of the list.   *
//**************************************************
void LinkedList::appendNode(double num)
{
	ListNode *newNode;  // To point to a new node
	ListNode *nodePtr;  // To move through the list

	// Allocate a new node and store num there.
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = NULL;
	newNode->previous = NULL;

	// If there are no nodes in the list make newNode the first node.
	if (!head ) 
	{
		head = newNode;
		tail = newNode;
	}
	else  // Otherwise, insert newNode at end.
	{
		//set the current last node's next pointer to the new node
		tail->next = newNode;
		newNode->previous = tail;
		
		//now the tail is the new node
		tail = newNode;
	}
}

//insert a new node at the integer position passed to this function
void LinkedList::insertNode(int position, double num)
{
	ListNode *nodePtr;
	ListNode *newNode;
	
	newNode = new ListNode;
	newNode->value = num;
	
	if(!head)
	{
		if(position != 0)
		{
			//can't insert node at position (>0) if there is not already a node
			cout << "\n\nUnable to insert a node at position " << position << " because there are currently no nodes in the list.  I am going to insert this node at position 0.\n\n";
		}
		head = newNode;
		tail = newNode;
	}
	else
	{
		nodePtr = head;
		int nodeCount = 0;
		if(position == 0)
		{
			newNode->next = head;
			head->previous = newNode;
			head = newNode;
		}
		while(nodePtr != tail && nodeCount < position)
		{
			nodeCount++;
			if(nodeCount == position)
				break;
			nodePtr = nodePtr->next;
		}
		
		//now nodePtr is positioned 1 node BEFORE the node we want to insert
		if(nodePtr->next == NULL) //we are appending this node to the end
			tail = newNode;
			
		//set up newNode's links
		newNode->next = nodePtr->next;
		newNode->previous = nodePtr;
		
		//change the node on the left
		nodePtr->next = newNode;
		
		//change the node on the right (if there is a node on the right)
		if(newNode->next)
		{
			nodePtr = newNode->next; 
			nodePtr->previous = newNode;
		}
	}
	
}

//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
//**************************************************
void LinkedList::displayList() const
{
	ListNode *nodePtr;  // To move through the list

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr points to a node, traverse the list.
	while (nodePtr)
	{
		// Display the value in this node.
		cout << nodePtr->value << endl;

		// Move to the next node.
		nodePtr = nodePtr->next;
	}
}

//**************************************************
// The deleteNode function searches for a node     *
// with num as its value. The node, if found, is   *
// deleted from the list and from memory.          *
//**************************************************

void LinkedList::deleteNode(double num)
{
	ListNode *nodePtr;       // To traverse the list
	ListNode *previousNode;  // To point to the previous node

	// If the list is empty, do nothing.
	if (!head)
		return;

	// Determine if the first node is the one.
	if (head->value == num)
	{
		nodePtr = head->next;
		delete head;
		if(nodePtr != NULL)
		{
			head = nodePtr;
			head->previous = NULL;
		}
		else
			head = NULL;
	}
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes whose value member is 
		// not equal to num.
		while (nodePtr && nodePtr->value != num)
		{  
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If nodePtr is not at the end of the list, 
		// link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr)
		{
			if(nodePtr == tail)
			{
				tail = previousNode;
			}
			previousNode->next = nodePtr->next;
			delete nodePtr;
			if(previousNode != tail)
			{
				nodePtr = previousNode->next;
				nodePtr->previous = previousNode;
			}
		}
	}
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
// Similar to a typical list function RemoveAll    *
//**************************************************

LinkedList::~LinkedList()
{
	ListNode *nodePtr;   // To traverse the list
	ListNode *nextNode;  // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != NULL)
	{
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}