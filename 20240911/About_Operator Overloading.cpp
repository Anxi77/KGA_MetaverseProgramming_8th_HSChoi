/*
==================================================================================
*연산자 재정의(Operator Overloading)
- 사용자 정의 자료형이나 클래스의 연산자를 재정의 하여 여러 의미로 사용한다.
- 객체간의 산술연산, 비교, 대입 등을 가능하게 한다.
- 단, 일부 연산자는 오버로딩을 할 수 없다.

<연산자 재정의>
//반환형 operator연산자기호(매개변수){함수내용}
//기본 연산자의 연산을 함수를 재정의하여 기능을 구현
==================================================================================
const : 상수 (변하지 않는 수)
ㄴconst int(자료형) num(변수명)
ㄴ데이터가 변경되지 않도록 보호해준다.
ㄴ의도하지 않은 변경을 사전에 방지
ㄴ데이터 , 포인터 , 변수 등등 다양한 곳에 사용이 가능하다 .
*/




#include <iostream>

const int MAX = 10;

using namespace std;

struct Point
{
	float x;
	float y;

	Point(float x, float y) //생성자 C++에서만 지원함
	{
		this->x = x; // this : 내 자신을 가르키는 포인터
		this->y = y;
	}
	//1.멤버함수를 통한 연산자 재정의
	Point operator+(const Point& other)
	{
		return Point(this->x + other.x, this->y + other.y);
	}
	void Test()const
	{
	}
	//Point 구조체의 멤버함수
	void Print()const //const로 선언된 함수 내부에서는 const로 선언되지 않은 함수를 호출할 수 없다.
	{
		Test();
		cout << "(" << x << " , " << y << ")" << endl;
	}
	float GetX()const //읽기전용 함수로 생성한다는 뜻(멤버변수를 변경하지 않겠다)
	{
		return this->x;
	}
};


//2.전역함수를 통한 연산자 재정의
Point operator-(const Point& left,const Point& right)
{
	return Point(left.x - right.x, left.y - right.y);
}

void PrintArr(const int arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
	//arr[0] = 5; 배열 변경 불가

	int* n = new int n;
}


int main()
{
	int arr[MAX];

	for (int i = 0; i < MAX; i++)
	{

	}

	Point vec1 = Point(2, 1);
	Point vec2 = Point(3, 1);

	Point add = vec1 + vec2;
	Point sub = vec1 - vec2;

	add.Print();
	sub.Print();



}