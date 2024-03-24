/*
	Title:  		Costume.h
	Author:			April Crockett
	Date Created:  	October 6, 2020
	Purpose:  		Implementation of the Costume class
				
*/
#ifndef COSTUME_H
#define COSTUME_H

#include <iostream>
using namespace std;

class Costume
{
	private:
		//attributes
		int id; // costume id
		string costumeName;
		float price;
		
	public:
		Costume(int id, string name, float price){
			this->id = id;
			this->costumeName = name;
			this->price = price;
		}
		int getID() const
		{
			return this->id;
		}
		string getCostumeName() const
		{
			return this->costumeName;
		}
		float getPrice() const
		{
			return this->price;
		}
		friend ostream & operator<< (ostream & os, Costume c)
		{
			os << c.getID() << ", " << c.getCostumeName();
			return os;
		}
		
};

#endif