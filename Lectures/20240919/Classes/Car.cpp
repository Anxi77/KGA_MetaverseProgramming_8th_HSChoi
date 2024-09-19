#include "Car.h"

Car::Car(const std::string& n) : Vehicle(n)
{
	std::cout << "자식(Car) 생성자 호출" << std::endl;
}

Car::~Car()
{
	std::cout << "Car 소멸자 호출" << std::endl;
}

void Car::Move() const
{
	std::cout << name << "의 자식클래스 자동차 함수 호출" << std::endl;
}
