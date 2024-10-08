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

int numshuffle(int pick) 
{
	int dest;
	int sour;
	int temp;
	int nums[9];

	for (int i = 0; i < 9; i++)
	{
		nums[i] = i;
	}

	for (int i = 0; i < 1000; i++)
	{
		dest = rand() % 9;
		sour = rand() % 9;
		temp = nums[dest];
		nums[dest] = nums[sour];
		nums[sour] = temp;
	}

	return nums[pick]
}

struct playerCard
{
	int pC;
};
struct cpuCard
{
	int cC;
};

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



int game ()
{
	int strike = 0;
	int ball = 0;

	while (strike < 3) 
	{
		srand((unsigned int)time(NULL)); //랜덤변수 원리 설명좀;;;(동시간내에 루프를 돌려버리면 동일한 난수가 중복되서 생성됨)

		int dest;
		int sour;
		int temp;

		int CPU[9];
		int cpuCard[3];



		cout << endl;
		cout << "Shufflin Numbers" << endl;
		cout << endl;

		for (int i = 0; i < 3; i++)
		{
			cpuCard[i] = CPU[i];
			cout << "CPU's " << " " << i + 1 << " " << " st/th number : " << cpuCard[i] << endl;
		}
	
		cout << "=================================================================================================" << endl;


		int playercard[3];
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
				cin >> playercard[i];
			}
			for (int i = 0; i < 3; i++)
			{
				if (playercard[i] < 0 || playercard[i] > 9)
				{
					numVali++;
				}
			}
			cout << endl;
			if (numVali > 0)
			{
				cout << "Please Enter Valid Numbers !!!" << endl;
			}

			if (playercard[0] >= 0 && playercard[0] <= 9 && playercard[1] >= 0 && playercard[1] <= 9 && playercard[2] >= 0 && playercard[2] <= 9)
			{
				playerFinished = 1;
			}
			cout << endl;
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (playercard[i] == cpuCard[j])
				{
					if (i == j)
					{
						strike++;
					}
					else
					{
						ball++;
					}
				}
			}
		}

		cout << "CPU" << "        " << "You" << endl;
		for (int i = 0; i < 3; i++)
		{
			//cpuCard[i] = CPU[i];
			//cout << "CPU's " << " " << i + 1 << " " << " st/th number : " << CPU[i] << endl;
			cout << " " << cpuCard[i] << "          " << playercard[i] << endl;

		}


		cout << endl;
		cout << "Player's Strike Count : " << strike << endl;
		cout << "Player's Ball Count : " << ball << endl;
		cout << endl;

	}

	cout << endl;
	cout << "Player's Win !!!!!!!" << endl;
		
		return 0;
}




int main()
{
	lobby();
	game();
}

