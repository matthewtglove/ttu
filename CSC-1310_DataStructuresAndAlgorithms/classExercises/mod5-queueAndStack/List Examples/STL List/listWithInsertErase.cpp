/********************************************************************
	Title:  	listWithInsertErase.cpp
	Author:  	April Crockett
	Date:  		Fall 2018
	Purpose:  	Demonstrate the Standard Template Library (STL) 
				List template class container
				Also demonstrate the STL iterator class
********************************************************************/

#include <list>
#include <iostream>

using namespace std;

int main()
{
	list <string> usefulStuff;
	list <string>::iterator myIterator; //iterator
	
	string name;
	
	usefulStuff.push_back("Duct Tape");
	usefulStuff.push_back("Zip Ties");
	usefulStuff.push_back("Magic Erasers");
	usefulStuff.push_front("Sharpies");
	
	//the following line prints "Sharpies" to the screen and also the front() function returns the iterator that points to the beginning of the list.
	cout << "\n\nPRINTING THE FRONT OF THE LIST:  " << usefulStuff.front() << endl;  
	
	//the following line prints "Magic Erasers" to the screen and also the front() function returns the iterator that points to the beginning of the list.
	cout << "\n\nPRINTING THE END OF THE LIST:  " << usefulStuff.back() << endl;
	
	cout << endl << endl;
	cout << "HERE IS THE FULL LIST FROM BEGINNING TO END USING THE ITERATOR:\n";
	for(myIterator = usefulStuff.begin();  myIterator != usefulStuff.end();  myIterator++)
	{
		name = *myIterator;  //if you dereference the iterator, then you are accessing the element that the iterator was pointing to
		cout << name << endl;
	}
	cout << endl;
	
	//insert a new element into the list before an iterator's position
	//So if I want to insert a 5th list item, but I want it in the middle then first make the iterator point to the third element
	myIterator = usefulStuff.begin(); //start at beginning of list
	myIterator++; //point to next (2nd) element in list
	myIterator++; //point to next (3rd) element in list
	
	//now insert "Stapler", which will insert BEFORE the iterator position - before the 3rd element
	usefulStuff.insert(myIterator, "Stapler");
	
	//now print out the list again
	cout << endl << endl;
	cout << "HERE IS THE FULL LIST AFTER INSERTING STAPLER:\n";
	for(myIterator = usefulStuff.begin();  myIterator != usefulStuff.end();  myIterator++)
	{
		name = *myIterator;  //if you dereference the iterator, then you are accessing the element that the iterator was pointing to
		cout << name << endl;
	}
	cout << endl;
	
	
	//erase a single element at iterator position
	//So if I want to erase "Zip Ties" I will first need to move the iterator from it's current position (3rd element) to the Zip Ties (4th) element.
	myIterator = usefulStuff.begin(); //start at the beginning of the list (Sharpies)
	myIterator++;  //now pointing to Duct Tape
	myIterator++;  //now pointing to Stapler
	myIterator++;  //now pointing to Zip Ties
	usefulStuff.erase(myIterator);
	
	//now print out the list again
	//now print out the list again
	cout << endl << endl;
	cout << "HERE IS THE FULL LIST AFTER ERASING ZIP TIES:\n";
	for(myIterator = usefulStuff.begin();  myIterator != usefulStuff.end();  myIterator++)
	{
		name = *myIterator;  //if you dereference the iterator, then you are accessing the element that the iterator was pointing to
		cout << name << endl;
	}
	cout << endl;
	
	return 0;
}