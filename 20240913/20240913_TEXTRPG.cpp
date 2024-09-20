/*
2.턴제게임 만들기
*/

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

protected:
	string uName;
	int uHp;
	int uAtk;
	int uDef;
	int uSpeed;
	int uCrit;
};

class Monster : public Unit
{
public:
	enum class MonsterType
	{
		Slime = 1,
		Goblin,
		Troll,
		Ogre,
		DeathAcolyte,
		DragonKnight,
		BigBlackDragon
	};
	Monster(const string& name, const int& hp, const int& atk, const int& def, const int speed, const int crit, MonsterType mtype)
		: Unit(name, hp, atk, def, speed, crit), selectedtype(mtype) {};
private:
	MonsterType selectedtype;

};

class Player : public Unit
{
public:
	enum class Playerclass
	{
		Knight = 1,
		Mage,
		Archer
	};
	Player(const string& name, const int& hp, const int& atk, const int& def, const int& speed, const int& crit, Playerclass pclass, int money)
		: Unit(name, hp, atk, def, speed, crit), selectedClass(pclass), pMoney(money)
	{
		cout << "Player's Name : " << name << endl;
		cout << "Player's HP : " << hp << endl;
		cout << "Player's ATK : " << atk << endl;
		cout << "Player's DEF : " << def << endl;
		cout << "Player's SPD : " << speed << endl;
		cout << "Player's Crit : " << crit << " % " << endl;
		cout << "Player's Money  : " << money << endl;
		switch (pclass)
		{
		case Player::Playerclass::Knight:
			cout << "Player's Class : Knight" << endl;
			break;
		case Player::Playerclass::Mage:
			cout << "Player's Class : Mage" << endl;
			break;
		case Player::Playerclass::Archer:
			cout << "Player's Class : Archer" << endl;
		}
		cout << endl;
	}
	void PlayerSkills(Player*& p, Monster*& m, int trig)
	{
		if (trig == 2)
		{
			cout << endl;
			if (p->selectedClass == Player::Playerclass::Knight)
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
			if (p->selectedClass == Player::Playerclass::Mage)
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
			if (p->selectedClass == Player::Playerclass::Archer)
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
		}

	}
	int getMoney() { return pMoney; }
	void setMoney(int drop) { pMoney = drop; }
private:
	Playerclass selectedClass;
	int pMoney;
};

void selectClass(Player*& p)
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

void generateMob(int mobselec, Monster*& m) //Monster* m �� �����͸� �����ؾ��ϱ⿡ *&�� ���ÿ� ���
{
	Monster::MonsterType mType = static_cast<Monster::MonsterType>(mobselec);


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

void playerAttack(Player*& p, Monster*& m, int trig)
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

void monsterAttack(Player*& p, Monster*& m)
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

void monsterDisplay(Player* p, Monster* m)
{
	cout << m->getName() << "'s HP : " << m->getHP() << endl;
	cout << m->getName() << "'s ATK : " << m->getAtk() << endl;
	cout << m->getName() << "'s DEF : " << m->getDef() << endl;
	cout << m->getName() << "'s SPD : " << m->getSpeed() << endl;
	cout << m->getName() << "'s Crit : " << m->getCrit() << " % " << endl;
	cout << endl;
}

void playerDisplay(Player* p, Monster* m)
{
	cout << "Player's Name : " << p->getName() << endl;
	cout << "Player's HP : " << p->getHP() << endl;
	cout << "Player's ATK : " << p->getAtk() << endl;
	cout << "Player's DEF : " << p->getDef() << endl;
	cout << "Player's SPD : " << p->getSpeed() << endl;
	cout << "Player's Crit : " << p->getCrit() << " % " << endl;
	cout << "Player's Money  : " << p->getMoney() << endl;
	cout << endl;
}

void battle(Player* p, Monster* m)
{

	if (p->getSpeed() > m->getSpeed())
	{
		int trig = 0;
		while (trig != 1 && trig != 2)
		{
			cout << "Enter 1) Attack 2) Use Skill : ";
			cin >> trig;
			if (trig != 1 && trig != 2)
			{
				cout << "Please Enter Valid Number" << endl;
			}
		}
		playerAttack(p, m, trig);
		p->PlayerSkills(p, m, trig);
		monsterAttack(p, m);
	}
	else if (m->getSpeed() > p->getSpeed())
	{
		monsterAttack(p, m);
		int trig = 0;
		while (trig != 1 && trig != 2)
		{
			cout << "Enter 1) Attack 2) Use Skill : ";
			cin >> trig;
			if (trig != 1 && trig != 2)
			{
				cout << "Please Enter Valid Number" << endl;
			}
		}
		playerAttack(p, m, trig);
		p->PlayerSkills(p, m, trig);
	}
	else
	{
		bool stageTrig = true;
		cout << p->getName() << " And " << m->getName() << " Has Same Speed !!!" << endl;
		cout << endl;
		cout << "Rolling The Dice......" << endl;
		cout << endl;
		while (stageTrig)
		{
			srand(time(NULL));
			int mobDice = rand() % 6;
			int pDice = rand() % 6;
			cout << "Player's Dice : " << pDice << endl;
			cout << "Monster's Dice : " << mobDice << endl;
			cout << endl;
			if (pDice > mobDice)
			{
				int trig = 0;
				while (trig != 1 && trig != 2)
				{
					cout << "Enter 1) Attack 2) Use Skill : ";
					cin >> trig;
					if (trig != 1 && trig != 2)
					{
						cout << "Please Enter Valid Number" << endl;
					}
				}
				playerAttack(p, m, trig);
				p->PlayerSkills(p, m, trig);
				monsterAttack(p, m);
				stageTrig = false;
			}
			else if (mobDice > pDice)
			{
				int trig = 0;
				monsterAttack(p, m);
				while (trig != 1 && trig != 2)
				{
					cout << "Enter 1) Attack 2) Use Skill : ";
					cin >> trig;
					if (trig != 1 && trig != 2)
					{
						cout << "Please Enter Valid Number" << endl;
					}
				}
				playerAttack(p, m, trig);
				p->PlayerSkills(p, m, trig);
				stageTrig = false;
			}
			else
			{
				cout << p->getName() << " And " << m->getName() << " Got Same Dice !!" << endl;
				cout << "Rerolling....." << endl;
			}
		}
	}
	cout << endl;
	cout << p->getName() << "'s Remaining HP : " << p->getHP() << endl;
	cout << endl;
}

void perks(Player* p)
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

void MonsterDrop(Player* p, int stage)
{
	srand(time(NULL));
	int mondrop;
	mondrop = (500 * (rand() % 7));
	cout << "Monster Dropped : " << mondrop << " Gold " << endl;
	cout << endl;
	p->setMoney(p->getMoney() + mondrop);
}

void shop(Player* p)
{
}

void stage(Player* p)
{
	bool stageTrig = true;
	int stage = 1;
	while (stageTrig)
	{
		bool monstertrig = true;
		while (p->getHP() > 0 || monstertrig)
		{
			Monster* m = nullptr;

			generateMob(stage, m);
			cout << p->getName() << " Encountered Monster " << m->getName() << " !!!" << endl;
			cout << endl;
			while (m->getHP() > 0 && p->getHP() > 0)
			{
				monsterDisplay(p, m);
				battle(p, m);
			}
			if (p->getHP() <= 0) // 플레이어 사망시
			{
				int contTrig = 0;
				cout << "You Died ..." << endl;
				cout << endl;
				while (contTrig != 1 && contTrig != 2)
				{
					cout << "1) Continue  2) Quit : ";
					cin >> contTrig;
					if (contTrig == 1)
					{
						break;
					}
					else if (contTrig == 2)
					{
						cout << "GG's................" << endl;
						stageTrig = false;
						break;
					}
				}
			}
			else if (m->getHP() <= 0) // 플레이어 승리시
			{
				int stattrig = 0;
				cout << p->getName() << "Has Defeated " << m->getName() << " !!!" << endl;
				cout << endl;
				monstertrig = false;
				stage++;
				perks(p);
				MonsterDrop(p, stage);
				while (stattrig != 1 && stattrig != 2)
				{
					cout << "1) Check Player Status , 2) Continue : ";
					cin >> stattrig;
					cout << endl;
					if (stattrig == 1)
					{
						playerDisplay(p, m);
						cout << "Next Stage..." << endl;
						cout << endl;
					}
					else if (stattrig == 2)
					{
						cout << "Next Stage..." << endl;
						cout << endl;
					}
					else
					{
						cout << "Please Enter Valid Number !!! " << endl;
						cout << endl;
					}
				}
			}
			delete m;
		}
	}
}

void maingame()
{
	Player* p = nullptr;
	selectClass(p);
	stage(p);
}

int main()
{
	maingame();
	return 0;
}