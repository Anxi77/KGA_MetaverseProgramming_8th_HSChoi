
#include"Vehicle.h"
#pragma once
class Bike : public Vehicle
{
public:

	Bike(const std::string& n);
	~Bike();

	void Move()const override;
};

