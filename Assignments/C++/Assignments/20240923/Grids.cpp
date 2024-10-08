#include "Grids.h"

Grids::Grids()
{
	for(int i = 0; i < 16; i++)
	{
		for(int j = 0; j <16; j++)
		{
			mapCord[i][j] = " ";
		}
	}
}

int ranNumGen() 
{
	// 정적 변수로 난수 생성기 선언
	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_int_distribution<> dis(0, 15);

	return dis(gen);
}

void Grids::ObstacleGenerator()
{
	for (int i = 0; i < 16; i++)
	{
		int x = ranNumGen();
		int y = ranNumGen();
		if (mapCord[x][y] == " ") // 중복 검사
		{
			mapCord[x][y] = "∇"; // '■' 대신 '#' 사용
		}
		else
		{
			i--; // 중복 시 다시 시도
		}
	}
	mapCord[7][15] = "▶";
}

void Grids::mapDisplay(int stage)
{
	cout << "Stage " << "[" << stage << "]" << endl;
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if(mapCord[i][j] == " ")
			{
				cout.width(3);
				cout << "▥";
			}
			else
			{
				cout.width(3);
				cout << mapCord[i][j];
			}
			
		}
		cout << endl;
	}
	cout << "Move Player To  ▶ Get To Next Level" << endl;
}

string Grids::GetMapCord(int x,int y)
{
	return mapCord[x][y];
}

void Grids::SetMapCord(string Player,int x ,int y)
{
	mapCord[x][y] = Player;
}
