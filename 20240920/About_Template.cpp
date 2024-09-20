/*
템플릿

프로그래머가 지정한 자료형에 함수나 클래스를 컴파일 시간에 생성하는 것

<함수템플릿> 
- 함수에 필요한 자료형을 선언하고 함수 호출시 자료형을 지정해주어 사용한다.
- 템플릿으로 작성한 함수를 호출하는 때에 자료형에 맞는 함수를 생성하여 사용하게 된다.

<클래스템플릿>
- 다양한 데이터 타입을 지원하는 클래스를 정의할수 있게 해준다.
- 템플릿 매개변수를 통해 클래스의 멤버변수와 멤버함수의 타입을 일반화 할 수 있다.
- 클래스에 필요한 자료형을 선언하고 클래스 자료형을 지정한다.
- 템플릿으로 작성한 클래스를 호출하는 때에 자료형에 맞는 클래스를 생성하여 사용된다.

*/

template <typename T>
T GetMax(const T x, const T y)
{
	if (x > y)return x;
	else return y;
}

template <typename T>
void Output (const T data)
{
	cout << "데이터 " << data << endl;
}

template <typename T1,typename T2>
void Output1(T1 a,T2 b)//타입네임이 하나인 경우 매개변수 타입이 다르면 실행되지 않는다.
{
	cout << a << " , " << b << endl;
}

template <typename T>
class Box
{
private:
	T data;
public:
	void SetData(T data) { this->data = data; }
	T getData() { return data; }
};

template <typename T1, typename T2>
class Box2
{
private:
	T1 firstData;
	T2 secondData;
public:
	T1 GetFirst();
	T2 GetSecond();

	void SetFrist(T1 val) { firstData = val; }
	void SetSecond(T2 val) { secondData = val; }
};

template<typename T1, typename T2>
T1 Box2<T1, T2>::GetFirst()
{
	return firstData;
}

template<typename T1, typename T2>
T2 Box2<T1, T2>::GetSecond()
{
	return secondData;
}

#include <iostream>
#include <vector>

using namespace std;

//int GetMax(int x, int y)
//{
//	if (x > y)return x;
//	else return y;
//}
//
//float GetMax(float x,float y)
//{
//	if (x > y)return x;
//	else return y;
//}
//위에 있는 함수를 템플릿화(함수템플릿)


int main()
{
	Output(1);
	Output("1wqwd");
	Output(1.5);
	Output1(1, 2);
	Output1(1, 1.5);

	Box<int> box;
	box.SetData(100);
	cout << box.getData() << endl;
	Box<double> box1;
	box1.SetData(3.14);
	box1.getData();
	Box2<int,double> box2;
	box2.SetFrist(10);
	box2.SetSecond(2.21);
}

