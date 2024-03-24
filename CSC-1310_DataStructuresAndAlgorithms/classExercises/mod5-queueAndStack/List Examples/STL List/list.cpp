/********************************************************************
	Title:  	list.cpp
	Author:  	April Crockett
	Date:  		Fall 2018
	Purpose:  	Demonstrate the Standard Template Library (STL) 
				List template class container
********************************************************************/

#include <list>
#include <iostream>

using namespace std;

int main()
{
	list <string> usefulStuff;
	
	usefulStuff.push_back("Duct Tape");
	usefulStuff.push_back("Zip Ties");
	usefulStuff.push_back("Magic Erasers");
	usefulStuff.push_back("Zip Ties");
	usefulStuff.push_front("Sharpies");
	
	cout << "\n\nThe number of characters in the string in the first node is ";
	cout << usefulStuff.front().length() << endl;  //prints out Sharpies
	
	cout << usefulStuff.back() << endl; 
	
	cout << "\nCurrent size of list:  " << usefulStuff.size() << endl;
	
	usefulStuff.pop_back();
	cout << "\nSize after pop_back: " << usefulStuff.size();
	
	usefulStuff.pop_front();
	cout << "\nSize after pop_front: " << usefulStuff.size() << endl;
	
	//usefulStuff.remove("Zip Ties");
	cout << "\nSize after removing Zip Ties: " << usefulStuff.size() << endl;
	
	return 0;
}