#pragma once
#include "Monster.h"
#include "Player.h"

using namespace std;

class MainGame
{
private:
	Player* p;
	Monster* m;
public:
	void battle(Player* p, Monster* m);
	
	void shop(Player* p) {};

	void stage(Player* p);

	MainGame()
	{ 
	p = nullptr;
	p->selectClass(p);
	stage(p);
	delete p;
	};

};

