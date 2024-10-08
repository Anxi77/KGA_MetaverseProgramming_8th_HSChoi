/*
- singleton
ㄴ오직 한개의 인스턴스만을 갖도록 보장
ㄴ즉 아무리 많은 객체를 생성해도 단 하나의 인스턴스만을 생성한것과 같다.
ㄴ클래스의 객체가 복사가 되면 X. 
*/
#include<iostream>

using namespace std;
class Singleton 
{
private:
	Singleton() {
		cout << "싱글톤 인스턴스 생성" << endl;
	}
	~Singleton(){}

	//복사생성자와 대입연산자 방어
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
public:

	static Singleton& GetInstance() 
	{
		static Singleton inst;
		return inst;
	 }

	void Print() {
		cout << "나는 싱글톤이라고해" << endl;
	}
};

int main() {

	Singleton& s1 = Singleton::GetInstance();
	s1.Print();

	Singleton& s2 = Singleton::GetInstance();
	s1.Print();

	if (&s1 == &s2) {
		cout << "같아용!@" << endl;
	}


}
