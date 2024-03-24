/*****************************************************************
	Title:  	Driver.cpp
	Date:  		2-8-2019
	Author: 	April Crockett
	Purpose:	This driver creates an instance of the 
				doubly-linked LinkedList class
******************************************************************/

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	// Define a LinkedList object.
	LinkedList list;

	cout << "Right now, the list is ";
	if(list.isEmpty())
		cout << "empty.\n";
	else
		cout << "not empty and has " << list.getLength() << " nodes.\n";

	cout << "\n\nNow, I am adding some list nodes (2.5, 7.9, 12.6).\n\n";
	// Build the list with some values.
	list.appendNode(2.5);
	list.appendNode(7.9);
	list.appendNode(12.6);

	cout << "Right now, the list is ";
	if(list.isEmpty())
		cout << "empty.\n";
	else
		cout << "not empty and has " << list.getLength() << " nodes.\n";

	// Display the list.
	cout << "Here are the initial values:\n";
	list.displayList();
	cout << endl;

	//getNode function
   
	cout << "\n\nThe node in position 2 is ";
	if(list.getNodeValue(2) != -1)
		cout << list.getNodeValue(2) << endl << endl;
	else
		cout << "oops!  That position doesn't exist in the list!\n\n";
	
	cout << "\n\nThe node in position 8 is ";
	if(list.getNodeValue(8) != -1)
		cout << list.getNodeValue(8) << endl << endl;
	else
		cout << "oops!  That position doesn't exist in the list!\n\n";
	
	
	// Delete the middle node.
	cout << "Now deleting the 7.9 node in the middle.\n";
	list.deleteNode(7.9);

	// Display the list.
	cout << "Here are the nodes left:\n";
	list.displayList();
	cout << endl;

	//Insert a new node, but make it inserted at position 1 (2nd node)
	cout << "Now inserting a node at position 1 (2nd node) with value 9.4.\n";
	list.insertNode(1, 9.4);

	cout << "Here are the nodes left:\n";
	list.displayList();
	cout << endl;

	// Delete the last node.
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
	// Display the list.
	cout << "Here are the nodes left:\n";
	list.displayList();
	cout << endl;


	return 0;
}