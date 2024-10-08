/*
Struct
<구조체>
-구조체는 여러개의 변수를 묶어 하나의 데이터 단위를 정의하는 사용자 정의 데이터 형식이다.
-구조체는 각각의 변수를 멤버로 가지고 이러한 멤버들은 서로 다른 데이터 타입일수 있다.
-C++에서는 함수도 포함이 가능하다.

	struct(구조체라는 것을 선언) MyStruct(구조체 이름)
	{

	};



과제
함수 , 구조체 , 열거타입
월남뽕 , 숫자야구
쪼갤수 있을만큼 쪼개보기
함수로 나누기

카드를 나타내는 구조체
문양을 나타내는 열거형

구조화 연습


*/

#include <iostream>

using namespace std;
//키워드 | 구조체 이름
struct Student 
{
	string name;// 학생이름
	int age;
	int phoneNumber;

};
struct Test
{
	short a;//2바이트
	int b;  //4바이트
	char c; //1바이트
};
//CPU -> 4byte씩 계산하는것이 빠르다. 4바이트씩 끊기 때문에 , short 가 4바이트를 차지하게 되고 , char도 4바이트를 차지하게 되서 총 사이즈가 12바이트가 된다.
struct Point
{
	int x;
	int y;
	void Print();//C++에서는 함수도 멤버로 가능하다

};
struct Person
{
	string name;
	string phoneNumber;
	int age;
};
struct Point1
{
	double x;
	double y;
};
double CalculateDistance(Point1 p1, Point1 p2)
{
	double deltaX = p2.x - p1.x;
	double deltaY = p2.y - p1.y;

	return sqrt(deltaX * deltaX + deltaY * deltaY);//제곱근을 구해주는 함수
}
struct StudentInfo
{
	string name;
	int age;
	int math;
	int english;
	int science;
	void calculatePoints();
	
};

void calculatePoints(int math, int english , int science)
{
	int res;
	res = 0;
	res = (math + english + science) / 3;
	cout << "평균 점수는" << (math + english + science) / 3 << endl;
}
int main()
{
	//구조체 변수 생성
	Student st;

	//구조체 멤버에 값을 할당
	st.name = "홍길동";
	st.age = 10;
	st.phoneNumber = 1234;

	//멤버에 할당된 데이터 출력
	cout << "이름 : " << st.name << endl;
	cout << "나이 : " << st.age << endl;
	cout << "전화번호 : " << st.phoneNumber << endl;

	cout << "=================================================" << endl;
	Point p;
	p.x = 10;
	p.y = 20;
	cout << "구조체 p.x의 값 : " << p.x << endl;
	cout << "구조체 p.y의 값 : " << p.y << endl;
	p.Print();
	cout << "구조체 선언과 동시 초기화" << endl;
	Point p1 = { 50,120 };
	cout << "구조체 p.x의 값 : " << p.x << endl;
	cout << "구조체 p.y의 값 : " << p.y << endl;
	
	Person per[3];

	per[0].name = "경1이";
	per[0].phoneNumber = "010-1131-1111";
	per[0].age = 11;

	per[1].name = "경2이";
	per[1].phoneNumber = "010-1311-1111";
	per[1].age = 12;

	per[2].name = "경3이";
	per[2].phoneNumber = "010-3111-1111";
	per[2].age = 13;

	cout << per[0].name << per[0].phoneNumber << per[0].age << endl;

	Person st1[3] =
	{
		{"김","12139-113234",60},
		{"이","12133-113234",20},
		{"박","12132-113234",70}
	};
	for (int i = 0;i<3;i++)
	{
		cout << st1[i].name << st1[i].phoneNumber << st1[i].age << endl;
	}

	Point1 point1 = { 1.0,2.0 };
	Point1 point2 = { 4.0,6.0 };

	double distance = CalculateDistance(point1, point2);

	cout << "두점사이의 거리 " << distance << endl;

	//학생 정보 관리 만들어보기(구조체)
	//이름, 나이, 점수(영어, 수학, 과학)
	//평균을 구하는 함수 만들기
	//ex) 홍길동 20
	//영어 : 20
	//수학 : 30
	//과학 : 50
	//각 과목 합계와 평균 출력

	StudentInfo sti;

	sti.name = "홍길동";
	sti.math = 50;
	sti.english = 70;
	sti.science = 80;
	
	cout << "성명 : " << sti.name << endl;
	cout << "수학 점수 : " << sti.math << endl;
	cout << "영어 점수 : " << sti.english << endl;
	cout << "과학 점수 : " << sti.science << endl;
	calculatePoints(sti.math, sti.english, sti.science);
 
}
void Point::Print()
{
	cout << "나는 Point 구조체의 멤버함수이다." << endl;
}
