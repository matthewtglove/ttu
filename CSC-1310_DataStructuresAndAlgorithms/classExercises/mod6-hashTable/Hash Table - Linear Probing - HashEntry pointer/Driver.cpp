#include <iostream>
#include "HashTable.h"
using namespace std;

int main()
{
	int size;
	int value;
	
	cout << "\nHello.\n\n";
	
	cout <<"What size is the table?   ";
	cin >> size;
	
	//create a Hash Table
	HashTable myHashTable(size);
	
	//add some keys and values
	cout << "\nEnter a value:  ";
	cin >> value;
	myHashTable.putValue(value, value);
	
	cout << "\nEnter a value:  ";
	cin >> value;
	myHashTable.putValue(value, value);
	
	cout << "\nEnter a value:  ";
	cin >> value;
	myHashTable.putValue(value, value);
	
	cout << "\nEnter a value:  ";
	cin >> value;
	myHashTable.putValue(value, value);
	
	cout << "\n\nHERE IS THE TABLE:\n\n";
	myHashTable.printHashTable();
	cout << endl << endl;
	
	
	
}