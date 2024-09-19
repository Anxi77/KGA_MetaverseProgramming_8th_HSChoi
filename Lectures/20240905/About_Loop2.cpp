/*
while

-조건이 참(true)인 동안 특정코드를 반복실행하기 위한 반복문이다.
-조건이 거짓이 될때까지 계속 반복
-일반적으로 반복횟수가 미리 정해지지 않았거나 특정 조건을 만족할때까지 반복해야 하는 경우 사용

	while (true)
	{
		//위 조건이 만족되면 여기를 실행
		//단, 종료 조건이 있어야만 해당 while이 종료가 된다.
	}

do-while
- 조건이 참인지 여부와 관계없이 코드블럭을 최소 한번은 실행해야 할때 사용한다.
- 다른 반복문과는 다르게 조건을 나중에 검사하는 것이 특징이다.

	do
	{
	 //실행할 코드가 들어간다.
	} while (true); --->do 블록이 실행 된 후에 조건을 검사한다.
	- 조건이 참이면 코드를 다시 실행하고 거짓이면 종료하게 된다.

while과 차이점
- do-while은 조건을 나중에 검사하므로 코드블럭을 최소 한번은 실행한다.
- while은 조건을 먼저 검사하기 때문에 처음부터 거짓이면 코드 블럭을 한번도 실행하지 않을 수 있다.

*/

#include<iostream>

int main()
{
	/*while (true)
	{
		std::cout << "*****" << std::endl;
	} 무한으로 반복된다.
	*/

	//int num = 0;

	////num이 10보다 작으면 (작을때까지 반복)
	//
	//while (num < 10)
	//{
	//	num++;// num이 1씩 증가한다
	//	std::cout << num << std::endl;
	//}

	///*
	//	while (true)
	//	{
	//		if (num == 10)break;
	//		num++; // 1씩 증가
	//		std::cout << num << std::endl;
	//	} //if문을 사용하여 위와 같은 결과를 나타내는 코드이다.
	//*/
	//std::cout << std::endl;
	//std::cout << "아무 숫자나 입력해 보세요" << std::endl;
	//while (true)
	//{
	//	int inputNum;
	//	std::cin >> inputNum;

	//	std::cout << "내가 입력한 숫자 : " << inputNum << std::endl;

	//	if (inputNum < 1 || inputNum > 10)break;
	//}

	////while을 이용하여 입력한 만큼 출력하기
	////ex)3을 입력하면 지정한 구문이 세번 출력되게 하기

	//std::cout << "숫자를 입력하시오 : ";
	//int inputNum;
	//std::cin >> inputNum;//입력용 변수

	//int count = 0; //count용 변수

	//while (count < inputNum) 
	//{
	//	std::cout << "위에 입력한 수 만큼 출력됩니다 ." << std::endl;
	//	count++;
	//}

	int inputNum;
	int total = 0;
	do 
	{
		std::cout << "0보타 큰 숫자를 입력하시오. 종료하려면 0 " << std:endl;
			std::cin >> inputNum;
		total += inputNum;
	} while (inputNum != 0) //0이 입력되면 종료
		std::cout << "합계 : " << total << std::endl;
	std::cout << std::endl;
	int num = 0;
	//조건이 처음부터 false 이기에 실행되지 않는다.
	while (num > 0)
	{
		std::cout << "여기는 실행되지 않는다 . " << std::endl;
	}
	do
	{
		std::cout << "여기는 최소 한번 실행된다 . " << std::endl;
	} while (num > 0);//조건은 false 이지만 do 블록이 먼저 실행된다.

	while (true)
	{
		int num = 0;
		num++;
		std::cout << num << std::endl;
	}
}