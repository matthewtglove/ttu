// This program demonstrates the NumberList List ADT
#include <iostream>
#include "StackLinkedList.h"
using namespace std;

int main()
{
	// Define a StackLinkedList object.
	StackLinkedList stack;

	cout << "Right now, the stack is ";
	if(stack.isEmpty())
		cout << "empty.\n";
	else
		cout << "not empty and has " << stack.getLength() << " nodes.\n";

	cout << "\n\nNow, I am adding some stack nodes (2.5, 7.9, 12.6).\n\n";
	stack.push(2.5);
	stack.push(7.9);
	stack.push(12.6);

	cout << "Right now, the stack is ";
	if(stack.isEmpty())
		cout << "empty.\n";
	else
		cout << "not empty and has " << stack.getLength() << " nodes.\n";

	// Display the stack.
	cout << "Here are the initial values in the stack:\n";
	stack.displayStack();
	cout << endl;
	
	
	// POP
	cout << "Now calling pop.\n";
	stack.pop();

	// Display the list.
	cout << "Here are the nodes left in the stack:\n";
	stack.displayStack();
	cout << endl;
	
	return 0;
}