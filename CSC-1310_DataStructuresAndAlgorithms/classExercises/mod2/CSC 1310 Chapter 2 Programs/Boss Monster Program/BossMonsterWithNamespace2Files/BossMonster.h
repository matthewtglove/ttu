/*
	Title:  BossMonster.h
	Author:  April Crockett
	Date:  8/30/2019
	Purpose:  Boss Monster Program - seperated in two files - Bossmonster.h and Driver.h
	and using a monster namespace.
*/

#include <iostream>
using namespace std;

namespace monster
{
	class BossMonster
	{
		private:
			int hitPoints;
			string treasureSymbol; //cleric(holy relic), fighter(sword), mage(magical book), theif (bag of money)
			float weightInPounds;
			float heightInInches;
			
		public:
			BossMonster(int, string, float, float);
			
			bool fightHeroMonsterWins(int, string);
			
			int getHitPoints() const;
			
			string getTreasureSymbol() const;
			
			float getWeightInPounds() const;
			
			float getHeightInInches() const;
			
	};


	BossMonster::BossMonster(int hP, string symbol, float weight, float height)
	{
		hitPoints = hP;
		treasureSymbol = symbol;
		weightInPounds = weight;
		heightInInches = height;
	}

	bool BossMonster::fightHeroMonsterWins(int heroPoints, string heroSymbol)
	{	
		bool theMonsterWon;
		
		if(heroSymbol != treasureSymbol)
			theMonsterWon = false;
		else if(heroPoints >= hitPoints)
			theMonsterWon = false;
		else
			theMonsterWon = true;
			
		return theMonsterWon;
	}

	int BossMonster::getHitPoints() const
	{
		return hitPoints;
	}

	string BossMonster::getTreasureSymbol() const
	{
		return treasureSymbol;
	}

	float BossMonster::getWeightInPounds() const
	{
		return weightInPounds;
	}

	float BossMonster::getHeightInInches() const
	{
		return heightInInches;
	}
}