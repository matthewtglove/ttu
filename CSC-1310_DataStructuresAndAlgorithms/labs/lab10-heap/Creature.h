#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <fstream>
using namespace std;  

class Creature
{
	private:
		string name; //name of creature
		string description; //description of creature
		bool dangerous; //is the creature dangerous?  Will it let me pet it?
		float creatureCost; //cost to take care of the creature per month
		
	public:
		Creature();
		Creature(string, string, bool, float);
		string getName() const;
		string getDescription() const;
		bool getDangerous() const;
		float getCost() const;
		void setName(string);
		void setDescription(string);
		void setDangerous(bool);
		void setCost(float );
		void printCreature();
		void printCreatureToFile(string);
};


#endif
