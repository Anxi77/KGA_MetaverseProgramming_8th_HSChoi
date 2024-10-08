/*
과제1.숫자야구게임(배열)
랜덤하게 숫자 3개를 뽑는다(0~9)
1, 5, 3
ㄴ1, 3, 5
결과는 1s2b
종료조건 : 3s, 1out(3개 다 틀릴 경우에)
*/

#include <iostream>



using namespace std;


int lobby()
{
	int gameStart;
	gameStart = 0;
	while (gameStart != 1 || gameStart != 2)
	{
		cout << "=================================Welcome to Baseball with Numbers================================" << endl;
		cout << endl;
		cout << "1) Start Game" << endl;
		cout << "2) Quit" << endl;
		cout << endl;
		cout << "Please Type 1 or 2 : "; cin >> gameStart;
		if (gameStart == 1 || gameStart == 2)
		{
			cout << endl;
			cout << "=============================================Game Start==========================================" << endl;
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



struct playerCard
{
	int pC;
};
struct cpuCard
{
	int cC;

};
struct originalCard 
{
	int oC;
};


void numshuffle(originalCard orgcard[])
{
	srand((unsigned int)time(NULL));
	int dest;
	int sour;
	int temp;

	for (int i = 0; i < 9; i++)
	{
		orgcard[i].oC = i;
	}

	for (int i = 0; i < 1000; i++)
	{
		dest = rand() % 9;
		sour = rand() % 9;
		temp = orgcard[dest].oC;
		orgcard[dest].oC = orgcard[sour].oC;
		orgcard[sour].oC = temp;
	}

}

void cpuPick(cpuCard cpucard[] , originalCard orgcard[])
{
	int strike = 0;
	int ball = 0;

	cout << endl;
	cout << "Shufflin Numbers" << endl;
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cpucard[i].cC = orgcard[i].oC;
	}
	for (int i = 0; i < 3; i++)
	{		
		cout << "CPU's " << " " << i + 1 << " " << " st/th number : " << orgcard[i].oC << endl;
	}
		
}

void playerPick(playerCard playercard[])
{
	int playerFinished;
	playerFinished = 0;

	cout << endl;
	cout << "Pick 3 Numbers between 0 ~ 9 " << endl;
	cout << endl;
	cout << "=================================================================================================" << endl;
	while (playerFinished == 0)
	{
		int numVali;
		numVali = 0;
		for (int i = 0; i < 3; i++)
		{
			cout << endl;
			cout << "Pick Your" << i + 1 << "st/th" << "Number : ";
			cin >> playercard[i].pC;
			
		}
		for (int i = 0; i < 3; i++)
		{
			if (playercard[i].pC < 0 || playercard[i].pC > 9)
			{
				numVali++;
			}
		}
		cout << endl;
		if (numVali > 0)
		{
			cout << "Please Enter Valid Numbers !!!" << endl;
		}

		else if (playercard[0].pC >= 0 && playercard[0].pC <= 9 && playercard[1].pC >= 0 && playercard[1].pC <= 9 && playercard[2].pC >= 0 && playercard[2].pC <= 9)
		{
			playerFinished = 1;
		}
		cout << endl;
	}
}


void game()
{
	originalCard oCard[9];
	cpuCard cpuCard[3];
	playerCard playercard[3];
	int strike = 0;
	int ball = 0;

	while (strike < 3)
	{



		numshuffle(oCard);
		cpuPick(cpuCard , oCard);
		playerPick(playercard);

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (playercard[i].pC == cpuCard[j].cC)
				{
					if (i == j)
					{
						strike++;
					}
					else
					{
						ball;
					}
				}
			}
		}

		cout << "CPU" << "        " << "You" << endl;
		for (int i = 0; i < 3; i++)
		{
			//cpuCard[i] = CPU[i];
			//cout << "CPU's " << " " << i + 1 << " " << " st/th number : " << CPU[i] << endl;
			cout << " " << cpuCard[i].cC << "          " << playercard[i].pC << endl;

		}


		cout << endl;
		cout << "Player's Strike Count : " << strike << endl;
		cout << "Player's Ball Count : " << ball << endl;
		cout << endl;

	}

	cout << endl;
	cout << "Player's Win !!!!!!!" << endl;

}

int main()
{
	if(lobby() == 1)
	{
		game();
	}
}
