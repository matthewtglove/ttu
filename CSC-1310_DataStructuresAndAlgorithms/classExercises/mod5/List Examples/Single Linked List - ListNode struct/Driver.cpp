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
	list.appendNode(2.5);
	list.appendNode(7.9);
	list.appendNode(12.6);
	
	
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

	
	/*
		Get a particular node's value by calling getNodeValue
		and sending the node's index position.  
		Note that index positions in lists usually begin with 
		zero.  
		If that position does not exist in the linked list, then
		the function returns -1.
	*/
	cout << "\n\nThe node in position 1 (2nd node) is ";
	if(list.getNodeValue(1) != -1)
		cout << list.getNodeValue(1) << endl << endl;
	else
		cout << "oops!  That position doesn't exist in the list!\n\n";

	
	/*
		Use the LinkedList search function to search for a node
		with a particular value.
		If the search funciton returns -1, then a node with that 
		value couldn't be found.
	*/
	cout << "\n\nSearching for the node with value 12.6:\n";
	if(list.search(12.6) == -1)
		cout << "A node with value 12.6 could not be found.\n\n";
	else
		cout << "A node with value 12.6 was found at position: " << list.search(12.6) << endl << endl;

	cout << "\n\nSearching for the node with value 20.4:\n";
	if(list.search(20.4) == -1)
		cout << "A node with value 20.4 could not be found.\n\n";
	else
		cout << "A node with value 20.4 was found at position: " << list.search(20.4) << endl << endl;

	
	/*
		Get a particular node's value by calling getNodeValue
		and sending the node's index position.  
	*/
	cout << "\n\nThe node in position 7 (8th node) is ";
	if(list.getNodeValue(7) != -1)
		cout << list.getNodeValue(7) << endl << endl;
	else
		cout << "oops!  That position doesn't exist in the list!\n\n";


	/*
		Delete a node with a specific value by calling the
		deleteNode function, sending the value.
	*/
	cout << "Now deleting the 7.9 node in the middle.\n";
	list.deleteNode(7.9);// Delete the middle node.
	
	
	// Display the list.
	cout << "Here are the nodes left:\n";
	list.displayList();
	cout << endl;

	
	/*
		Insert a node into a specific position with a sent value
		by calling the insertNode function.
	*/
	cout << "Now inserting a node at position 1 with value 9.4.\n";
	list.insertNode(1, 9.4);

	
	// Display the list.
	cout << "Here are the nodes left:\n";
	list.displayList();
	cout << endl;

	cout << "Now deleting the last node (12.6).\n";
	list.deleteNode(12.6);

	cout << "Here are the nodes left:\n";
	list.displayList();
	cout << endl;

	cout << "Now deleting the inserted node (9.4).\n";
	list.deleteNode(9.4);

	cout << "Here are the nodes left:\n";
	list.displayList();
	cout << endl;

	cout << "Now deleting the only remaining node(2.5).\n";
	list.deleteNode(2.5);

	cout << "Right now, the list is ";
	if(list.isEmpty())
		cout << "empty.\n";
	else
		cout << "not empty and has " << list.getLength() << " nodes.\n";
	
	
	cout << "Here are the nodes left:\n";
	list.displayList();
	cout << endl;


	return 0;
}