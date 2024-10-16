
#include<iostream>

/*
변수 (Variable)
- 어떠한 데이터 값을 저장할수 있는 메모리 공간에 붙혀진 이름
- 변수라는 것을 선언하면 메모리 공간이 할당되고 , 할당된 메모리 공간에 이름이 붙는다

** 변수의 이름
 - 변수의 이름을 통해 할당된 메모리 공간에 접근이 가능
 - 값을 저장할수도 있고 저장된 값을 참조할수도 있다 . 

 ####주의사항####
1. 변수의 이름은 , 알파벳, 숫자, 언더스코어(_)로 구성할수 있다
2. 대소문자 구분한다. EX) Num , num 은 전혀 다른 변수다
3. 변수의 이름은 숫자로 시작할 수 없고 키워드도 변수의 이름으로 사용할수 없다
4. 공백 삽입 불가
5. 변수의 이름에 특수문자 사용 불가
6. 한글선언도 되지만 관례상 영어로 선언한다
7. 변수의 이름은 의미가 있는 (다른 사람이 봐도 이해가능한) 변수 이름을 지어야 함

*/

int main()
{
	int a = 10; // 변수 a (int(정수)형 타입의 변수를 선언)
	// 프로그래밍에서는 (=)을 대입연산자로 사용함 (대입한다는 뜻)
	// 프로그래밍에서는 == 이 등호
	int b; // 변수 b (정수형 데이터를 담을 수 있는 컨테이너)

	float c; // 실수형 데이터타입인 변수 c를 선언

	int num, num1; // ,를 이용하여 복수의 변수를 동시에 선언가능

	//변수를 선언과 동시에 초기화(데이터값을 대입)
	int input = 10;
	//변수를 선언
	int inputnum;
	inputnum = 20;
	std::cout << "위에서 선언한 변수 a의 값은 : " << a << std::endl;
	std::cout << "위에서 선언한 변수 inputnum의 값은 : " << inputnum << std::endl;
	inputnum = 10;
	std::cout << "위에서 선언한 변수 inputnum의 값은 : " << inputnum << std::endl;

	//선언하면 안되는 것들
	//int int;
	//int 7num; - 변수의 시작이 숫자로 불가능
	//int num#; - 특수문자 불가능
	//int num num; - 공백 불가능
	//int 한글변수 - 가능하지만 사용 X
	
	//의사코드 먼저 작성해라
	

	//한글로 작성

	//EX) 플레이어와 관련된 변수 - 공격력 , 방어력 ... , 몬스터와 관련된 변수 - 공격력 , 방어력 ...
}


