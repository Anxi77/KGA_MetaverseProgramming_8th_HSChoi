#pragma once
#include"Unit.h"
class Player : public Unit
{
public:
	Player(const std::string& n, const int h);
	void Attack()const override;
	void TakeDamage(const int damage) override;
	
};

