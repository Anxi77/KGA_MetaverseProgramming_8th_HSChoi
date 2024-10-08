#include "SceneManager.h"

SceneManager::SceneManager()
{
	std::cout << " 씬 매니저 인스턴스 생성" << std::endl;
}

SceneManager::~SceneManager()
{

	for (auto& pair : scenes)
	{
		delete pair.second;
	}
}

void SceneManager::AddScene(const std::string& name, const std::string& desc)
{
	scenes[name] = new Scene(name, desc);
}

void SceneManager::SetCurrentScene(const std::string& name)
{
	if (scenes.find(name) != scenes.end()) {
		currentScene = scenes[name];
		std::cout << "현재 씬이 " << name << "설정" << std::endl;
	}
	else {
		std::cout << "찾을 수 없다." << std::endl;
	}
}

void SceneManager::ShowCurrentScene() const
{
	if (currentScene) {
		currentScene->Print();
	}
	else {
		std::cout << "설정된 씬이 없음" << std::endl;
	}
}
