#pragma once
#include "Monster.h"
#include "Player.h"
#include <vector>

using namespace std;

class MainGame
{
private:
	vector<Player*> players;
	vector<Monster*> monsters;
public:
	void battle(Player* p, Monster* m);
	
	void shop(Player* p); //todo idunno

	void stage(Player* p);

	void gamestart();

	MainGame();



};

