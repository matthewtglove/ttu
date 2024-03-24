/*
	Title:  oop.cpp
	Author: April Crockett
	Date:  8-30-2019
	Purpose: first example of an object oriented program (Book Class)
*/

#include <iostream>
#include <string>
using namespace std;

class Book
{
	private:
		int id;
		string bookName;
		string authorName;
	public:
		void setBookName(string);
		void setAuthorName(string);
		string getAuthorName()const; 
		string getBookName()const;
};

void Book::setBookName(string name)
{
	bookName = name;
}
void Book::setAuthorName(string name)
{
	authorName = name;
}
string Book::getAuthorName()const
{
	return authorName;
}
string Book::getBookName()const
{
	return bookName;
}

int main()
{
	Book b;  //instance (object) of the Book class
	
	//b.bookName = "The Giver";
	b.setBookName("The Giver");
	
	cout << b.getBookName();
	// I will make a call to the defined member functions by using the object b
	
	return 0;
}

