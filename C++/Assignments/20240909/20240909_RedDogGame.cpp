#include <iostream>

using namespace std;

int lobby()
{
	int gameStart;
	gameStart = 0;
	while (gameStart != 1 || gameStart != 2)
	{
		cout << "======================================Welcome to Red Dog Game====================================" << endl;
		cout << endl;
		cout << "1) Start Game" << endl;
		cout << "2) Quit" << endl;
		cout << endl;
		cout << "Please Type 1 or 2 : "; cin >> gameStart;
		if (gameStart == 1)
		{
			cout << endl;
			cout << "=============================================Game Start==========================================" << endl;
			cout << endl;
			return gameStart;
		}
		else if (gameStart == 2)
		{
			cout << endl;
			cout << "=============================================Thank You !==========================================" << endl;
			cout << endl;
			return gameStart;
		}
		else 
		{
			cout << endl;
			cout << "***Please Enter Valid Number***" << endl;
			cout << endl;
		}
	}

}

struct card
{
	string shape;
	int num;
};

void suit(card cards[])
{
	for (int i = 0; i < 53; i++) 
	{
		switch (cards[i].num / 13)
		{
		case 0:
		
			cards[i].shape = "¢¼";
			break;
		case 1:
		
			cards[i].shape = "¡ß";
			break;
		case 2:
		
			cards[i].shape = "¢¾";
			break;
		case 3:
		
			cards[i].shape = "¢À";
			break;
		}
	}
}

void shuffle(card cards[])
{
	srand(time(NULL));

	for (int i = 0; i < 100; i++)
	{
		int dest;
		int sour;
		card temp;

		dest = rand() % 52;
		sour = rand() % 52;
		temp = cards[dest];
		cards[dest] = cards[sour];
		cards[sour] = temp;
	}

}

void num(card cards[])
{
	for (int i = 0; i < 53; i++)
	{
		cards[i].num = (cards[i].num % 13) + 1;
	}
}

void game()
{
	int pMoney = 10000;
	int bMoney = 0;
	card car[52];
	int cards[52];
	int count = 0;
	int gcards[3];
	bool bEsc = true;

	for(int i = 0; i < 53; i++)
	{
		car[i].num = i;
	}

	suit(car);
	num(car);
	shuffle(car);



	while(bEsc)
	{
		int gametrig = 0;


		for(int i = 0; i < 3; i++)
		{
			gcards[i] = car[i + count].num;
		}
		for(int i = 0; i < 2; i++)
		{
			switch (car[i + count].num)
			{
			case 1:
				cout << car[i + count].shape << " " << "Ace" << endl;
				cout << endl;
				break;
			case 11:
				cout << car[i + count].shape << " " << "Jack" << endl;
				cout << endl;
				break;
			case 12:
				cout << car[i + count].shape << " " << "Queen" << endl;
				cout << endl;
				break;
			case 13:
				cout << car[i + count].shape << " " << "King" << endl;
				cout << endl;
				break;
			default:
				cout << car[i + count].shape << " " << gcards[i] << endl;
				cout << endl;
				break;
			}
		}

		cout << endl;
		cout << "Your Current Money : " << pMoney << endl;
		cout << endl;

		while (true)
		{
			cout << "Place Your Bet (Minimum 100 Gold) : ";
			cin >> bMoney;
			if (bMoney >= 100 && bMoney < pMoney)
			{
				break;
			}
			else
			{
				cout << endl;
				cout << "Please Type Valid Number !!! " << endl;
				cout << endl;
			}
		}

		cout << endl;
		cout << "==============================================Last Card===========================================" << endl;
		cout << endl;

		switch (car[2 + count].num)
		{
		case 1:
			cout << car[2 + count].shape << " " << "Ace" << endl;
			cout << endl;
			break;
		case 11:
			cout << car[2 + count].shape << " " << "Jack" << endl;
			cout << endl;
			break;
		case 12:
			cout << car[2 + count].shape << " " << "Queen" << endl;
			cout << endl;
			break;
		case 13:
			cout << car[2 + count].shape << " " << "King" << endl;
			cout << endl;
			break;
		default:
			cout << car[2 + count].shape << " " << gcards[2] << endl;
			cout << endl;
			break;
		}
		
		cout << "==================================================================================================" << endl;
		
		count += 3;

		if (gcards[2] > gcards[0] && gcards[2] < gcards[1] || gcards[2] > gcards[1] && gcards[2] < gcards[0])
		{
			pMoney += bMoney;
			cout << endl;
			cout << "You Win!" << endl;
			cout << endl;
		}
		else
		{
			pMoney -= bMoney;
			cout << endl;
			cout << "You Lose" << endl;
			cout << endl;
		}
		
	
		
		cout << "Number of Remaining Cards : " << 52 - count << endl;

		if (count == 52 || pMoney <= 0)
		{
			bEsc = false;
		}
		
		cout << endl;

		while(bEsc)
		{
			cout << "Type 1) to Continue or 2) to Quit : ";
			cin >> gametrig;

			if(gametrig == 1)
			{
				cout << endl;
				cout << "Next Game..." << endl;
				cout << endl;
				break;
			}
			else if(gametrig == 2)
			{
				bEsc = false;
				
			}
			else
			{
				cout << endl;
				cout << "Please Enter Valid Number !! " << endl;
				cout << endl;
			}
		}
		cout << endl;

	}
	

}

int main()
{
	if(lobby() == 1)
	{
		game();
	}
	cout << "================================================GG's=============================================" << endl;
}