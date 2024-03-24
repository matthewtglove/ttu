/*****************************************************************
	Title:  	Driver.cpp
	Date:  		2-8-2019
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
	// Define a LinkedList object.
	LinkedList list;

	
	// Tell the user the number of nodes in the list
	cout << "Right now, the list is ";
	if(list.isEmpty())
		cout << "empty.\n";
	else
		cout << "not empty and has " << list.getLength() << " nodes.\n";
	
	
	// Append (add to the end) values to the list
	cout << "\n\nNow, I am adding some list nodes (2.5, 7.9, 12.6).\n\n";
	list.appendNode(12.6);
	list.appendNode(7.9);
	list.appendNode(2.4);
	list.appendNode(4.8);
	
	
	//Tell the user the number of nodes in the list
	cout << "Right now, the list is ";
	if(list.isEmpty())
		cout << "empty.\n";
	else
		cout << "not empty and has " << list.getLength() << " nodes.\n";

	
	// Display the list.
	cout << "Here are the initial values:\n";
	list.displayList();
	cout << endl;
	
	//sort using insertion sort
	list.insertionSort();
	
	
	cout << "Here are the nodes left:\n";
	list.displayList();
	cout << endl;


	return 0;
}