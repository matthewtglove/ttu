// This program demonstrates the QueueLinkedList Queue ADT
#include <iostream>
#include "QueueLinkedList.h"
using namespace std;

int main()
{
	// Define a StackLinkedList object.
	QueueLinkedList queue;

	cout << "Right now, the queue is ";
	if(queue.isEmpty())
		cout << "empty.\n";
	else
		cout << "not empty and has " << queue.getLength() << " nodes.\n";

	cout << "\n\nNow, I am adding some queue nodes (2.5, 7.9, 12.6).\n\n";
	queue.push_back(2.5);
	queue.push_back(7.9);
	queue.push_back(12.6);

	cout << "Right now, the queue is ";
	if(queue.isEmpty())
		cout << "empty.\n";
	else
		cout << "not empty and has " << queue.getLength() << " nodes.\n";

	// Display the queue.
	cout << "Here are the initial values in the queue:\n";
	queue.displayQueue();
	cout << endl;
	
	
	// POP
	cout << "Now calling pop.\n";
	queue.pop_front();

	// Display the list.
	cout << "Here are the nodes left in the queue:\n";
	queue.displayQueue();
	cout << endl;
	
	return 0;
}