#pragma once
#include "SceneManager.h"
#include "GridManager.h"
#include "ConsoleUtils.h"
#include <fstream>
#include <string>

using namespace ConsoleUtils;

class GameManager
{
public :
	void GameStart();
	GameManager();
	~GameManager();
private:
	bool GameVali(vector<vector<int>>& grid, int size);
	void SaveGame(int topscore, const vector<vector<int>>& grid);
	void LoadGame(int& topscore, vector<vector<int>>& grid);
	int topscore;
	vector<vector<int>> savedGrid;
	const string SAVE_FILE = "2048_save.txt";
};

