/*
	과제 2. 카드게임(월남뽕)
	트럼프 52장 생성 (4개의 문양 , 1 ~ 13(a~k))
	보여지는 카드 3장
	베팅액 있음
	두장의 카드가 보여지고 그 사이에 내가 뽑은 카드가 들어가면 승리
	한번 나온 카드는 다시 나오면 안된다.
	그전에 나온 인덱스를 접근하지 않으면 된다.

	종료조건 : 파산 , 17판
*/

#include <iostream>

using namespace std;

void seperator()
{
	for (int i = 97; i > 0; i--)
	{
		cout << "*";
	}
	cout << endl;
}


int lobby() 
{
	int gameStart;
	gameStart = 0;
	while (gameStart != 1 || gameStart != 2)
	{
		cout << "=================================Welcome to Red Dog================================" << endl;
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

void game()
{
	srand(time(NULL));
	int pMoney = 10000;
	int count = 0;
	int pickedcards[3] = {0};
	int playercard = 0;
	int playerpick = 0;
	int nonPickedCard = 0;
	int cards[4][13] = { 0 };
	int dumpcards[4][13] = { 0 };
	int picksuits, picknums = 0;
	bool gametrig = true;

	//카드 생성
	for (int num = 0; num < 13; num++)
	{
		cards[0][num] = num + 1;
		cards[1][num] = num + 1;
		cards[2][num] = num + 1;
		cards[3][num] = num + 1;
	}


	//for (int i = 0; i < 1000; i++) //2차원 배열 랜덤섞끼
	//{
	//	suitsorg = rand() % 4;
	//	suitsrand = rand() % 4;
	//	numsorg = rand() % 13;
	//	numsrand = rand() % 13;
	//
	//	temp = cards[suitsorg][numsorg];
	//	cards[suitsorg][numsorg] = cards[suitsrand][numsrand];
	//	cards[suitsrand][numsrand] = temp;
	//}


	while (gametrig)
	{

		int bMoney = 0;
		cout << "Your Current Money is : " << pMoney << " Gold" << endl;
		seperator();
		cout << "Place your Bet Please : ";
		cin >> bMoney;
		int min = 0;
		int max = 0;
		int cardComp[3];
		bool playercontinue = true;


		if (bMoney > 0 && bMoney <= pMoney)
		{
			cout << endl;
			cout << "You Have Placed " << bMoney << " Gold to Bet " << endl;
			cout << endl;
			cout << "Pick One of Between Two Cards" << endl;
			seperator(); cout << endl;
			
			//첫번째 두카드 뽑기
			
			for (int i = 0; i < 2; i++)
			{
				picksuits = rand() % 4;
				picknums = rand() % 13;

				while (true) 
				{
					picksuits = rand() % 4;
					picknums = rand() % 13;
					if (cards[picksuits][picknums] != -1)
					{
						pickedcards[i] = cards[picksuits][picknums];
						if (i == 0)
						{
							cout << "1) ";
						}
						if (i == 1)
						{
							cout << "2) ";
						}

						if (picksuits == 0)
						{
							if (cards[picksuits][picknums] > 1 && cards[picksuits][picknums] < 11)
							{
								cout << cards[0][picknums] << " of " << " Spade" << endl;
							}
							if (cards[picksuits][picknums] == 1)
							{
								cout << "Ace of Spade" << endl;
							}
							if (cards[picksuits][picknums] == 11)
							{
								cout << "Jack of Spade" << endl;
							}
							if (cards[picksuits][picknums] == 12)
							{
								cout << "Queen of Spade" << endl;
							}
							if (cards[picksuits][picknums] == 13)
							{
								cout << "King of Spade" << endl;
							}
						}
						if (picksuits == 1)
						{
							if (cards[picksuits][picknums] > 1 && cards[picksuits][picknums] < 11)
							{
								cout << cards[picksuits][picknums] << " of " << " Diamond" << endl;
							}
							if (cards[picksuits][picknums] == 1)
							{
								cout << "Ace of Diamond" << endl;
							}
							if (cards[picksuits][picknums] == 11)
							{
								cout << "Jack of Diamond" << endl;
							}
							if (cards[picksuits][picknums] == 12)
							{
								cout << "Queen of Diamond" << endl;
							}
							if (cards[picksuits][picknums] == 13)
							{
								cout << "King of Diamond" << endl;
							}

						}
						if (picksuits == 2)
						{
							if (cards[picksuits][picknums] > 1 && cards[picksuits][picknums] < 11)
							{
								cout << cards[picksuits][picknums] << " of " << " Heart" << endl;
							}
							if (cards[picksuits][picknums] == 1)
							{
								cout << "Ace of Heart" << endl;
							}
							if (cards[picksuits][picknums] == 11)
							{
								cout << "Jack of Heart" << endl;
							}
							if (cards[picksuits][picknums] == 12)
							{
								cout << "Queen of Heart" << endl;
							}
							if (cards[picksuits][picknums] == 13)
							{
								cout << "King of Heart" << endl;
							}

						}
						if (picksuits == 3)
						{
							if (cards[picksuits][picknums] > 1 && cards[picksuits][picknums] < 11)
							{
								cout << cards[picksuits][picknums] << " of " << " Clover" << endl;
							}
							if (cards[picksuits][picknums] == 1)
							{
								cout << "Ace of Clover" << endl;
							}
							if (cards[picksuits][picknums] == 11)
							{
								cout << "Jack of Clover" << endl;
							}
							if (cards[picksuits][picknums] == 12)
							{
								cout << "Queen of Clover" << endl;
							}
							if (cards[picksuits][picknums] == 13)
							{
								cout << "King of Clover" << endl;
							}

						}
						cards[picksuits][picknums] = -1;
						break;
					}

				}
				//if (i == 0)
				//{
				//	cout << "1) ";
				//}
				//if (i == 1)
				//{
				//	cout << "2) ";
				//}

				//if (picksuits == 0)
				//{
				//	if (cards[picksuits][picknums] > 1 && cards[picksuits][picknums] < 11)
				//	{
				//		cout << cards[0][picknums] << " of " << " Spade" << endl;
				//	}
				//	if (cards[picksuits][picknums] == 1)
				//	{
				//		cout << "Ace of Spade" << endl;
				//	}
				//	if (cards[picksuits][picknums] == 11)
				//	{
				//		cout << "Jack of Spade" << endl;
				//	}
				//	if (cards[picksuits][picknums] == 12)
				//	{
				//		cout << "Queen of Spade" << endl;
				//	}
				//	if (cards[picksuits][picknums] == 13)
				//	{
				//		cout << "King of Spade" << endl;
				//	}
				//}
				//if (picksuits == 1)
				//{
				//	if (cards[picksuits][picknums] > 1 && cards[picksuits][picknums] < 11)
				//	{
				//		cout << cards[picksuits][picknums] << " of " << " Diamond" << endl;
				//	}
				//	if (cards[picksuits][picknums] == 1)
				//	{
				//		cout << "Ace of Diamond" << endl;
				//	}
				//	if (cards[picksuits][picknums] == 11)
				//	{
				//		cout << "Jack of Diamond" << endl;
				//	}
				//	if (cards[picksuits][picknums] == 12)
				//	{
				//		cout << "Queen of Diamond" << endl;
				//	}
				//	if (cards[picksuits][picknums] == 13)
				//	{
				//		cout << "King of Diamond" << endl;
				//	}

				//}
				//if (picksuits == 2)
				//{
				//	if (cards[picksuits][picknums] > 1 && cards[picksuits][picknums] < 11)
				//	{
				//		cout << cards[picksuits][picknums] << " of " << " Heart" << endl;
				//	}
				//	if (cards[picksuits][picknums] == 1)
				//	{
				//		cout << "Ace of Heart" << endl;
				//	}
				//	if (cards[picksuits][picknums] == 11)
				//	{
				//		cout << "Jack of Heart" << endl;
				//	}
				//	if (cards[picksuits][picknums] == 12)
				//	{
				//		cout << "Queen of Heart" << endl;
				//	}
				//	if (cards[picksuits][picknums] == 13)
				//	{
				//		cout << "King of Heart" << endl;
				//	}

				//}
				//if (picksuits == 3)
				//{
				//	if (cards[picksuits][picknums] > 1 && cards[picksuits][picknums] < 11)
				//	{
				//		cout << cards[picksuits][picknums] << " of " << " Clover" << endl;
				//	}
				//	if (cards[picksuits][picknums] == 1)
				//	{
				//		cout << "Ace of Clover" << endl;
				//	}
				//	if (cards[picksuits][picknums] == 11)
				//	{
				//		cout << "Jack of Clover" << endl;
				//	}
				//	if (cards[picksuits][picknums] == 12)
				//	{
				//		cout << "Queen of Clover" << endl;
				//	}
				//	if (cards[picksuits][picknums] == 13)
				//	{
				//		cout << "King of Clover" << endl;
				//	}

				//}

			}
			cout << endl;
			cout << "Type 1 or 2 to Pick Card : ";
			cin >> playercard;
			cout << endl;

			if (playercard == 1)
			{
				playercard = pickedcards[0];
				nonPickedCard = pickedcards[1];

			}
			if (playercard == 2)
			{
				playercard = pickedcards[1];
				nonPickedCard = pickedcards[0];
			}

			//마지막 카드 뽑기
			picksuits = rand() % 4;
			picknums = rand() % 13;

			while (true)
			{
				picksuits = rand() % 4;
				picknums = rand() % 13;
				if (cards[picksuits][picknums] != -1)
				{
					pickedcards[2] = cards[picksuits][picknums];

					if (picksuits == 0)
					{
						cout << "Last card is : ";
						if (cards[picksuits][picknums] > 1 && cards[picksuits][picknums] < 11)
						{
							cout << cards[0][picknums] << " of " << " Spade" << endl;
						}
						if (cards[picksuits][picknums] == 1)
						{
							cout << "Ace of Spade" << endl;
						}
						if (cards[picksuits][picknums] == 11)
						{
							cout << "Jack of Spade" << endl;
						}
						if (cards[picksuits][picknums] == 12)
						{
							cout << "Queen of Spade" << endl;
						}
						if (cards[picksuits][picknums] == 13)
						{
							cout << "King of Spade" << endl;
						}



					}
					if (picksuits == 1)
					{
						cout << "Last card is : ";
						if (cards[picksuits][picknums] > 1 && cards[picksuits][picknums] < 11)
						{
							cout << cards[picksuits][picknums] << " of " << " Diamond" << endl;
						}
						if (cards[picksuits][picknums] == 1)
						{
							cout << "Ace of Diamond" << endl;
						}
						if (cards[picksuits][picknums] == 11)
						{
							cout << "Jack of Diamond" << endl;
						}
						if (cards[picksuits][picknums] == 12)
						{
							cout << "Queen of Diamond" << endl;
						}
						if (cards[picksuits][picknums] == 13)
						{
							cout << "King of Diamond" << endl;
						}

					}
					if (picksuits == 2)
					{
						cout << "Last card is : ";
						if (cards[picksuits][picknums] > 1 && cards[picksuits][picknums] < 11)
						{
							cout << cards[picksuits][picknums] << " of " << " Heart" << endl;
						}
						if (cards[picksuits][picknums] == 1)
						{
							cout << "Ace of Heart" << endl;
						}
						if (cards[picksuits][picknums] == 11)
						{
							cout << "Jack of Heart" << endl;
						}
						if (cards[picksuits][picknums] == 12)
						{
							cout << "Queen of Heart" << endl;
						}
						if (cards[picksuits][picknums] == 13)
						{
							cout << "King of Heart" << endl;
						}


					}
					if (picksuits == 3)
					{
						cout << "Last card is : ";
						if (cards[picksuits][picknums] > 1 && cards[picksuits][picknums] < 11)
						{
							cout << cards[picksuits][picknums] << " of " << " Clover" << endl;
						}
						if (cards[picksuits][picknums] == 1)
						{
							cout << "Ace of Clover" << endl;
						}
						if (cards[picksuits][picknums] == 11)
						{
							cout << "Jack of Clover" << endl;
						}
						if (cards[picksuits][picknums] == 12)
						{
							cout << "Queen of Clover" << endl;
						}
						if (cards[picksuits][picknums] == 13)
						{
							cout << "King of Clover" << endl;
						}

					}
					cards[picksuits][picknums] = -1;
					break;
				}

			}



			min = pickedcards[0];
			max = pickedcards[0];

			for (int i = 0; i < 3; i++)
			{

				if (min > pickedcards[i])
				{
					min = pickedcards[i];
				}
				if (max < pickedcards[i])
				{
					max = pickedcards[i];
				}
			}


			if (playercard > min && playercard < max)
			{
				pMoney += bMoney*2;
				cout << endl;
				seperator();
				cout << "You Won !!!" << endl;
				seperator();
			}
			else
			{
				pMoney -= bMoney * 2;
				cout << endl;
				seperator();
				cout << "You Lost" << endl;
				seperator();
			}



			count +3;

		}
		else 
		{
			cout << endl;
			cout << "Please Bet Right Amount !!!!" << endl;
			cout << endl;
		}
		cout << endl;
		seperator();
		cout << "Type 1) to Continue or 2) to Quit : ";
		while(playercontinue != 1 || playercontinue !=2)
		{
			cin >> playercontinue;
		}
		
		if (pMoney <= 0) 
		{
			gametrig = false;
		}
		if (count > 17) 
		{
			gametrig = false;
		}


	}

}

int main()
{
	lobby();
	game();
}


