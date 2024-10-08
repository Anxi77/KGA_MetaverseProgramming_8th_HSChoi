/*
constructor
-객체가 생성될 때 자동으로 호출되는 특별한 멤버함수.
-객체의 초기화를 담당한다 .
-클래스와 동일한 이름을 가지며 반환타입이 없다 .
-생성자 기본생성자 , 매개변수가 있는 생성자 , 복사생성자 등이 있다.

1. 기본생성자
-매개변수가 없는 생성자. 
-명시적으로 정의하지 않는다면 컴파일러가 자동으로 제공한다 .

실습 사각형 클래스 만들고
가로세로
면적 출력하는 함수를 만들어라

*/

#include <iostream>

using namespace std;

class Player
{
private:
	string mName;
	int mAtk;
	int mDef;

public:
	//기본생성자
	Player()
	{
		cout << "나는 생성자임 !" << endl;
	}
	//매개변수가 있는 생성자
	Player(const string& playerName,const int playerAtk,const int playerDef)
	{
		mName = playerName;
		mAtk = playerAtk;
		mDef = playerDef;
	}
	void PrintInfo()const;


};

void Player::PrintInfo() const
{
	cout << "이름 : " << mName << endl;
	cout << "공격력 : " << mAtk << endl;
	cout << "방어력 : " << mDef << endl;
}

int main()
{
	//정적할당
	//Player p;

	//동적할당
	Player* player = new Player;//명시적으로 생성자를 명시한것
	player->PrintInfo();
	Player* player1 = new Player();

	("김김김", 10, 20);
	player1->PrintInfo();


	delete player;
	delete player1;

	player = nullptr;//메모리 안정성을 위해 삭제를 하더라도 해당 포인터는 아무것도 가리키지 않는다라는 명시.
	player1 = nullptr;
}