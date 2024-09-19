/*

*/


#include <iostream>
using namespace std;

//값에 의한 전달 -> callByValue
//함수에 인수를 전달할때 인수의 값이 복사되어 함수의 매개변수로 전달된다.
//함수 내부에서 매개변수를 변경하더라도, 호출한 함수의 실제 인수는 변하지 않는다.

void Value(int n);


//참조에 의한 호출
//함수 호출시 인수로 변수의 주소를 전달하는 방식
//함수가 매개변수로 받은 참조를 통해 실제 인수의 값을 직접 수정 가능하다.
//함수 내부에서 매개변수의 값을 변경하면 호출한 함수의 실제 인수의 데이터도 변경됨.
//값을 복사하는 대신 주소를 전달하므로 메모리와 성능효율이 좋다 .
//C style
void Address(int* n);
//C++ Style 변수의 다른 이름(별명)을 만들어 함수가 해당 변수의 원본데이터에 직접 접근하고 수정가능하게 만든다.
void Reference(int& n);

struct Mystruct
{


};

void T(Mystruct& m); // <- 구조체를 넘기는 예시 

/*
* , & 전달 방식의 차이?
* -> 변수의 메모리 주소를 전달하며 함수 내부에서 포인터를 통해 값을 수정
 ㄴ 함수 호출시 변수의 주소를 명시적으로 전달
 ㄴ 포인터는 nullptr 또는 null로 설정 할 수 있다.
 ㄴ 잘못된 사용시 유효하지 않은 메모리 접근으로 오류 발생가능
& -> 변수의 별칭을 전달하며 내부에서 참조를 통해 직접 값을 수정
 ㄴ함수 호출시 변수의 참조를 암시적으로 전달 . 더 안전하게 사용 가능
*/

void Swap(int a, int b);
void Swap_Address(int* a, int* b);
void Swap_Reference(int& a, int& b);

int main()
{
	int* p = nullptr; // 포인터 변수의 초기화
	int num = 30;
	Value(num);//n=num 형태로 복사
	cout << "num의 값 : " << num << endl;
	cout << "num의 주소값 : " << &num << endl;
	cout << "============================" << endl;

	int num1 = 30;
	Address(&num1);
	cout << "num1의 값 : " << num1 << endl;
	cout << "num1의 주소값 : " << &num1 << endl;
	cout << "============================" << endl;

	int num2 = 20;
	Reference(num2);
	cout << "num2의 값 : " << num2 << endl;
	cout << "num2의 주소값 : " << &num2 << endl;
	cout << "============================" << endl;

	int num3 = 10;
	int num4 = 20;
	cout << "스왑 전 데이터 : " << num3 << " , " << num4 << endl;
	Swap(num3, num4);
	cout << "스왑 후 데이터 : " << num3 << " , " << num4 << endl;
	cout << "============================" << endl;

	int swapAddressNum1 = 10;
	int swapAddressNum2 = 20;
	cout << "스왑 전 데이터 : " << swapAddressNum1 << " , " << swapAddressNum2 << endl;
	Swap_Address(&swapAddressNum1, &swapAddressNum2);
	cout << "스왑 후 데이터 : " << swapAddressNum1 << " , " << swapAddressNum2 << endl;
	cout << "===================================================================" << endl;

	int swapRefNum1 = 30;
	int swapRefNum2 = 50;
	cout << "스왑 전 데이터 : " << swapAddressNum1 << " , " << swapAddressNum2 << endl;
	Swap_Address(&swapAddressNum1, &swapAddressNum2);
	cout << "스왑 후 데이터 : " << swapAddressNum1 << " , " << swapAddressNum2 << endl;
	cout << "===================================================================" << endl;

}

void Value(int n)
{
	n = 10;
	cout << "n의 값 : " << n << endl;
	cout << "n의 주소값 : " << &n << endl;
}

void Address(int* n)
{
	*n = 10;
	cout << "n의 값 : " << *n << endl;
	cout << "n의 주소값 : " << &n << endl;
}

void Reference(int& n)
{
	n = 10;
	cout << "n의 값 : " << n << endl;
	cout << "n의 주소값 : " << &n << endl;

}
//아래와 같은 형태는 전달이 아니라 복사가 되기 때문에
//num3, num4에 각각 저장된 10,20이 복사된다.
//swap 내부에서만 값변경이 이루어지고 main함수에 있는 num3,num4 영향을 받지 않는다.
void Swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
	cout << "Swap()함수 내부의 값 : ";
	cout << a << " , " << b << endl;
}
//주소값을 매개변수로 전달해서 스왑하려는 변수에 접근
void Swap_Address(int* a, int* b) 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//참조방식
//&주소를 반환하는 연산자가 아님
//참조는 변수의 별명 -> 스왑하려는 메모리를 공유
//별명이 바뀌면(참조자)참조하는 변수의 값이 변경된다.
void Swap_Reference(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}