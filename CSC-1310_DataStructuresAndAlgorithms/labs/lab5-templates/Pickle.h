/************************************************************
	Filename:      Pickle.h
	Author:        April R. Crockett
	Date Created:  2/24/2021
	Purpose:       Class specification file for a Pickle
				   which will be used in
				   CSC 1310 LAB 5 on Template Linked List
*************************************************************/

#ifndef PICKLE_H
#define PICKLE_H

class Pickle
{
private:
	string type;
	bool bumpySkin;
	bool sweet;

public:
	// CONSTRUCTORS
	Pickle() {}
	Pickle(string t, bool b, bool swe)
	{
		this->type = t;
		this->bumpySkin = b;
		this->sweet = swe;
	}

	// OVERLOADED << OPERATOR to display the pickle with cout <<
	friend ostream &operator<<(ostream &os, Pickle p)
	{
		os << "\nPickle Type:\t" << p.type;
		os << "\nBumpy Skin?\t";
		if (p.bumpySkin)
			os << "yes\n";
		else
			os << "no\n";
		os << "Sweet?\t\t";
		if (p.sweet)
			os << "yes\n";
		else
			os << "no\n";

		return os;
	}

	// OVERLOADED relational operators to be able to search for a specific pickle object by type
	bool operator!=(const Pickle &p)
	{
		if (this->type != p.type)
			return true;
		else
			return false;
	}

	// OVERLOADED == OPERATOR to be able to search for a specific pickle object by type
	bool operator==(const Pickle &p)
	{
		if (this->type == p.type)
			return true;
		else
			return false;
	}
};

#endif