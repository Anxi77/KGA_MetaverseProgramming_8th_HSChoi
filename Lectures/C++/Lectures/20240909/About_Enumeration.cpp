/*
---------사용자 정의 자료형---------

클래스 , 열거타입 , 구조체

-열거형
ㄴ상수집합에 이름을 붙여서 사용하는 데이터타입
ㄴ코드의 가독성을 높임
ㄴ기본적으로 정수타입으로 처리가 되며 자동으로 0부터 1씩 증가한다.
ㄴ명시적으로 값을 지정할 수 있다.

	//구버전(C++11 이전)
	enum MyEnum
	{

	};
	//범위 기반 열거형(C++11 부터 지원)
	//이름 충돌을 방지. 타입에 대한 안정성을 높임
	enum class MyEnumClas
	{

	};

*C Style의 형변환*
* C에서는 두가지의 형변환이 주로 사용됨
- 묵시적 형변환 (TypeCasting)
ㄴ 컴파일러가 자동으로 수행함.
e.g)
int a = 5;
float b = 3.14;
float res = a+b; <- 정수타입이었던 a를 float타입으로 변환해준다.

-명시적 형변환
ㄴ사용자(프로그래머)가 직접 변환을 명시한다.()

int a = 5;
float b = 3.14;
int res = a+(int)b;

*C++ 의 형변환*
e.g)
int a = 10;
-static_cast<double>(a)

*/




#include <iostream>

using namespace std;


enum Color
{
	Red,    //0
	Green,  //1
	Black   //2
	//마지막 항목은 , 를 찍지 않는다
};

enum maptype
{
	jungle,
	tundra,
	desert
};

class map
{
public:
	string intro;
};

enum Direction
{
	Left = 1, //명시적으로 값을 지정 가능.
	Right,
	Up,
	Down
};
enum class Location
{
	Inven,
	Town,
	Shop
};
enum class Character
{
	Knight = 1,
	Archer,
	Mage,
	None

};

Character GetCharacter(int n)
{
	switch(n)
	{
	case 1: return Character::Knight;
	case 2: return Character::Archer;
	case 3: return Character::Mage;
	}
}

int main()
{
	map m;
	m.intro = maptype.desert;


	Color c = Red;
	cout << c << endl;
	Location loc = Location::Inven; // 범위지정 연산자::를 통하여 명시적으로 열거타입을 지정해야한다.

	switch (c)
	{
	case Red:
		cout << "빨간색" << endl;
		break;
	case Green:
		cout << "초록색" << endl;
		break;
	case Black:
		cout << "검은색" << endl;
		break;
	default:
		break;
	}

	//암묵적으로 형변환을 해줌
	int dirSelect;
	cin >> dirSelect;
	switch (dirSelect)
	{
	case Direction::Left:
		cout << "왼쪽" << endl;
		break;
	case Direction::Right:
		cout << "오른쪽" << endl;
		break;
	case Direction::Up:
		cout << "위" << endl;
		break;
	case Direction::Down:
		cout << "아래" << endl;
		break;

	}


	int characterSelect;
	cin >> characterSelect;

	Character selectCharacter = static_cast<Character>(characterSelect);

	//범위기반 enum class는 명시적으로 형변환을 해줘야함.
	switch (selectCharacter)
	{

	case Character::Knight:
		cout << "나이트를 선택" << endl;
		break;
	case Character::Archer:
		cout << "아처를 선택" << endl;
		break;
	case Character::Mage:
		cout << "메이지를 선택" << endl;
		break;
	default:
		break;
	}

	Character ch = Character::None;
	int input;
	cin >> input;
	ch = GetCharacter(input);


	


	switch(loc)
	{
	case Location::Inven:
		break;
	case Location::Town:
		break;
	case Location::Shop:
		break;
	default:
		break;
	}
}
