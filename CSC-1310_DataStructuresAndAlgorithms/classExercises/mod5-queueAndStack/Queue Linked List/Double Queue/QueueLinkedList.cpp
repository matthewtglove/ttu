// Implementation file for the QueueLinkedList class
#include <iostream>  
#include "QueueLinkedList.h"
using namespace std;
// isEmpty returns true if the stack has no nodes and false if it does
bool QueueLinkedList::isEmpty()
{
	if(!head)
		return true;
	else
		return false;
}

int QueueLinkedList::getLength()
{
	int counter = 0;
	ListNode *nodePtr;
	
	nodePtr = head;
	
	while(nodePtr)
	{
		counter++;
		nodePtr = nodePtr->next;
	}
	return counter;
}

//push this number item at the end of the queue
void QueueLinkedList::push_back(double num)
{
	ListNode *newNode;  // To point to a new node

	// Allocate a new node and store num there.
	newNode = new ListNode;
	newNode->value = num;
	
	if(!head)
	{
		newNode->next = NULL;
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
		tail->next = NULL;
	}
}

//remove & return the first item in the queue
double QueueLinkedList::pop_front()
{
	ListNode *nodePtr;
	double temp;
	
	if(!head)
		return -1;
	else
	{
		nodePtr = head;
		head = head->next;
		
		temp = nodePtr->value;
		delete nodePtr;
		
		return temp;
	}
}

//display all queue items
void QueueLinkedList::displayQueue() const
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
// Destructor                                      *
// This function deletes every node in the queue.  *
//**************************************************

QueueLinkedList::~QueueLinkedList()
{
	ListNode *nodePtr;   // To traverse the list
	ListNode *nextNode;  // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

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
	cout << "\n\nDeleted all the nodes in the queue!!\n\n";
}