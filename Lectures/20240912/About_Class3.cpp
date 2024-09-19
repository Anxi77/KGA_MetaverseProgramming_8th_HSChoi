#include <iostream>

using namespace std;

//생성자 멤버 초기화 리스트
//멤버변수가 생성자 본문 안에서 초기화 되기 전에 직접 초기화
//멤버변수가 먼저 생성되고 나중에 값을 변경하는 것보다 효율적이다.
//생성자 매개변수 뒤에 삽입 ':' 콜론으로 시작한 다음 초기화 할 각 변수들을 쉼표로 구분하여 나열한다.
//상수 , 참조 멤버변수가 있다면 반드시 멤버초기화 리스트를 사용하여 초기화를 진행해야 한다 .


//destructor(소멸자)
//객체가 소멸될때 자동으로 호출되는 특별한 멤버함수.
//동적 메모리를 할당 해제할때 사용한다.
//매개변수를 가질 수 없다 . 반환값 X 오버로딩이 불가능


class Exam
{
public:
	//const
	const int num;

	//참조
	int& score;
	//Exam()//상수화 되어있는 변수나 , 참조타입인 경우엔 본문에서 초기화가 불가능하다 .  초기화 리스트를 통해 해야한다.
	//{
	//	//num = 1;
	//	score = 2;
	//}
	
	//상수와 참조멤버들은 반드시 아래와 같이 멤버 초기화 리스트를 활용.
	Exam(int num, int scord):num(num), score(score)
	{

	}
	
};

class MyClass
{
public:
	MyClass(int size);
	~MyClass();

private:
	int* data;
};

MyClass::MyClass(int size)
{
	data = new int[size]; //객체의 생성을 배열로 한다 . 
	cout << "여긴 생성자 영억" << endl;
}

MyClass::~MyClass()
{
	delete[] data;//반납하겠다는 뜻.
	data = nullptr;
	cout << "여긴 소멸자 영역" << endl;

}

class Monster 
{
private:

	string name;
	int mAtk;
	int mHealth;

public:
	//생성자 선언 및 멤버 초기화 리스트
	Monster(const string& monsterName, int monsterAtk, int monsterHealth)
		: name(monsterName), mAtk(monsterAtk), mHealth(monsterHealth)
	{
		//여기서 따로 초기화 할 필요가 없다 .
	};
};

int main()
{
	MyClass* m = new MyClass(10);

	delete m;
	m = nullptr;

}