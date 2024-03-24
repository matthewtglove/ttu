/*****************************************************************
	Title:  	ShorterDriver.cpp
	Date:  		2-24-2021
	Author: 	April Crockett
	Purpose:	To demonstrate a Singly-Linked List using a
				LinkedList class that contains a ListNode
				structure variable
******************************************************************/

#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	
	LinkedList list;    // Define a LinkedList object.

	cout << "\n\nAppending list nodes with values (2.5, 7.9, 12.6).\n";
	list.appendNode(2.5);
	list.appendNode(7.9);
	list.appendNode(12.6);
	
	cout << "\nInserting a node at position 1 with value 9.4.\n";
	list.insertNode(1, 9.4);

	cout << "\nHere are the values in the singly linked list:\n";
	list.displayList();

	cout << "\nNow deleting the 7.9 node in the middle.\n";
	list.deleteNode(7.9);
	
	cout << "\nHere are the values in the singly linked list:\n";
	list.displayList();

	return 0;
}