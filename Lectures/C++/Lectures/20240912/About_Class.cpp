/*
==========================================
class
-객체지향 기법은 소프트웨어 설계에 있어 많은 장점을 제공하는 강력한 기술
ㄴ개념을 이해하기 까다롭다.
-객체
ㄴ클래스는 객체를 정의하는 틀이자 설계도이다.(모양자 비유)
ㄴ객체는 설계도(클래스)를 기반으로 실체화 시키는 것이다. -> 그래야 사용이 가능하니까
ㄴ인스턴스화 : 클래스를 사용하여 객체를 생성하는 과정을 의미한다.
==========================================

*/
/*
class 자동차
{
private:
//멤버변수(속성->자동차를 구성하는 부품 > 숨겨야한다.)

public:
//멤버함수(기능->브레이크,페달,방향지시등... > 우리가 이용해야한다 -> 노출)


}
============================================
-접근제어지시자
-private: 숨겨야 할 멤버 변수등을 이곳에 사용
ㄴ클래스의 default 가 된다.

-public: 외부에서 자유롭게 참조할 수 있다.
ㄴ외부에서 직접적으로 멤버들을 조작할 수 있기 떄문에 공개할 기능들 이곳에 사용
-protected : 상속 관계에서만 허용해준다.

//접근제어		클래스내부		클래스 외부		상속클래스
//private			O				X				X
//public			O				O				O				
//protected			O				X				O

============================================
*/

#include <iostream>

using namespace std;

class Student
{
public://접근제어
	Student(); //생성자
	~Student();//소멸자
	//외부에서 호출하기 때문에 public에 있어야한다.

	//멤버함수
	void Print() { cout << "스튜던트 클래스의 프린트 함수"; }
	void Print(int a, int b) { cout << a << " , " << b << endl; }
	void Print(string str = "디폴트 매개변수") { cout << str << endl; }

	//클래스 내부에 원형만
	int sum(int a, int b);
private://접근제어

};

int Student::sum(int a , int b)
{
	return a + b;
}

struct Circle : public CCircle
{
//public : 묵시적으로 들어가 있다.
	int radius;
	string color;

	double calcArea()
	{
		return 3.14 * radius * radius;
	}
};

class CCircle
{
//private : 묵시적으로 들어가 있다.
	int radius;
	string color;


	double calcArea()
	{
		return 3.14 * radius * radius;
	}
};

int main()
{
	Circle c;
	c.radius = 5;
	c.calcArea();





}