#include <iostream>

using namespace std;


struct student
{
	string name;
	int age;
	int phonenumber;

	void findinfobyphonenumber();
};

void findinfobyphonenumber(int phonenumber, student st[])
{
	for(int i = 0; i < 3; i++)
	{
		if(phonenumber == st[i].phonenumber)
		{
			cout << "입력해주신 전화번호의 학생의이름은 : " << st[i].name;
		}
	}
}

int main()
{

	
	student st[3];

	for (int i = 0; i < 3; i++) 
	{
		cout << "학생의 이름을 입력해 주세요 : ";
		cin >> st[i].name;
		cout << "학생의 전화번호를 입력해 주세요 : ";
		cin >> st[i].phonenumber;
	}
	
	int phonenumber = 0;
	cout << "찾으실 학생의 전화번호를 입력해 주세요 : ";
	cin >> phonenumber;
	findinfobyphonenumber(phonenumber,st);
}