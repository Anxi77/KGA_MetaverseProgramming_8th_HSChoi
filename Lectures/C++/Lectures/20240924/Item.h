#pragma once
#include<string>
class Item
{
private:
	std::string name;
	std::string type;
	int attack;
	int defense;
	bool equipped;

public:
	Item(const std::string& name, const std::string& type, int attack, int defense);

	std::string getName()const { return name; }
	std::string getType()const { return type; }
	int getAttack()const { return attack; }
	int getDefense()const { return defense; }
	bool isEquipped()const { return equipped; }
	void setEquipped(bool value) { equipped = value; }



};

