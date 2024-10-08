/*
 함수(Functions)
 <함수의 구성>
//반환형 함수이름(매개변수){함수내용}

<반환형 (Return Type)>
//함수의 결과(출력) 데이터의 자료형
//함수의 결과 데이터가 없는 반환형 void

<return>
//함수가 끝나기 전까지 반드시 return 으로 반환형에 맞는 데이터를 반환해야한다.
//함수 진행중 return을 만났을 경우 그 결과 데이터를 반환하고 함수를 빠져나온다
//void 반환형의 함수의 return은 생략가능
*/

#include <iostream>

int IntReturn()
{
	std::cout << "return 전" << std::endl;
	return 10;
	std::cout << "return 후" << std::endl; //이미 위에서 리턴을 해서 함수가 종료되었으므로 실행되지 않는다.
}

void Func4_2()
{										//1
	std::cout << "끝 ! " << std::endl;	//2
}										//3

void Func4_1()							
{										//4
	Func4_2();							//5
}										//6

void Main ()
{										//7
	Func4_1();							//8
}										//9



/*
<함수의 전방선언>
함수를 구현하기 전에 함수의 선언만 우선 진행
컴파일시 함수의 호출은 함수의 구현을 필요로 하며 구현이 없는 경우 사용이 불가하다
전방 선언을 진행하는 경우 함수의 구현을 호출 이후에 진행하도록 구현 가능하다 .

함수의 호출이 함수의 구현보다 먼저 발생되는 경우 오류가 발생한다
*/

void Func6_1();
void Func6_3();

void Main6() 
{
	Func6_1();
	//Func6_2(); 선언만 되고 구현이 되지 않았기 때문에 오류가 발생한다.
	//Func6_3(); 선언만 되고 구현이 되지 않았기 때문에 오류가 발생한다.
}
void Func6_2() 
{
	
}

int main()
{
	Main();
}

void Func6_1() 
{
	std::cout << "ewruiqporuqewuriowpq" << std::endl;
}
/*<기본 매개변수>
* 매개변수에 기본값을 지정하여 함수 호출시 매개변수를 전달하지 않으면 미리 지정해놓은 기본값으로 처리가 된다
* 기본 매개변수를 지정할 때에는 뒤에서부터 해야한다. 
*/
void Func7(int param, int param1 = 2, int param2 = 3) 
{

}
