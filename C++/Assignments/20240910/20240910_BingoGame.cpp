/*
과제 2.
빙고게임 만들기
배열을 사용하여 5x5 크기 생성
입력한 숫자를 마킹
1~25까지의 랜덤한 숫자를 배정
종료조건 3줄이면 완성

*/

#include <iostream>

using namespace std;

int lobby()
{
	int gameStart;
	gameStart = 0;
	while (gameStart != 1 || gameStart != 2)
	{
		cout << "===============================================Welcome To Bingo Game=============================================" << endl;
		cout << endl;
		cout << "1) Start Game" << endl;
		cout << "2) Quit" << endl;
		cout << endl;
		cout << "Please Type 1 or 2 : "; cin >> gameStart;
		if (gameStart == 1)
		{
			cout << endl;
			cout << "====================================================Game Start===================================================" << endl;
			cout << endl;
			return gameStart;
		}
		else if (gameStart == 2)
		{
			cout << endl;
			cout << "====================================================Thank You !==================================================" << endl;
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

void separatorS()
{
	for(int i = 0; i < 113; i++)
	{
		cout << "_";
	}
	
	cout << endl;
}
void separatorE()
{

	for (int i = 0; i < 57; i++)
	{
		cout << "￣";
	}

	cout << endl;
}
void Numgen(int bnum[])
{

	for (int i = 0; i < 25; i++)
	{
		bnum[i] = i + 1;
	}
}

void random(int bnum[])
{

	srand(time(NULL));

	for (int i = 0; i < 100; i++)
	{
		int dest;
		int sour;
		int temp = 0;


		dest = rand() % 25;
		sour = rand() % 25;
		temp = bnum[dest];
		bnum[dest] = bnum[sour];
		bnum[sour] = temp;
	}
	
}

void bingoDisplay(int bnum[])
{
	separatorS();
	for (int i = 0; i < 5; i++)
	{
		if(bnum[i] == -1)
		{
			cout << "|\t" << "#" << "\t|" << "\t";
		}
		else 
		{
			cout << "|\t" << bnum[i] << "\t|" << "\t";
		}
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		if (bnum[i+5] == -1)
		{
			cout << "|\t" << "#" << "\t|" << "\t";
		}
		else
		{
			cout << "|\t" << bnum[i+5] << "\t|" << "\t";
		}
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		if (bnum[i+10] == -1)
		{
			cout << "|\t" << "#" << "\t|" << "\t";
		}
		else
		{
			cout << "|\t" << bnum[i + 10] << "\t|" << "\t";
		}
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		if (bnum[i+15] == -1)
		{
			cout << "|\t" << "#" << "\t|" << "\t";
		}
		else
		{
			cout << "|\t" << bnum[i + 15] << "\t|" << "\t";
		}
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		if (bnum[i+20] == -1)
		{
			cout << "|\t" << "#" << "\t|" << "\t";
		}
		else
		{
			cout << "|\t" << bnum[i + 20] << "\t|" << "\t";
		}
	}
	cout << endl;
	separatorE();
	cout << endl;
}
void userInput(int bnum[])
{
	bool usertrig = true;
	while (usertrig)
	{
		int userinput = 0;
		cout << endl;
		cout << "Please enter Number Between 1~25 : ";
		cin >> userinput;
		if (usertrig >= 1 && usertrig <= 25)
		{
			for (int i = 0; i < 25; i++)
			{
				if (bnum[i] == userinput)
				{
					bnum[i] = -1;
					usertrig = false;
				}
			}
		}
		else
		{
			cout << "Please Enter Valid Number !!" << endl;
			cout << endl;
		}
	}
}
void validation(int bnum[], int& bingo)
{
	for (int i = 0; i < 5; i++)
	{
		if (bnum[i * 5] == -1 && bnum[(i * 5) + 1] == -1 && bnum[(i * 5) + 2] == -1 && bnum[(i * 5) + 3] == -1 && bnum[(i * 5) + 4] == -1)
		{
			bingo++;
		}
		if (bnum[i] == -1 && bnum[i + 5] == -1 && bnum[i + 10] == -1 && bnum[i + 15] == -1 && bnum[i + 20] == -1)
		{
			bingo++;
		}
	}
	if (bnum[0] == -1 && bnum[6] == -1 && bnum[12] == -1 && bnum[18] == -1 && bnum[24] == -1)
	{
		bingo++;
	}
	if (bnum[4] == -1 && bnum[8] == -1 && bnum[12] == -1 && bnum[16] == -1 && bnum[20] == -1)
	{
		bingo++;
	}


}

void maingame()
{
	int nums[25];
	int* numsarr = nums;
	int userinput = 0;
	bool bEsc = true;

	
	
	Numgen(numsarr);
	random(numsarr);
	while (bEsc) 
	{
		int bingo = 0;
		bingoDisplay(numsarr);
		userInput(numsarr);
		validation(numsarr, bingo);
	
		if (bingo == 3)
		{
			bEsc = false;
		}

		cout << endl;
		cout << "Your Bingo Count : " << bingo << endl;
		cout << endl;
	}


}

int main()
{
	if (lobby() == 1)
	{
		maingame();
	}
	cout << "=======================================================GG's======================================================" << endl;
}