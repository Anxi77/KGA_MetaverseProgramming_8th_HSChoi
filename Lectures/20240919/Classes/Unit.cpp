#include "Unit.h"

Unit::Unit(const std::string& n, const int h)
	:name(n), health(h)
{
}

Unit::~Unit()
{
}

void Unit::Move()
{
	std::cout << "무브 함수" << std::endl;
}
