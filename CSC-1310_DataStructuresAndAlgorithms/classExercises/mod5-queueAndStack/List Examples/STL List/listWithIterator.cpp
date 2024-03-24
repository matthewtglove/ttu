/********************************************************************
	Title:  	listWithIterator.cpp
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
	list<string> usefulStuff;
	list<string>::iterator myIterator; //iterator
	
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
	
	return 0;
}



