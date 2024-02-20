//Single Linked List - Driver.cpp

// This program demonstrates the LinkedList class - a singly linked list implemented with a ListNode object
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
	
	


	//getNodeValue function
	cout << "\n\nThe node in position 1 (2nd node) is ";
	if(list.getNodeValue(1) != -1)
		cout << list.getNodeValue(1) << endl << endl;
	else
		cout << "oops!  That position doesn't exist in the list!\n\n";
	
	
	/*
		NOTE:  THIS FUNCTION IS NEW IN THIS VERSION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		insertNode function (overloaded) - will insert the node
		in the correct position based on the value
	*/
	cout << "\n\nNow inserting a node with value 4.3 which will be inserted in correct numerical order of node value.\n";
	list.insertNode(4.3);
	
	// Display the list.
	cout << "Here are the initial values:\n";
	list.displayList();
	cout << endl;
	
	//search function
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
	
	cout << "\n\nThe node in position 7 (8th node) is ";
	if(list.getNodeValue(7) != -1)
		cout << list.getNodeValue(7) << endl << endl;
	else
		cout << "oops!  That position doesn't exist in the list!\n\n";
	
	
	// Delete the middle node.
	cout << "Now deleting the 7.9 node in the middle.\n";
	list.deleteNode(7.9);

	// Display the list.
	cout << "Here are the nodes left:\n";
	list.displayList();
	cout << endl;

	//Insert a new node, but make it inserted at position 2
	cout << "Now inserting a node at position 1 with value 9.4.\n";
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