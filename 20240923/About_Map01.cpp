#include "SceneManager.h"
/*

system("cls")는 C와 C++에서 콘솔 화면을 지우는 데 사용되는 명령어

*/

#include <iostream>
#include <map>

using namespace std;

class Armor
{

public:

	Armor() :name(""), def(0) {}
	Armor(const string n, int d) : name(n), def(d) {}


	string GetName()const { return name; }
	int GetDef()const { return def; }

private:

	string name;
	int def;
};

class Scene
{
private:

	string desc;

public:

	Scene() :desc("") {}
	Scene(const string& d) : desc(d) {}

	string GetDescription()const { return desc; }
};

class SceneManager
{
private:
	//씬의 이름을 키로 하고 씬 포인터를 값으로 저장하는 map
	map<string, Scene*>scenes;
	Scene* currentScene; //현재 씬을 가리키는 포인터
	string currentSceneName; //현재 씬의 이름


public:

	SceneManager() :currentScene(nullptr), currentSceneName("") {}
	~SceneManager()
	{
		//map 에 저장된 모든 씬을 돌면서 해제
		for (auto& pair : scenes)
		{
			delete pair.second;
		}
	}

public:

	//씬을 추가하는 함수
	void AddScene(const string& name, Scene* scene)
	{
		scenes[name] = scene; //씬의 이름을 키값으로 하고 포인터를 값으로 저장
	}

	//씬을 삭제하는 함수
	void RemoveScene(const string& name)
	{
		auto it = scenes.find(name);//씬 이름으로 map에서 찾음.
		//씬이 존재하면
		if (it != scenes.end())
		{
			delete it->second;//동적으로 할당된 씬 객체 해제
			scenes.erase(it);//map 에서 삭제
		}
	}

	void SceneManager::AddScene(const std::string& name, const std::string& desc)
	{
	}

	//씬을 설정하는 함수
	void SetCurrentScene(const string& name)
	{
		auto it = scenes.find(name);//씬 이름을 map에서 찾음.

		if (it != scenes.end())
		{
			currentScene = it->second;
			currentSceneName = name;
		}
		else
		{
			cout << "찾을 수 없음 ! " << endl;
		}

	}


	//출력하는 함수

	void ShowCurrentScene() const
	{
		if (!currentSceneName.empty())
		{
			cout << "현재 씬: " << currentSceneName << endl;
			cout << "설명: " << currentScene->GetDescription() << endl;
		}
		else
		{
			cout << "현재 설정된 씬이 없습니다." << endl;
		}
	}


};



int main()
{
	//key == string , 값 == Armor객체
	//map<string, Armor>armorMap;
	//armorMap.insert(make_pair("helmet", Armor("철모자", 5)));
	//armorMap.insert(make_pair("sheild", Armor("나무방패", 5)));
	//armorMap.insert(make_pair("greaves", Armor("신발", 5)));
	//armorMap.insert(make_pair("ㅇㅇㅇ", Armor("갑옷", 5)));

	//cout << "전체 방어구 목록 : " << endl;
	//for (const auto& pair : armorMap)
	//{
	//	cout << "키값 : " << pair.first << endl;
	//	cout << "방어구 이름 : " << pair.second.GetName() << endl;
	//	cout << "방어력 : " << pair.second.GetDef() << endl;
	//	cout << endl;
	//}
	//cout << "========================================================" << endl;

	//string searchKey;
	//cout << "검색할 방어구의 키를 입력해라 : ";
	//cin >> searchKey;

	//auto it = armorMap.find(searchKey);

	//if(it !=armorMap.end())
	//{
	//	cout << "찾은 방어구" << endl;
	//	cout << "이름 : " << it->second.GetName() << endl;
	//	cout << "방어력 : " << it->second.GetDef() << endl;
	//}
	//else
	//{
	//	cout << "방어구를 찾을 수 없다 ! " << endl;
	//}


	SceneManager* sceneManager = new SceneManager();

	sceneManager->AddScene("Main Menu", new Scene("메인 메뉴 : 시작 , 옵션 , 종료"));
	sceneManager->AddScene("Level 1", new Scene("레벨 1 : 첫번째 레벨"));

	sceneManager->SetCurrentScene("Main Menu");
	sceneManager->ShowCurrentScene();

	sceneManager->SetCurrentScene("Level 1");
	sceneManager->ShowCurrentScene();

	sceneManager->RemoveScene("Main Menu");

	sceneManager->SetCurrentScene("oooo");
	sceneManager->ShowCurrentScene();

}