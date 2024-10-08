/*
-포인터는 주소를 저장한느 변수이다.
-모든 데이터들은 메모리 상에 특정한 공간에 저장이 되어있다.
-기존의 변수는 데이터를 저장하는데 비해 포인터는 메모리 공간의 주소를 저장한다.
-포인터 변수가 주소를 저장하려면 변수의 주소를 알아야 한다.
ㄴ변수 이름 앞에 &연산자를 붙인다.
ㄴ포인터 변수가 저장하는 변수의 주소에 저장된 값을 참조하려면 * 연산자를 사용한다.

-포인터 연산자
& : 특정한 데이터의 메모리 상의 주소값을 알 수 있다.
* : & 연산자가 어떤 데이터의 주소값을 얻어내는 연산자라면 반대로 주소값에서 해당 주소값에 대응되는 데이터를 가져오는 연산자(역참조)

int a;
Pointer(라는 타입이 있다면)* p;
p = &a;

해당 변수의 시작 메모리 주소만 갖고 있기 때문에 데이터 타입을 지정하여야 한다.

*/

#include <iostream>


using namespace std;


int main()
{
	//int* p;//포인터 변수 p 선언
	//int a;
	//a = 2;
	////p = 10;//우리가 흔히 알고 있는 데이터는 저장이 안된다.
	//p = &a; //포인터 변수 p 에 정수형 변수 a의 주소를 저장한다.

	//cout << "p의 값(a의 주소값) : " << p << endl;
	//cout << "a의 값 : " << a << endl;
	//cout << "*p의 값 : " << *p << endl;
	cout << "====================================" << endl;
	int num = 10;
	cout << "num의 값 : " << num << endl;
	cout << endl;
	cout << "num의 주소값 : " << &num << endl;
	cout << endl;
	int* p = &num;
	cout << "pointer 변수 p의 값 : " << p << endl;
	cout << endl;
	cout << "p의 주소값 : " << &p << endl;
	cout << endl;
	cout << "p의 역참조(num의 값) : " << *p << endl;
	cout << endl;
	*p =  777;
	cout << "num의 값 : " << num << endl;

	int** pp; //이중포인터 - 포인터 변수의 주소를 저장하는 역할이다 .

	int b;
	pp = &p;
	cout << endl;
	cout << "pp의 값(포인터 변수 p의 주소) : " << pp << endl;
	cout << endl;
	cout << "*pp의 값(num의 주소) : " << *pp << endl;
	**pp = 1234;
	cout << endl;
	cout << "변경된 num의 값 : " << num << endl;

	//callbyRef
	//callbyValue
}