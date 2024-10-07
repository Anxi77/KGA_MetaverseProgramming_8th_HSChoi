#include "Monster.h"
#include "Player.h"

void Monster::Attack(Player* p,Monster* m) 
{
	cout << m->getName() << "'s Attack !!" << endl;
	if ((m->getAtk() - p->getDef()) > 0)
	{
		int critrand = rand() % 100;
		if (p->getCrit() > critrand)
		{
			p->setHP(p->getHP() - ((m->getAtk() * 2) - p->getDef()));
			cout << "Critical !!! " << endl;
			cout << p->getName() << " Taken " << (m->getAtk() * 2) - p->getDef() << " Damage !!!" << endl;

		}
		else
		{
			p->setHP(p->getHP() - (m->getAtk() - p->getDef()));
			cout << p->getName() << " Taken " << m->getAtk() - p->getDef() << " Damage !!!" << endl;
		}
	}
	else
	{
		cout << p->getName() << "Has Defended " << m->getName() << "'s Attack !!!" << endl;
	}
}

void Monster::Display(Monster* m)
{
	cout << m->getName() << "'s HP : " << m->getHP() << endl;
	cout << m->getName() << "'s ATK : " << m->getAtk() << endl;
	cout << m->getName() << "'s DEF : " << m->getDef() << endl;
	cout << m->getName() << "'s SPD : " << m->getSpeed() << endl;
	cout << m->getName() << "'s Crit : " << m->getCrit() << " % " << endl;
	cout << endl;
}

void Monster::generateMob(int stage, Monster*& m)
{
	Monster::MonsterType mType = static_cast<Monster::MonsterType>(stage);


	switch (mType)
	{
	case Monster::MonsterType::Slime:
		//name    hp  atk def speedcrit          class        
		m = new Monster("Slime", 120, 10, 0, 20, 1, Monster::MonsterType::Slime);
		break;
	case Monster::MonsterType::Goblin:
		m = new Monster("Goblin", 200, 20, 9, 30, 5, Monster::MonsterType::Goblin);
		break;
	case Monster::MonsterType::Troll:
		m = new Monster("Troll", 350, 30, 20, 50, 7, Monster::MonsterType::Troll);
		break;
	case Monster::MonsterType::Ogre:
		m = new Monster("Ogre", 500, 50, 60, 90, 12, Monster::MonsterType::Ogre);
		break;
	case Monster::MonsterType::DeathAcolyte:
		m = new Monster("Death Acolyte", 450, 100, 30, 100, 25, Monster::MonsterType::Ogre);
		break;
	case Monster::MonsterType::DragonKnight:
		m = new Monster("Dragon Knight", 600, 120, 100, 80, 33, Monster::MonsterType::Ogre);
		break;
	case Monster::MonsterType::BigBlackDragon:
		m = new Monster("Big Black Dragon", 900, 190, 120, 120, 55, Monster::MonsterType::Ogre);
		break;
	}
}

void Monster::MonsterDrop(Player*p , int stage) 
{
	srand(time(NULL));
	int mondrop;
	mondrop = (500 * (rand() % 7));
	cout << "Monster Dropped : " << mondrop << " Gold " << endl;
	cout << endl;
	p->setMoney(p->getMoney() + mondrop);
}