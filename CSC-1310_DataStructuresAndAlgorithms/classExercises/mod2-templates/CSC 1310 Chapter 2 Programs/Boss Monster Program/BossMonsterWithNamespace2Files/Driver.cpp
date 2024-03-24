/*
	Title:  Driver.cpp
	Author:  April Crockett
	Date:  8/30/2019
	Purpose:  Boss Monster Program - seperated in two files - Bossmonster.h and Driver.h
	and using a monster namespace.
*/

#include <iostream>
#include "Bossmonster.h"
using namespace std;

int main()
{
	monster::BossMonster rancor(800, "fighter", 500, 200.5);
	string symbol;
	int heroPoints;
	char response;
	
	cout << "\n\nHello, hero!  What treasure do you have?  (cleric, fighter, mage, theif)\n";
	getline(cin, symbol);
	
	while(symbol != "cleric" && symbol != "fighter" && symbol != "mage" && symbol != "theif")
	{
		cout << "\nThat is not one of the possible treasures that you could have.\n";
		cout << "What treasure do you have?  (cleric, fighter, mage, theif)\n";
		getline(cin, symbol);
	}
	
	cout << "\nGreat!  Now how many hit points do you have? (0 to 1000)\n";
	cin >> heroPoints;
	
	while(heroPoints < 0 || heroPoints > 1000)
	{
		cout << "\nThat is an invalid number of hit points.\n";
		cout << "\nHow many hit points do you have?  (0 to 1000)\n";
		cin >> heroPoints;
	}
	
	cout << "\n\nThe Rancor has " << rancor.getHitPoints() << " hit points.  Do you want to fight it?\n";
	cout << "Enter Y or N:  ";
	cin >> response;
	
	if(response == 'Y' || response == 'y')
	{
		if(rancor.fightHeroMonsterWins(heroPoints, symbol))
		{
			cout << "\n\nOh No!  The Rancor won and you are dead!!\n\n";
		}
		else
			cout << "\n\nAwesome!!  You won and the Rancor is dead!!\n\n";
	}
	
	return 0;
}







