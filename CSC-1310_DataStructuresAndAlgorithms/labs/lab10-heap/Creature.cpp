#include "Creature.h"

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

Creature::Creature()
{
	
}

Creature::Creature(string n, string d, bool dang, float cost)
{
	name = n; //name of creature
	description = d; //description of creature
	dangerous = dang; //is the creature dangerous?  Will it let me pet it?
	creatureCost = cost; //cost to take care of the creature per month
}

string Creature::getName() const
{
	return name;
}
string Creature::getDescription() const
{
	return description;
}
bool Creature::getDangerous() const
{
	return dangerous;
}
float Creature::getCost() const
{
	return creatureCost;
}
void Creature::setName(string n)
{
	name = n;
}
void Creature::setDescription(string desc)
{
	description = desc;
}
void Creature::setDangerous(bool dang)
{
	dangerous = dang;
}
void Creature::setCost(float cost)
{
	creatureCost = cost;
}

void Creature::printCreature()
{
	bool flag;
	cout << setprecision(2) << fixed;
	cout << "Name:  " << name << endl;
	
	//print out the description with some word wrapping
	int len = description.length();
	cout << "Description:\n";
	for(int y = 0; y < len; y++)  //go through each character of the description
	{
		if(y%60 == 0 && y != 0) //once we reach the 60th character we are at the point where we want to go to the next line
		{
			//time to add a newline.
			flag = true;
		}
		if(y == 0)
		{
			cout << "\t ";  //this will indent the first line of the description
		}
		if(flag == true && description[y] == ' ')  //dont start a new line until the word is finished, though (determined by a space).
		{
			cout << "\n\t"; //start new line & indent the line
			flag = false;
		}
			
		cout << description[y]; //print out the character
	}
	cout << endl << endl;								
	cout << "Dangerous?  ";
	if(dangerous == true)
		cout << "yes\n";
	else
		cout << "no\n";
	cout << "Cost per Month to Care for Creature:  $ " << creatureCost << endl;

	
	cout << endl << endl;
}

void Creature::printCreatureToFile(string fileName)
{
	ofstream file;
	file.open(fileName.c_str(), ios::app);
	if(file)
	{
		file << name << endl;
		file << description << endl; 
		file << dangerous << endl;
		file << creatureCost << endl;
		file.close();
		file.clear();
		cout << name << " was printed to " << fileName << "\n";
	}
	else
	{
		cout << "\n\nCreature could not be printed to file because file couldn't be opened.\n\n";
	}
}