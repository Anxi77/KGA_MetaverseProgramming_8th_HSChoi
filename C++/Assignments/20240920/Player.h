#pragma once
#include <iostream>
#include <vector>
#include "Unit.h"

class Monster;

class Player : public Unit
{
public:
	enum class Playerclass
	{
		Knight = 1,
		Mage,
		Archer,
		None

	};
	Player(const string& name, const int& hp, const int& atk, const int& def, const int& speed, const int& crit, Playerclass pclass, int money);
	void PlayerSkills(Player* p, Monster*& m, int trig);
	int getMoney() { return pMoney; }
	void setMoney(int drop) { pMoney = drop; }
	void Attack(Player* p, Monster* m, int trig);
	void revive(Player* p) { setHP(100); }
	void Display(Player* p);
	void selectClass(Player*& p);
	void perks(Player* p);
	Playerclass getPlayerClass(Player* p) { return selectedClass; }
private:
	Playerclass selectedClass;
	int pMoney;
};


