#include "MainGame.h"
#include "Player.h"
#include "Monster.h"

using namespace std;

void MainGame::battle(Player* p, Monster* m)
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
		p->Attack(p, m, trig);
		p->PlayerSkills(p, m, trig);
		m->Attack(p, m);
	}
	else if (m->getSpeed() > p->getSpeed())
	{
		m->Attack(p, m);
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
		p->Attack(p, m, trig);
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
				p->Attack(p, m, trig);
				p->PlayerSkills(p, m, trig);
				m->Attack(p, m);
				stageTrig = false;
			}
			else if (mobDice > pDice)
			{
				int trig = 0;
				m->Attack(p, m);
				while (trig != 1 && trig != 2)
				{
					cout << "Enter 1) Attack 2) Use Skill : ";
					cin >> trig;
					if (trig != 1 && trig != 2)
					{
						cout << "Please Enter Valid Number" << endl;
					}
				}
				p->Attack(p, m, trig);
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

void MainGame::stage(Player* p) 
{
	bool stageTrig = true;
	int stage = 1;
	while (stageTrig)
	{
		bool monstertrig = true;
		while (p->getHP() > 0 || monstertrig)
		{
			Monster* m = nullptr;

			m->generateMob(stage, m);
			p->Display(players[0]);
			cout << p->getName() << " Encountered Monster " << m->getName() << " !!!" << endl;
			cout << endl;
			while (m->getHP() > 0 && p->getHP() > 0)
			{
				m->Display(m);
				battle(p, m);
			}
			if (p->getHP() <= 0) // 플레이어 사망시
			{
				int contTrig = 0;
				std::cout << "You Died ..." << std::endl;
				std::cout << std::endl;
				while (contTrig != 1 && contTrig != 2)
				{
					std::cout << "1) Continue  2) Quit : ";
					std::cin >> contTrig;
					if (contTrig == 1)
					{
						p->revive(p);
						stage = 1;
						cout << endl;
						break;
					}
					else if (contTrig == 2)
					{
						std::cout << "GG's................" << std::endl;
						stageTrig = false;
						return; // 게임 종료
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
				p->perks(p);
				m->MonsterDrop(p, stage);
				while (stattrig != 1 && stattrig != 2)
				{
					cout << "1) Check Player Status , 2) Continue : ";
					cin >> stattrig;
					cout << endl;
					if (stattrig == 1)
					{
						if(!(p->getPlayerClass(p) == Player::Playerclass::None))
						{
							p->Display(players[0]);
						}
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

void MainGame::gamestart()
{
	Player* newPlayer = new Player(" ", 0, 0, 0, 0, 0, Player::Playerclass::None, 0);
	players.push_back(newPlayer);
	newPlayer->selectClass(newPlayer);
	stage(newPlayer);
}

MainGame::MainGame()
{
	gamestart();
}

