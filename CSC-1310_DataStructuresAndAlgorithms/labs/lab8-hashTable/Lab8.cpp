/*
	Title:    Lab8.cpp
	Author:   April Crockett and Matthew Love
	Date:     October 6, 2020
	Purpose:  Costume Inventory Data stored in Hash Table
*/

#include <iostream>
#include "HashTable.h"
#include "Costume.h"
using namespace std;

int main()
{
	int size;
	int key;
	Costume *newCostume;
	string name;
	float price;
	
	cout << "\nHello.\n\n";
	
	cout <<"What size is the table?   ";
	cin >> size;
	
	//create a Hash Table
	HashTable myHashTable(size);
	
	//Enter ten costumes
	for(int i=0; i<10; i++)
	{
		cout << "\n*****COSTUME " << i+1 << "*****\n";
		cout << "COSTUME ID:  ";
		cin >> key;
		cin.ignore();
		cout << "NAME:  ";
		getline(cin, name);
		cout << "PRICE:  $";
		cin >> price;
		newCostume = new Costume(key, name, price);
		myHashTable.putValue(key, newCostume);
	}
		
	cout << "\n\nHERE IS THE TABLE:\n\n";
	myHashTable.printHashTable();
	cout << endl << endl;
	
	return 0;
	
}