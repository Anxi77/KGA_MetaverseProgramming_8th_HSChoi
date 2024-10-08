#include "Player.h"

Player::Player(const std::string& n, const int h)
	:Unit(n,h)
{
}

void Player::Attack() const
{
	std::cout << name << "Ä®À» ÈÖµÎ¸§" << std::endl;
}

void Player::TakeDamage(const int damage)
{
	health -= damage;
	std::cout << health << std::endl;
}
