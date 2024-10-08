




#include<iostream>
using namespace std;
class Person
{
private:
	string name;
	int age;
public:

	//get
	string GetName()const { return name; }

	//set
	void SetName(const string& s) { name = s; }

	int GetAge()const { return age; }
	void SetAge(int a) { age = a; }

};
//해볼것.
//사각형 클래스를 만들고
//get, set을 활용하여 가로, 세로를 셋팅
// 면적을 계산하는 get 함수를 만들어라.


int main() {
	Person p;
	p.SetName("홍길동");
	p.SetAge(10);

	cout << "이름 : " << p.GetName() << endl;
	cout << "나이 : " << p.GetAge() << endl;
}