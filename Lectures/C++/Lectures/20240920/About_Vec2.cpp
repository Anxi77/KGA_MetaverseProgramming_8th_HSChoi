/*
과제
1. 벡터를 이용한 캐릭터 정보 출력하기(반복문 사용)



*/

#include <iostream>
#include <vector>

using namespace std;

class Weapon
{
public:
	Weapon(const string& name, int damage)
		:name(name), damage(damage) {}
	void Print()const
	{
		cout << "이름 : " << name << " , 공격력 : " << damage << endl;
	}
private:
	string name;
	int damage;
};


//벡터를 값으로 전달하는 함수를 만든다면

void PrintVectorValue(vector<int> vec)
{
	for(auto& vec : vec)
	{
		cout << vec << endl;
	}
}

//벡터를 참조로 전달하는 함수

void PrintVectorRef(vector<int>& vec)
{
	for (auto& vec : vec)
	{
		cout << vec << endl;
	}
}



int main()
{
	//웨폰 객체를 저장할 벡터생성
	vector<Weapon> weapon;

	weapon.push_back(Weapon("장검", 50));
	weapon.push_back(Weapon("화살", 50));
	weapon.push_back(Weapon("도끼", 50));
	weapon.push_back(Weapon("단검", 50));

	cout << "무기정보 " << endl;
	//벡터의 모든 무기 정보 출력
	for (const auto& w : weapon)
	{
		w.Print();
	}
	cout << endl;
	vector<Weapon*> weapons;
	weapons.push_back(new Weapon("q검", 10));
	weapons.push_back(new Weapon("ㅁ검", 10));
	weapons.push_back(new Weapon("ㅈ검", 10));
	weapons.push_back(new Weapon("ㄷ검", 10));
	weapons.push_back(new Weapon("ㄱ검", 10000));

	for(const auto& weapon : weapons)
	{
		weapon->Print();
	}
	for(auto& weapon : weapons)
	{
		delete weapon;
	}

}