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
	for (int i = 0; i < 113; i++)
	{
		cout << "_";
	}

	cout << endl;
}
void separatorE()
{

	for (int i = 0; i < 57; i++)
	{
		cout << "£þ";
	}

	cout << endl;
}
void bingoDisplay(int bnum[][5])
{
	separatorS();
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++) 
		{
			if (bnum[i][j] == -1)
			{
				cout << "|\t" << "#" << "\t|" << "\t";
			}
			else
			{
				cout << "|\t" << bnum[i][j] << "\t|" << "\t";
			}
		}
		cout << endl;
	}
	cout << endl;
	separatorE();
	cout << endl;
}
void bingoGen(int bingo[][5])
{
	srand(time(NULL));

	int numgen[25];
	int dest;
	int sour;
	int temp;
	int count = 0;

	for (int i = 0; i < 25; i++)
	{
		numgen[i] = i + 1;
	}

	for(int i = 0; i < 100; i ++)
	{
		int dest;
		int sour;
		int temp = 0;

		dest = rand() % 25;
		sour = rand() % 25;

		temp = numgen[dest];
		numgen[dest] = numgen[sour];
		numgen[sour] = temp;
	}

	for(int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			bingo[i][j] = numgen[count];
			count++;
		}
	}
}
void userinput(int bingo[][5], int& count)
{
	bool bEsc = true;
	int playerinput = 0;

	while(bEsc)
	{
		cout << "Please Enter Number Between 1 ~25 : ";
		cin >> playerinput;

		if(playerinput >= 1 && playerinput <= 25)
		{
			for(int i = 0; i < 5; i++)
			{
				for(int j = 0; j < 5; j++)
				{
					if(bingo[i][j] == playerinput)
					{
						bingo[i][j] = -1;
						count += 1;
						bEsc = false;
					}
					
				}
			}
		}
		else
		{
			cout << "Please Enter Vaild Number !!! " << endl;
		}
	}
}
void validation(int bingo[][5],bool& bEsc)
{
	int bingocount = 0;
	int widthcount = 0;
	int vertcount = 0;
	int xcount1 = 0;
	int xcount2 = 0;
	
	for(int i = 0; i < 5; i++)
	{
		widthcount = 0;

		for(int j = 0; j < 5; j++)
		{
			if(bingo[i][j] == -1)
			{
				widthcount++;
			}
		}
		if (widthcount == 5)
		{
			bingocount++;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		vertcount = 0;
		for (int j = 0; j < 5; j++)
		{
			if (bingo[j][i] == -1)
			{
				vertcount++;
			}
			if (vertcount == 5)
			{
				bingocount++;
			}
		}
	}

	for(int i = 0; i < 5; i++)
	{
		if(bingo[i][i] == -1)
		{
			xcount1++;
		}
		if (xcount1 == 5)
		{
			bingocount++;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		if (bingo[i][4-i] == -1)
		{
			xcount2++;
		}
		if (xcount2 == 5)
		{
			bingocount++;
		}
	}


	if(bingocount >= 3)
	{
		bEsc = false;
	}
}
void maingame()
{
	int bingo[5][5];
	bool bEsc = true;
	int count = 0;
	bingoGen(bingo);
	while(bEsc)
	{
		bingoDisplay(bingo);
		userinput(bingo, count);
		validation(bingo, bEsc);
	}
}
int main()
{
	if(lobby() == 1)
	{
		maingame();
	}
	cout << "=======================================================GG's======================================================" << endl;


}