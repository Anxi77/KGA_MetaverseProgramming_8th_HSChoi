#include<iostream>
using namespace std;

/*
===============================================
상속
-무엇은 무엇의 한 종류다.
-기존 클래스(기반, 부모)를 재사용해서 새로운 클래스 생성
ㄴ부모 : 공통속성과 메서드를 제공
ㄴ자식 : 기반(부모)클래스에 상속받아 새로운 속성과 메서드를 추가하거나 기존것을 재정의

부모->자식
-클래스간의 상속관계를 맺을 때는 공통의 기능을 상위 클래스에 묶어 넣어 다른 클래스로
확장할수 있게 하는 것이 목적.

만약 클래스들이 서로 비슷한 또는 완전히 같은 코드를 가지고 있다면 해당코드를
상위클래스로 묶어 내는 것을 고려하는 것이 좋다.

ex)유닛클래스
- 이름, 공격력, 데미지...
- 공격하기, 스킬쓰기, 도망가기..행동..
ex)몬스터클래스
- 이름, 공격력, 데미지../.
- 공격하기, 스킬쓰기, 도망가기..행동..

===============================================
*/

//상속을 쓰지 않았을때
//워리어 클래스
//class Warrior {
//
//private:
//	string name;
//	int health;
//
//public:
//	Warrior(const string& n, const int h):name(n),health(h){}
//
//	void Attack() {
//		cout << name << "이(가) 검을 휘두른다" << endl;
//	}
//	void TakeDamage(const int damage) 
//	{
//		health -= damage;
//		cout << name << "이(가)" << damage << "만큼 먹음! 체력 : " << health<<endl;
//	}
//};
//class Mage {
//private:
//	string name;
//	int health;
//public:
//	Mage(const string& n, const int h):name(n), health(h){}
//
//	void Skill() {
//		cout << name << "이(가) 아이스볼 발사" << endl;
//	}
//	void TakeDamage(const int damage)
//	{
//		health -= damage;
//		cout << name << "이(가)" << damage << "만큼 먹음! 체력 : " << health << endl;
//	}
//
//};
//상속으로
//부모(기반)
class Character
{
protected:
	string name;
	int health;

public:
	
	Character(const string& n, const int h):name(n),health(h) {
		cout << "부모 클래스 Character  생성자 호출" << endl;
	}
	~Character()
	{
		cout << "부모클래스 Character소멸자 호출" << endl;
	}
	void TakeDamage(int damage) {
		health -= damage;
		cout << name << "이(가)" << damage << "의 피해를 입음. 남은 체력 : " << health << endl;
	}
	
};

//파생클래스
class Warrior : public Character {

public:
	//Character(n,h) : 자식클래스 warrior가 부모클래스인 Character 의 생성자를 호출
	Warrior(const string& n, const int h) : Character(n,h)
	{
		cout << "자식 클래스 Warrior 생성자 호출" << endl;
	}
	~Warrior()
	{
		cout << "자식 클래스 Warrior 소멸자 호출" << endl;
	}
		void Attack() {
		cout << name << "이(가) 검을 휘두른다" << endl;
	}
		

};
class Mage : public Character
{
public:

	Mage(const string& n, const int h) : Character(n, h) 
	{
		cout << "자식 클래스 Mage 생성자 호출" << endl;
	}
	~Mage()
	{
		cout << "자식 클래스 Mage 소멸자 호출" << endl;
	}
	void Skill()
	{
		cout << name << "이(가) 아이스볼 발사" << endl;
	}

};


int main() 
{
	Warrior* w = new Warrior("토르", 100);
	w->Attack();
	w->TakeDamage(10);

	Mage* m = new Mage("간달프", 90);
	m->Skill();
	m->TakeDamage(20);

	delete w;
	delete m;
}