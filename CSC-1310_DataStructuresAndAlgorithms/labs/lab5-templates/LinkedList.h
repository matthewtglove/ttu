/*****************************************************************
	Filename:       LinkedList.h - Class Specification File for
					LinkedList Template Class
	Date Created:   2024-02-21, Wed
	Author:         Matthew Love
	Purpose:        LAB 5 - A Singly-Linked List implemented in a
					LinkedList template class that contains a ListNode
					structure variable
******************************************************************/

#ifndef LinkedList_H
#define LinkedList_H

#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
class LinkedList
{
private:
	struct ListNode
	{
		T value;
		ListNode *next;
	};

	ListNode *head;
	ListNode *tail;

public:
	LinkedList()
	{
		head = NULL;
		tail = NULL;
	}
	~LinkedList();
	bool isEmpty() const;
	void appendNode(T value);
	void deleteNode(int position);
	void displayList() const;
};

template <typename T>
LinkedList<T>::~LinkedList()
{
	if (!head)
	{
		return;
	}

	ListNode *currentNode = head;
	while (currentNode)
	{
		ListNode *deleteNode = currentNode;
		currentNode = currentNode->next;
		cout << "*****DELETING the node with address: " << deleteNode << endl;
		delete deleteNode;
	}

	head = NULL;
	tail = NULL;
}

// Frequently used in the below functions for initial checks
template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return (!head);
}

template <typename T>
void LinkedList<T>::appendNode(T value)
{
	ListNode *newNode = new ListNode;
	newNode->value = value;
	newNode->next = NULL;

	// First node
	if (isEmpty())
	{
		head = newNode;
		tail = newNode;
		return;
	}

	// Sets current tail to the new value
	tail->next = newNode;
	// Then redefines the tail to the new value
	tail = newNode;
}

template <typename T>
void LinkedList<T>::deleteNode(int position)
{
	// Bad input handling
	if (position < 0)
	{
		cout << "[Given position must be 0 or greater]" << endl;
		return;
	}

	if (isEmpty())
	{
		cout << "[List is empty]" << endl;
		return;
	}

	if (position == 0)
	{
		cout << "DELETING the node with address: " << head << endl;
		delete head;
		return;
	}

	// Bad input handling - Out of bounds check
	int listMaxIndex = 0;
	ListNode *node = head;
	while (node->next != NULL)
	{
		node = node->next;
		listMaxIndex++;
	}
	if (position > listMaxIndex)
	{
		cout << "[Given position is outside of list bounds]" << endl;
		return;
	}

	// Already checked head
	ListNode *previousNode = head;
	ListNode *currentNode = head->next;
	int deleteIndex = 1;
	while (deleteIndex < position)
	{
		currentNode = currentNode->next;
		previousNode = previousNode->next;
		deleteIndex++;
	}

	// Redefines the tail if the last node is going to be deleted
	if (deleteIndex == listMaxIndex)
	{
		tail = previousNode;
	}

	// Makes the previous nodes `next` value equal to the node past the one that is about to be deleted
	previousNode->next = currentNode->next;
	cout << "DELETING the node with address: " << currentNode << endl;
	delete currentNode;
}

template <typename T>
void LinkedList<T>::displayList() const
{
	if (isEmpty())
	{
		cout << "[List is empty]" << endl;
		return;
	}

	ListNode *currentNode = head;
	int nodeCount = 1;

	while (currentNode)
	{
		cout << "-----Node " << nodeCount << " with memory address " << currentNode;

		cout << currentNode->value;

		currentNode = currentNode->next;
		nodeCount++;
	}
}

#endif