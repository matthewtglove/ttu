/**********************************************************************
	Title:        Destination.h
	Author:       April R. Crockett
	Date Created: 2/3/2021
	Purpose:      Class specification file for the Destination class,
	              which represents a place that a person can vacation 
				  or travel to.
***********************************************************************/

#ifndef _DESTINATION_H
#define _DESTINATION_H

#include <iostream>
using namespace std;

class Destination
{
	private:
		string placeName;
		string description;
		float travelCost;  //typical cost in US dollars to travel to this destination
		int dangerScore; //(1 to 10, 1=not dangerous, 10=you will probably die)
		
	public:
		Destination(string name, string desc, float cost, int danger)
		{
			this->placeName = name;
			this->description = desc;
			this->travelCost = cost;
			this->dangerScore = danger;
		}

		//overloaded << operator to be able to print out this object with cout <<
		friend ostream & operator <<(ostream& os, const Destination& d)
		{
			os << "PLACE:  " << d.placeName << endl;
			os << "DESCRIPTION:  " << d.description << endl;
			os << "TRAVEL COST:  $" << d.travelCost << endl;
			os << "DANGER SCORE:  " << d.dangerScore << endl;
			
			return os;
		}

		//overloaded relational less-than operator so that objects can be easily compared
		bool operator <(const Destination& d)
		{
			if(this->placeName < d.placeName)
				return true;
			return false;
		}
};
#endif