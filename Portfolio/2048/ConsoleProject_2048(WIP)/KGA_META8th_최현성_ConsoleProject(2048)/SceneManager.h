#pragma once
#include <iostream>
#include "StageScreen.h"
#include "LobbyScreen.h"
#include "GameOverScreen.h"
#include "ConsoleUtils.h"
#include <conio.h>
using namespace std;

class SceneManager
{
public:
    SceneManager();
    void StageScene(int size, int topscore, int currentscore, vector<vector<int>> grid,pair<int,int> newSpawn);
    void LobbyScene();
    void GameOverScene();
    void TestScenes();
    int StageSelect() { return LobbyScreen::StageSelect(); }
    int ContinueSelect(int topscore) { return GameOverScreen::ContinueSelect(topscore); }

};



