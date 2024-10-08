#include <iostream>

/*
 if
 - 조건문 이라고도 하며 프로그램의 실행 흐름을 제어하는데 사용한다.
 - 조건문은 주어진 조건이 True/False 여부에 따라 코드 블록을 실행하게 된다.

if (조건) <- 이곳이 참이라면
{
실행 (조건이 참일 경우 실행되는 코드)
}

 1. if문은 갯수 제한이 없다.(연속적으로 사용가능)
 2. if문은 조건식을 전부 검사한다.
 3. else는 위에 있는 if문이 거짓이면 실행한다.
 4. else는 단독으로 사용이 불가능하고 연속적으로 사용할 수 없다.
 5. else if 는 위의 조건이 거짓이고 구문 안의 조건이 참이라면 실행된다
 6. else if는 if~if(연속된if문)문 과는 다르게 조건 만족시 그 아래에 있는 코드(조건식)을 검사하지 않는다. 
*/

int main()
{


	//if (true) {
	//
	//	std::cout << "조건이 참이면 이곳이 실행된다" << std::endl;
	//}

	//int num = 10;

	//////만약 num이 10보다 같거나 크다면
	//if (num < 10) {
	//	std::cout << "첫번째 if문 실행" << std::endl;
	//}
	////OK
	////위 조건이 거짓이고 밑과 같은 조건이라면
	//else if (num == 10) 
	//{
	//	std::cout << "두번째 if문 실행" << std::endl;
	//}
	//else if (num <= 10) 
	//{
	//	std::cout << "세번째 if문 실행" << std::endl;
	//}
	//else 
	//{
	//	std::cout << "위 조건이 전부 만족하지 않는다면 else를 실행한다" << std::endl;
	//}

	//int num1 = 50;

	//if (num1==51)
	//{
	//	std::cout << "num1이 50이면실행" << std::endl;
	//}
	//else
	//{
	//	std::cout << "위 조건이 거짓이면 실행" << std::endl;	//
	//}

	/*
	int input;
	std::cin >> input;

	//입력한 값을 2로 나눈 나머지가 0이라면
	if ((input % 2) == 0)
	{
		std::cout << " 짝수 " << std::endl;
	}


		if ((input % 2) != 0)
	{
		std::cout << " 홀수 " << std::endl;
	}

	가능은 하지만 이렇게 쓰진 않는다



	else {
		std::cout << " 홀수 " << std::endl;
	}
	*/


	int input;
	int input2;
	int calc;

	std::cout << "첫번째 숫자를 입력해주세요" << std::endl;
	std::cin >> input;
	std::cout << "두번째 숫자를 입력해주세요" << std::endl;
	std::cin >> input2;
	std::cout << "1)더하기 2)빼기 3)곱하기 4)나누기 중 1개를 선택해주세요" << std::endl;
	std::cin >> calc;
	if (calc == 1) {
		std::cout << "첫번째 숫자에 두번째 숫자를 더한 값은 : " << (input + input2) << std::endl;
	}
	if (calc == 2) {
		std::cout << "첫번째 숫자에 두번째 숫자를 뺀 값은 : " << (input - input2) << std::endl;
	}
	if (calc == 3) {
		std::cout << "첫번째 숫자에 두번째 숫자를 곱한 값은 : " << (input * input2) << std::endl;
	}
	if (calc == 4) {
		std::cout << "첫번째 숫자에 두번째 숫자를 나눈 값은 : " << (input / input2) << std::endl;
	}


	//if (input > 0) //입력한 값이 양수
	//{
	//	//짝수라면
	//	if (input % 2 == 0) {
	//		//짝수

	//		//여기까지 왔다라는건 입력한 값이 양수 && 짝수
	//		if (true) {

	//	}
	//	else {
	//	
	//	}
	//}

	////실습
	////1.입력을 두개를 받는다.
	////2.더하기 빼기 곱셈 나눗셈을 선택한다.
	////EX)1) 더하기 , 2) 빼기 , 3) 곱셈 , 4 나눗셈)

	// 몬스터와 플레이어 체력 설정
	int playerHealth = 100;
	int monsterHealth = 100;

	//몬스터 공격력 세팅
	int monsterAttack = 10;

	//이건 입력으로 처리
	int playerAttack = 0;

	std::cout << "전방에 고블린이 나왔다" << std::endl;

	//먼저 때려볼까?
	//std::cout << "플레이어가 고블린을 공격!!" << std::endl;

	//때려야하는데 고블린의 체력이 0 미만이면 안되니까
	if (monsterHealth > 0)
	{
		std::cout << "플레이어의 공격력을 입력하시요" << std::endl;
		std::cin >> playerAttack;

		std::cout << "고블린이 공격한다!" << std::endl;
		//플레이어 체력깎고
		playerHealth -= monsterAttack;
		//고블린 체력깎고
		monsterHealth -= playerAttack;

		if (playerHealth > 0) 
		{
			std::cout << "플레이어의 남은체력 :" << playerHealth << std::endl;
			std::cout << "몬스터의 남은체력 :" << monsterHealth << std::endl;
		}
	}
	else
	{
		std::cout << "몬스터가 죽었다" << std::endl;
	}
}