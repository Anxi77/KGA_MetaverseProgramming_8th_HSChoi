#pragma once
#include <iostream>
#include <random>

using namespace std;

class Grids
{
private:
	string mapCord[16][16];
public:
	Grids();
	void ObstacleGenerator();
	void mapDisplay(int stage);
	string GetMapCord(int x ,int y);
	void SetMapCord(string Player,int x , int y);
};

