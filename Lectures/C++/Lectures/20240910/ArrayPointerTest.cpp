#include <iostream>

using namespace std;


struct student
{
	int age;
	string name;
};

void calculate(student* s)
{
	s->age; //포인터로 구조체 안에 있는 요소에 접근하려면 ->를 이용하여 접근이 가능하다.
}

int main()
{
	int num[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* pnum = num;
	int sum = 0;
	//for(int i = 0; i < 10; i++)
	//{
	//	sum += *(pnum + i);
	//}
	while(pnum-num<10)//포인터가 배열의 끝을 넘지 않을때까지 반복
	{
		sum += *pnum;
		pnum++;
	}
	cout << "합계는 : " << sum << endl;

}