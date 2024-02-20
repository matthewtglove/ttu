/*****************************************************************
	Title:  		Lab4.cpp
	Creation Date:  9-26-2019
	Last Updated:	1-31-2021
	Author: 		April Crockett
	Purpose:		CSC 1310 Lab 4
******************************************************************/

#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	// Define a LinkedList object.
	List halloweenList;
	
	// Append (add to the end) values to the list
	cout << "\n\nI am appending several strings to the list.\n\n";
	halloweenList.appendNode("boogeyman");
	halloweenList.appendNode("ghost");
	halloweenList.appendNode("scarecrow");
	halloweenList.appendNode("witch");
	halloweenList.appendNode("zombie");
	
	halloweenList.displayList();
	
	//Insert
	cout << "\n\nI am inserting vampire in the list.\n\n";
	halloweenList.insertNode("vampire");
	
	halloweenList.displayList();
	
	
	//Delete
	cout << "\n\nI am deleting ghost from the list.\n\n";
	halloweenList.deleteNode("ghost");
	
	halloweenList.displayList();

	return 0;
}