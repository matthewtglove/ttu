// This program demonstrates a class with a destructor.
#include <iostream>
#include "ContactInfo.h"
using namespace std;

int main()
{
	char name[100] = "Kristen Lee";
	char phone[100] = "931-555-2021";
	
	// Define a ContactInfo object with the following data:
	ContactInfo entry(name, phone);

	// Display the object's data with accessor functions.
	cout << endl << endl;
	cout << "Name: " << entry.getName() << endl;
	cout << "Phone Number: " << entry.getPhoneNumber() << endl;
	
	//Display the object's data with the overloaded << operator.
	cout << entry;
	
	cout << endl << endl;
	
	return 0;
}