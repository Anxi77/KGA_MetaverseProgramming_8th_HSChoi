/*
-과제-
1.슬라이드 퍼즐 만들기
4x4 크기의 슬라이드 퍼즐
종료조건은 없다.
스타트 지점 생성
배열로 스왑

*/

#include <iostream>

using namespace std;

class Generators
{
public:
	void numgen(int nums[])
	{
		for (int i = 0; i < 16; i++)
		{
			nums[i] = i + 1;
		}
	}
	void randnum(int nums[])
	{
		int dest = 0;
		int sour = 0;
		int temp = 0;
		srand(time(NULL));
		for (int i = 0; i < 10; i++)
		{
			dest = rand() % 16;
			temp = rand() % 16;

			temp = nums[dest];
			nums[dest] = nums[sour];
			nums[sour] = temp;
		}

	}
	void makeBoard(int nums[],int board[][4])
	{
		int count = 0;
		for(int i = 0; i <4; i++)
		{
			for(int j = 0; j<4; j++)
			{
				if (i == 3 && j == 3) 
				{
					board[i][j] = 0;
				}
				else
				{
					board[i][j] = nums[count];
				}
				count++;
			}
		}
	}
};

class Functions
{
public:
	void moveNums(int boardget[][4])
	{
		int temp[4][4] = { 0 };
		bool trig = true;
		while (trig)
		{
			string key = "";
			cout << "W : UP | A : Left | S : Down | D : Right :";
			cin >> key;
			bool intrig = true;
			if (key == "w" || key == "W" || key == "a" || key == "A" || key == "s" || key == "S" || key == "d" || key == "D")
			{
				while (intrig)
				{
					if (key == "w" || key == "W")
					{
						for (int i = 0; i < 4; i++)
						{
							if (intrig == false)
							{
								break;
							}
							for (int j = 0; j < 4; j++)
							{
								if (boardget[i][j] == 0)
								{
									if (i == 0)
									{
										cout << "Cant Move !!!" << endl;
										intrig = false;
										break;
									}
									else
									{
										temp[i][j] = boardget[i - 1][j];
										boardget[i - 1][j] = boardget[i][j];
										boardget[i][j] = temp[i][j];
										trig = false;
										intrig = false;
										break;
									}
								}
							}
						}
					}
					if (key == "a" || key == "A")
					{
						for (int i = 0; i < 4; i++)
						{
							if (intrig == false)
							{
								break;
							}
							for (int j = 0; j < 4; j++)
							{
								if (boardget[i][j] == 0)
								{
									if (j == 0)
									{
										cout << "Cant Move !!!" << endl;
										intrig = false;
										break;
									}
									else
									{
										temp[i][j] = boardget[i][j - 1];
										boardget[i][j - 1] = boardget[i][j];
										boardget[i][j] = temp[i][j];
										trig = false;
										intrig = false;
										break;
									}
								}
							}
						}
					}
					if (key == "s" || key == "S")
					{
						for (int i = 0; i < 4; i++)
						{
							if (intrig == false)
							{
								break;
							}
							for (int j = 0; j < 4; j++)
							{
								if (boardget[i][j] == 0)
								{
									if (i == 3)
									{
										cout << "Can't Move !!! " << endl;
										intrig = false;
										break;
									}
									else
									{
										temp[i][j] = boardget[i + 1][j];
										boardget[i + 1][j] = boardget[i][j];
										boardget[i][j] = temp[i][j];
										trig = false;
										intrig = false;
										break;
									}
								}
							}
						}
					}
					if (key == "d" || key == "D")
					{
						for (int i = 0; i < 4; i++)
						{
							for (int j = 0; j < 4; j++)
							{
								if (intrig == false)
								{
									break;
								}
								if (boardget[i][j] == 0)
								{
									if (j == 3)
									{
										cout << "Can't Move !!! " << endl;
										intrig = false;
										break;
									}
									else
									{
										temp[i][j] = boardget[i][j + 1];
										boardget[i][j + 1] = boardget[i][j];
										boardget[i][j] = temp[i][j];
										trig = false;
										intrig = false;
										break;
									}
								}
							}
						}
					}
				}
			}
			else
			{
				cout << "Please Enter Valid Number !!!" << endl;
			}
		}
	}
};

class gameUI
{
public:
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
			cout << "￣";
		}

		cout << endl;
	}
	void displayBoard(int boardget[][4])
	{
		cout << endl;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (boardget[i][j] == 0)
				{
					cout << "\t" << "★" << "\t" << "\t";
				}
				else
				{
					cout << "\t" << boardget[i][j] << "\t" << "\t";
				}
			}
			cout << endl;
			cout << endl;
			cout << endl;
		}
		cout << endl;
	}
};

class slideGame : public Generators, Functions, gameUI
{
public:
	void getslideGame()
	{
		if (lobby() == 1)
		{
			MainGame();
		}
	}

private:
	int num[16];
	int board[4][4];
	void MainGame()
	{
		bool gameTrig = true;
		numgen(num);
		randnum(num);
		makeBoard(num, board);
		while (gameTrig) 
		{
			int inTrig;
			displayBoard(board);
			moveNums(board);
			cout << "1) Continue , 2) Quit : ";
			cin >> inTrig;
			if(inTrig == 1)
			{
				continue;
			}
			else if(inTrig == 2)
			{
				gameTrig = false;
			}
			else
			{
				cout << "Please Enter Valid Number !! " << endl;
			}
		}
	}
	int lobby()
	{
		int gameStart;
		gameStart = 0;
		while (gameStart != 1 || gameStart != 2)
		{
			cout << "===============================================Welcome To Slide Puzzle===========================================" << endl;
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
};

void StartGame()
{
	slideGame* s= new slideGame;
	s->getslideGame();
	delete s;
	s = nullptr;
}

int main()
{
	StartGame();
}

