/*
	Title:  BossMonster.h
	Author: April Crockett
	Purpose:  Boss Monster Program With Namespace in 3 Files
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
}

