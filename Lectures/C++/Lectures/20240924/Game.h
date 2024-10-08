#pragma once
#include"Player.h"
#include"Item.h"
#include"Menu.h"
class Game
{
private:
	Player* player;
	std::vector<Item> availableItems;

public:
	Game() {

		InitItems();
		player = new Player();
	}
	~Game() 
	{
		delete player;
	}
public:
	void InitItems();
	void Run();
	void ShowMenu();
	void EquipItem();
	void UnEquipItem();
};

