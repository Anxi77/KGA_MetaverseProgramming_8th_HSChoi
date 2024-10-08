#pragma once
#include"singleton.h"
#include"Scene.h"
#include<iostream>
#include<map>
class SceneManager : public CSingleton<SceneManager>
{
private:
	std::map<std::string, Scene*>scenes;
	Scene* currentScene = nullptr;
public:
	SceneManager();
	~SceneManager();

	void AddScene(const std::string& name, const std::string& desc);
	void SetCurrentScene(const std::string& name);
	void ShowCurrentScene()const;
};


