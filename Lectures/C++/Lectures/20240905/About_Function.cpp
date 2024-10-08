/*
함수 (Functions)
- 특정 작업을 수행하는 코드의 집합
- 코드의 안정성 , 에러를 수정하기 쉽다.
- 볼륨이 커지는 프로그램일수록 수정 , 유지보수가 어렵다.
ㄴ기능별로 세분화 시키는것이 필요하다.
- 코드의 재사용성이 좋다

기본적으로 함수는 매개변수(Parameter) 유, 무와 반환(return)값의 유무에 따라 함수를 4개의 형태로 나눌수 있다.

1. 매개변수와 반환값이 모두 있는 경우
2. 매개변수가 있고 반환값이 없는 경우
3. 매개변수가 없고 반환값이 있는 경우
4. 매개변수와 반환값이 모두 없는 경우

*/
//1. 지역변수
/*
 - 중괄호 내에 선언되는 변수 모두 지역이다 .
 - 활동 영역은 변수가 선언된 블록 내에서만 유효된다.
 - 전역변수의 사용은 최대한 지양해야한다 . 
*/

#include <iostream>

//1. 매개변수와 반환값이 모두 있는 경우
int Sum(int a, int b)//int (반환값/출력의 형태) Sum(함수의 이름) int a, int b (매개변수 / 입력값)
{
	int res = a + b;
	//반환 타입에 맞게 반환해야함 e.g)int 정수 str 문자열
	return res;
}

//2. 매개변수가 있고 반환값이 없는 경우

void MyPrint(int num) 
{
	std::cout << num << std::endl;
}

//3. 매개변수가 없고 반환값이 있는 경우

int ReadNum() 
{
	int num;
	std::cin >> num;
	return num;
}

//4.매개변수와 반환값이 모두 없는 경우

void Print() 
{
	std::cout << "아무것도 없다." << std::endl;
}

void LocalVariable()
{
	//지역변수
	int num = 1;
	{
		num = 2;

		int num1 = 5;
	}
	
	std::cout << num << std::endl;
	//std::cout << num1 << std::endl;
}

int GlobalVariable = 10; //전역변수

void GlobalVariable() 
{
	std::cout << GlobalVariable << std::endl;
}

//local global
int main() 
{
	//1.
	int result;
	result = Sum(1, 2);
	std::cout << "Sum() 함수 호출 결과 : " << result << std::endl;

	//2.
	MyPrint(5);

	//3.
}