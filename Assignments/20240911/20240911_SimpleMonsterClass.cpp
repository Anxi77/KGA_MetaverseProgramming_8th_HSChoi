#include <iostream>

using namespace std;

class Monster
{
public:
	string name;
	int att;
	int hp;
	void hit(int incomingdamage)
	{
		hp -= incomingdamage;
	}
private:
	string droptable;

};

void maingame()
{

}