#include "Player.h"
#include "Monster.h"

using namespace std;

Player::Player(const string& name, const int& hp, const int& atk, const int& def, const int& speed, const int& crit, Playerclass pclass, int money)
	: Unit(name, hp, atk, def, speed, crit), selectedClass(pclass), pMoney(money)
{
	//cout << "Player's Name : " << name << endl;
	//cout << "Player's HP : " << hp << endl;
	//cout << "Player's ATK : " << atk << endl;
	//cout << "Player's DEF : " << def << endl;
	//cout << "Player's SPD : " << speed << endl;
	//cout << "Player's Crit : " << crit << " % " << endl;
	//cout << "Player's Money  : " << money << endl;
	//switch (pclass)
	//{
	//case Player::Playerclass::Knight:
	//	cout << "Player's Class : Knight" << endl;
	//	break;
	//case Player::Playerclass::Mage:
	//	cout << "Player's Class : Mage" << endl;
	//	break;
	//case Player::Playerclass::Archer:
	//	cout << "Player's Class : Archer" << endl;
	//}
	//cout << endl;
}

void Player::Attack(Player* p, Monster* m, int trig)
{
	if (trig == 1)
	{
		srand(time(NULL));
		cout << endl;
		cout << p->getName() << "'s Attack !!" << endl;
		if ((p->getAtk() - m->getDef()) > 0)
		{
			int critrand = rand() % 100;
			if (p->getCrit() > critrand)
			{
				m->setHP(m->getHP() - ((p->getAtk() * 2) - m->getDef()));
				cout << "Critical !!! " << endl;
				cout << m->getName() << " Taken " << (p->getAtk() * 2) - m->getDef() << " Damage !!!" << endl;

			}
			else
			{
				m->setHP(m->getHP() - (p->getAtk() - m->getDef()));
				cout << m->getName() << " Taken " << p->getAtk() - m->getDef() << " Damage !!!" << endl;
			}
		}
		else
		{
			cout << m->getName() << " Defended " << p->getName() << "'s Attack !!!" << endl;
		}
		cout << endl;
	}
}

void Player::Display(Player* p) 
{
	cout << "Player's Name : " << getName() << endl;
	cout << "Player's HP : " << getHP() << endl;
	cout << "Player's ATK : " << getAtk() << endl;
	cout << "Player's DEF : " << getDef() << endl;
	cout << "Player's SPD : " << getSpeed() << endl;
	cout << "Player's Crit : " << getCrit() << " % " << endl;
	cout << "Player's Money  : " << getMoney() << endl;
	cout << endl;
}

void KnightSkills(Player* p, Monster*& m)
{
	int skilltrig = 0;
	cout << "1) Shock Stun" << endl;
	cout << "2) Double Stirke" << endl;
	cout << "3) Sheild Breaker" << endl;
	cout << "Enter Number of Skill You Want to Use : ";
	cin >> skilltrig;
	if (skilltrig == 1)
	{
		cout << p->getName() << " Used Shock Stun !! " << endl;
		m->setAtk(m->getSpeed() - 20);
		cout << endl;
		cout << m->getName() << "'s SPD Changed to : " << m->getSpeed() << endl;
	}
	if (skilltrig == 2)
	{
		cout << p->getName() << " Used Double Stirke !! " << endl;
		p->setAtk(p->getAtk() * 2);
		cout << endl;
		if ((p->getAtk() - m->getDef()) > 0)
		{
			cout << m->getName() << " Taken " << p->getAtk() - m->getDef() << " Damage !!!" << endl;
		}
		else
		{
			cout << m->getName() << " Defended " << p->getName() << "'s Attack !!!" << endl;
		}
		if ((p->getAtk() - m->getDef()) > 0)
		{
			m->setHP(p->getAtk() - m->getDef());
		}
		p->setAtk(p->getAtk() / 2);
		cout << endl;
	}
	if (skilltrig == 3)
	{
		cout << p->getName() << " Used Sheild Breaker !! " << endl;
		m->setDef(m->getDef() - 20);
		cout << endl;
		cout << m->getName() << "'s Def Changed to : " << m->getDef();
		cout << endl;
	}
}

void MageSkills(Player* p, Monster*& m)
{
	int skilltrig = 0;
	cout << "1) Magic Missile" << endl;
	cout << "2) Slow Time" << endl;
	cout << "3) Blur" << endl;
	cout << "Enter Number of Skill You Want to Use : ";
	cin >> skilltrig;
	if (skilltrig == 1)
	{
		cout << p->getName() << " Used Magic Missile !! " << endl;
		p->setAtk(p->getAtk() * 3);
		cout << endl;
		if ((p->getAtk() - m->getDef()) > 0)
		{
			cout << m->getName() << " Taken " << p->getAtk() - m->getDef() << " Damage !!!" << endl;
		}
		else
		{
			cout << m->getName() << " Defended " << p->getName() << "'s Attack !!!" << endl;
		}
		if ((p->getAtk() - m->getDef()) > 0)
		{
			m->setHP(p->getAtk() - m->getDef());
		}
		p->setAtk(p->getAtk() / 3);
		cout << endl;
	}
	if (skilltrig == 2)
	{
		cout << p->getName() << " Used Slow Time " << endl;
		m->setAtk(m->getSpeed() - 20);
		cout << endl;
		cout << m->getName() << "'s SPD Changed to : " << m->getSpeed() << endl;
		cout << endl;
	}
	if (skilltrig == 3)
	{
		cout << p->getName() << " Used Blur !! " << endl;
		m->setDef(m->getDef() - 20);
		cout << m->getName() << "'s Def Changed to : " << m->getDef();
		cout << endl;
	}
}

void ArcherSkills(Player* p, Monster*& m)
{
	int skilltrig = 0;
	cout << "1) Ice Arrow" << endl;
	cout << "2) Multi Shot" << endl;
	cout << "3) Nimble" << endl;
	cout << "Enter Number of Skill You Want to Use : ";
	cin >> skilltrig;
	if (skilltrig == 1)
	{
		cout << p->getName() << " Used Ice Arrow !! " << endl;
		m->setSpeed(m->getSpeed() - 20);
		cout << m->getName() << "'s SPD Changed to : " << m->getSpeed();
		cout << endl;
		p->setAtk(p->getAtk() / 2);
		if ((p->getAtk() - m->getDef()) > 0)
		{
			cout << m->getName() << " Taken " << p->getAtk() - m->getDef() << " Damage !!!" << endl;
		}
		else
		{
			cout << m->getName() << " Defended " << p->getName() << "'s Attack !!!" << endl;
		}
		if ((p->getAtk() - m->getDef()) > 0)
		{
			m->setHP(p->getAtk() - m->getDef());
		}
		p->setAtk(p->getAtk() * 2);
		cout << endl;

	}
	if (skilltrig == 2)
	{
		cout << p->getName() << " Used Multi Shot !! " << endl;
		p->setAtk(p->getAtk() * 3);
		cout << endl;
		if ((p->getAtk() - m->getDef()) > 0)
		{
			cout << m->getName() << " Taken " << p->getAtk() - m->getDef() << " Damage !!!" << endl;
		}
		else
		{
			cout << m->getName() << " Defended " << p->getName() << "'s Attack !!!" << endl;
		}
		if ((p->getAtk() - m->getDef()) > 0)
		{
			m->setHP(p->getAtk() - m->getDef());
		}
		p->setAtk(p->getAtk() / 3);
	}
	if (skilltrig == 3)
	{
		cout << p->getName() << " Used Nimble !! " << endl;
		p->setSpeed(p->getSpeed() + 7);
		cout << p->getName() << "'s SPD Changed to : " << p->getSpeed();
	}
}

void Player::PlayerSkills(Player* p, Monster*& m, int trig)
{
	if (trig == 2)
	{
		cout << endl;
		if (p->getPlayerClass(p) == Player::Playerclass::Knight)
		{
			KnightSkills(p, m);
		}
		if (p->getPlayerClass(p) == Player::Playerclass::Mage)
		{
			MageSkills(p, m);
		}
		if (p->getPlayerClass(p) == Player::Playerclass::Archer)
		{
			ArcherSkills(p, m);
		}
	}

}

void Player::selectClass(Player*& p)
{
	string name;
	int trig = 0;
	cout << "Enter Player Name : ";
	cin >> name;
	cout << endl;
	while (trig != 1 && trig != 2 && trig != 3)
	{
		cout << "Enter Class Type 1) Knight , 2) Mage , 3) Archer : ";
		cin >> trig;
		cout << endl;
	}

	Player::Playerclass pclass = static_cast<Player::Playerclass>(trig);

	delete p;

	switch (pclass)
	{
	case Player::Playerclass::Knight:
		//name hp   atk def speedcrit   class                       money
		p = new Player(name, 100, 70, 20, 100, 7, Player::Playerclass::Knight, 100);
		break;

	case Player::Playerclass::Mage:
		p = new Player(name, 77, 30, 5, 100, 3, Player::Playerclass::Mage, 100);
		break;

	case Player::Playerclass::Archer:
		p = new Player(name, 77, 35, 10, 100, 12, Player::Playerclass::Archer, 200);

	}

}

void Player::perks(Player* p) 
{
	srand(time(NULL));
	int randnum = rand() % 6;
	cout << "Randomizing Perks... " << endl;
	cout << endl;
	cout << "Player Got";
	if (randnum == 0)
	{
		cout << " Vengeful Strike : Player's ATK + 15 " << endl;
		p->setAtk(p->getAtk() + 15);
		cout << endl;
	}
	if (randnum == 1)
	{
		cout << " Berserk : Player's ATK + 25 , Player's Def - 15 ";
		p->setAtk(p->getAtk() + 25);
		p->setDef(p->getDef() - 15);
		cout << endl;
	}
	if (randnum == 2)
	{
		cout << " Warped Stirke : Player's ATK + 10 , Player's SPD + 20";
		p->setAtk(p->getAtk() + 10);
		p->setSpeed(p->getSpeed() + 20);
		cout << endl;
	}
	if (randnum == 3)
	{
		cout << " Deadly Strike : Player's ATK + 20 , Player's HP - 15";
		p->setAtk(p->getAtk() + 20);
		p->setHP(p->getHP() - 15);
		cout << endl;
	}
	if (randnum == 4)
	{
		cout << " Great Wall : Player's DEF + 15 , Player's HP + 20";
		p->setDef(p->getDef() + 15);
		p->setHP(p->getHP() + 20);
		cout << endl;
	}
	if (randnum == 5)
	{
		cout << " Haste : Player's Speed + 15 , Player's Crit + 7";
		p->setSpeed(p->getSpeed() + 15);
		p->setCrit(p->getCrit() + 7);
		cout << endl;
	}
	if (randnum == 6)
	{
		cout << "Critical Strike : Player's Crit + 15";
		p->setCrit(p->getCrit() + 15);
		cout << endl;
	}
}


