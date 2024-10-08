#include<iostream>

/*
=================Data Type================
- 자료형은 데이터를 표현하는 방법
└ 변수는 데이터의 저장을 위해 할당된 메모리 공간에 붙혀진 이름
└ 메모리 공간의 할당에 앞서 정수나 실수를 저장할 것인지 결정해야함
└ 만약 정수형을 저장한다고 가정할때 몇 바이트를 사용할 것인지 결정해야함.
└ "정수를 저장할 것인데 크기를 4byte로 하고 이름은 num 으로 함.

===기본자료형의 종류와 데이터의 표현범위===

자료형			크기 (byte)
 정수형
char			1
short			2
int				4
long			8
long long		8

 실수형
float			4
double			8

 참과 거짓
bool

*CPU는 4Byte 로 끊어서 계산하는것이 빠르다 (int)*
*컴퓨터도 소수점 밑으로 계산하계되면 오차 발생 (입실론으로 절대값 지정 가능)*
*/

int main() {
	std::cout << "int 형 크기 : " << sizeof(int) << " 바이트 " << std::endl;
	std::cout << "short 형 크기 : " << sizeof(short) << " 바이트 " << std::endl;
	std::cout << "char 형 크기 : " << sizeof(char) << " 바이트 " << std::endl;
	std::cout << "long 형 크기 : " << sizeof(long) << " 바이트 " << std::endl;
	std::cout << "long long 형 크기 : " << sizeof(long long) << " 바이트 " << std::endl;
	std::cout << "float 형 크기 : " << sizeof(float) << " 바이트 " << std::endl;
	std::cout << "double 형 크기 : " << sizeof(double) << " 바이트 " << std::endl;
	std::cout << "bool 형 크기 : " << sizeof(bool) << " 바이트 " << std::endl;

	std::cout << "====================================" << std::endl;

	////ASCII 코드로 대응 가능 (정수형 <-> 문자형)
	//int a = 'b';
	//char num1 = 100;

	//std::cout << a << std::endl;
	//std::cout << num1 << std::endl;

	char num1 = 1;
	char num2 = 2;

	char result = 0;

	short num3 = 300;
	short num4 = 200;
	short result1 = 0;

	std::cout << " 변수 num1의 사이즈 : " << sizeof(num1) << "바이트" << std::endl;//1
	std::cout << " 변수 num2의 사이즈 : " << sizeof(num2) << "바이트" << std::endl;//1
	std::cout << " 변수 result의 사이즈 : " << sizeof(num2) << "바이트" << std::endl;//1
	std::cout << "==========================" << std::endl;
	std::cout << " 변수 num3의 사이즈 : " << sizeof(num3) << "바이트" << std::endl;//2
	std::cout << " 변수 num4의 사이즈 : " << sizeof(num4) << "바이트" << std::endl;//2
	std::cout << " 변수 result1의 사이즈 : " << sizeof(result1) << "바이트" << std::endl;//2

	std::cout << " char 변수 num1+num2의 사이즈 " << sizeof(num1 + num2) << "바이트" << std::endl;//4
	std::cout << " short 변수 num3+num4의 사이즈 " << sizeof(num3 + num4) << "바이트" << std::endl;//4

	float a = 3.141592;

	std::cout << a << std::endl;

	//PC는 4바이트로 계산이 빠르지만 , 상황에 따라서 Data Type 선택 필요
}