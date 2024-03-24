


#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	// Define a LinkedList (template) object.
	LinkedList<double> list;

	cout << "Right now, the list is ";
	if(list.isEmpty())
		cout << "empty.\n";
	else
		cout << "not empty and has " << list.getLength() << " nodes.\n";

	// Build the list with some values.
	cout << "\n\nAPPEND NODE WITH VALUE 2.5\n";
	list.appendNode(2.5);
	cout << "\nAPPEND NODE WITH VALUE 7.9\n";
	list.appendNode(7.9);
	cout << "\nAPPEND NODE WITH VALUE 12.6\n";
	list.appendNode(12.6);

	cout << "\n\nRight now, the list is ";
	if(list.isEmpty())
		cout << "empty.\n";
	else
		cout << "not empty and has " << list.getLength() << " nodes.\n";

	// Display the list.
	cout << "Here are the values:\n";
	list.displayList();
	cout << endl;

	//the program will call the NumberList destructor automatically at return 0
	return 0;
}










