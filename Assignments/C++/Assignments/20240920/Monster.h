#pragma once

#include <iostream>
#include "Unit.h"
#include "Player.h"

using namespace std;

class Player;

class Monster : public Unit
{
public:

	enum class MonsterType
	{
		Slime = 1,
		Goblin,
		Troll,
		Ogre,
		DeathAcolyte,
		DragonKnight,
		BigBlackDragon
	};
	Monster(const string& name, const int& hp, const int& atk, const int& def, const int speed, const int crit, MonsterType mtype)
		: Unit(name, hp, atk, def, speed, crit), selectedtype(mtype) {};
	
	void Display(Monster* m);
	void Attack(Player* p, Monster* m);
	void generateMob(int stage, Monster*& m);
	void MonsterDrop(Player* p, int stage);


private:
	MonsterType selectedtype;
};