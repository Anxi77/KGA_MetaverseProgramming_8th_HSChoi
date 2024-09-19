


#include"Vehicle.h"
//여긴 자식 클래스
#pragma once
class Car : public Vehicle
{
public:
	Car(const std::string& n);
	~Car();

	void Move()const override;
};

