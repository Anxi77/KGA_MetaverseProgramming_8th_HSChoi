/*
==========================================================
static
-클래스 내의 static 변수 및 함수
1. 클래스 정적멤버변수 : 모든 클래스 인스턴스가 공유하는 변수
ㄴ클래스의 모든 인스턴스가 해당 변수에 접근이 가능.하나의 인스턴스에서 변수를 수정하면 다른 인스턴스에 반영

2. 클래스 정적멤버 함수 :  클래스의 인스턴스 없이 호출할수 있는 함수
ㄴ정적멤버함수는 클래스의 정적멤버변수에만 접근이 가능. 인스턴스 멤버변수나 함수에는 접근 불가

==========================================================

*/

#include<iostream>

using namespace std;

class Count {
private:
	int num;//멤버변수

	static int count;//정적 멤버변수
public:
	Count() 
	{
		count++;
	}

	void Print() {

	}
	//정적 멤버함수
	static int GetCount() {

		//인스턴스 멤버변수는 접근불가
		//num = 1;
		//멤버 함수 접근불가
		//Print();
		return count;

	}
};
//초기화
int Count::count = 0;

int main() 
{
	Count c1;
	Count c2;
	Count c3;

	cout << Count::GetCount() << endl;
}