/*
-과제
맵 한개를 임의적으로 그려서
장애물 배치 장애물은 지나갈 수 없음.

던전 입구 통해서 다음 맵으로 진행
*/


#include <iostream>
#include "Grids.h"
#include "Character.h"
#include <cstdlib>
#include <conio.h>
#include <Windows.h>


using namespace std;

void Move(Grids& m, Character& c,int stage)
{
    char Movetrig;
    cout << "W : Up , A : Left , S : Down , D : Right" << endl;
    Movetrig = _getch();
    while (_kbhit()) _getch();
    Sleep(7);
    int dx = 0, dy = 0;
    if (Movetrig == 'w' || Movetrig == 'W') dy = -1;
    else if (Movetrig == 'a' || Movetrig == 'A') dx = -1;
    else if (Movetrig == 's' || Movetrig == 'S') dy = 1;
    else if (Movetrig == 'd' || Movetrig == 'D') dx = 1;
    else {
        system("cls");
        cout << "Invalid input!" << endl;
        Sleep(333);
        m.mapDisplay(stage);
        return;
    }

    int playerX = -1, playerY = -1;
    for (int i = 0; i < 16; i++) 
    {
        for (int j = 0; j < 16; j++) 
        {
            if (m.GetMapCord(i, j) == "★") 
            {
                playerX = i;
                playerY = j;
                break;
            }
        }
        if (playerX != -1) break;
    }

    int newX = playerX + dy;
    int newY = playerY + dx;

    if (newX >= 0 && newX < 16 && newY >= 0 && newY < 16 && m.GetMapCord(newX, newY) != "∇") 
    {
        m.SetMapCord(c.Player, newX, newY);
        m.SetMapCord(" ", playerX, playerY);
    }
    else 
    {
        cout << "Can't Move !!" << endl;
        Sleep(100);
    }
}

int main()
{
	Grids m;
	Character c;
    int stage = 1;
    bool GameTrig = true;
    while (GameTrig) 
    {
        bool ContTrig = true;
        int ContNum = 0;
        m.ObstacleGenerator();
        m.SetMapCord(c.Player, 0, 0);
        while (m.GetMapCord(7, 15) == "▶")
        {
            cout << endl;
            m.mapDisplay(stage);
            Move(m, c,stage);
            system("cls");
        }
        while(ContTrig)
        {
            int PTrigin = 0;
            cout << "1) Continue , 2) Quit : ";
            cin >> PTrigin;
            if(PTrigin == 1)
            {
                ContTrig = false;
                ++stage;
                system("cls");
                cout << "Next Stage";
                for(int i = 0; i < 7; i++)
                {
                    cout << ".";
                    Sleep(77);
                }
                system("cls");
                break;
            }
            else if (PTrigin == 2)
            {
                ContTrig = false;
                GameTrig = false;
                system("cls");
                cout << "GG's" << endl;
                break;
            }
            else
            {
                cout << "Please Enter Right Number !!!" << endl;
                system("cls");
                Sleep(333);
            }
        }
    }
	
}