#pragma once
#include <iostream>
using namespace std;

class Unit
{
public:
	Unit(const string& name, int hp, int atk, int def, int speed, int crit) : uName(name), uHp(hp), uAtk(atk), uDef(def), uSpeed(speed), uCrit(crit) {};
	string getName() const { return uName; }
	int getHP() const { return uHp; }
	int getAtk() const { return uAtk; }
	int getDef() const { return uDef; }
	int getSpeed() const { return uSpeed; }
	int getCrit() const { return uCrit; }
	void setHP(int stat) { uHp = stat; }
	void setAtk(int stat) { uAtk = stat; }
	void setDef(int stat) { uDef = stat; }
	void setSpeed(int skills) { uSpeed = skills; }
	void setCrit(int item) { uCrit += item; }
	virtual void Attack() {};
	virtual void Display() {};
	virtual ~Unit() = default;
protected:
	string uName;
	int uHp;
	int uAtk;
	int uDef;
	int uSpeed;
	int uCrit;
};

