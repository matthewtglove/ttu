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
using namespace std;

template <typename T>
class LinkedList
{
private:
	struct ListNode
	{
		// STRUCTURE MEMBERS NEED TO BE ADDED HERE
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
	void appendNode(T value);
	void deleteNode(int position);
	void displayList() const;
};

// DEFINE ALL OTHER LinkedList class FUNCTIONS BELOW THIS LINE--------------------------------

template <typename T>
LinkedList<T>::~LinkedList()
{
	//
}

#endif