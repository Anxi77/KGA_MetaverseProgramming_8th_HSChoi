#include <iostream>

/*
반복(Loop)
for,while,do-while

*****for*****
- 반복작업을 수행할때 사용되는 반복문 중 하나.
- 반복횟수가 명확하거나 정밀한 제어가 필요할때 유용하다.
- while보다 기본적으로 많은 코드로 이루어져 있지만 임의의 횟수만큼 반복을 수행하기에
for 문이 편리하다.
- for 문은 초기화 , 조건 , 증감 세 부분으로 구성된다 .

	for (초기화; 조건(종료); 증감)
	{
		//반복실행할 코드를 작성
	}
	-초기화 : 루프가 시작할떄 처음 한번만 실행되는 부분으로 반복문에 발생될 변수를 초기화한다.
	-조건 : 각 반복이 실행될 때 마다 조건이 검사되며 조건이 true이면 루프가 계속 실행된다
			조건이 거짓이면 루프가 종료된다
	-증감 : 각 반복이 끝난 후에 실행되는 부분으로 변수를 증가 / 감소 시키며 반복횟수를 제어한다
*/
int main()
{
	
	//초기값을 0으로 지정하고 루프가 종료되는 조건은 i가 5보다 작을때까지 / i 를 증가시켜라
	for (int i = 0; i < 5; i++)
	{
		std::cout << i << std::endl;//0,1,2,3,4
	}
	std::cout << std::endl;
	for (int i = 10; i >= 1; i--) 
	{
		std::cout << i << std::endl;
	}
	std::cout << std::endl;
	//1~10중 홀수만 출력
	for (int i = 1; i <= 10; i++) 
	{
		// 짝수라면 건너뛰어라 / continue의 조건이 부합하는 순간 건너뛰고 밑의 코드를 실행하지 않고 위의 for문으로 다시 돌아간다
		if (i % 2 == 0)continue;
		std::cout << i << std::endl;
	}
	std::cout << std::endl;
	for (int i = 1; i <= 10; i++) 
	{
		//1~10까지의 숫자중 5까지만 출력/break를 만나게 되면 for 문을 종료시키고 밑으로 나간다.
		if (i > 5)break;
		std::cout << i << std::endl;
	}
	std::cout << std::endl;
	
	int sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		sum += i;
	}
	std::cout << sum << std::endl;
	std::cout << std::endl;

	// 만약 1부터 50까지 반복을 하는데 i가 3의 배수이거나 5의 배수인지?
	
	for (int i = 1; i <= 50; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			std::cout << i << "는 3 또는 5의 배수입니다 . " << std::endl;
		}
	}
	std::cout << std::endl;
	for (int i = 1; i <= 10; i += 2) 
	{
		//홀수만
	}
	std::cout << std::endl;
	//다중 for
	//바깥쪽 for
	for (int i = 0; i < 3; i++) 
	{
		//안쪽 for
		for (int k = 0; k < 3; k++)
		{
			std::cout << "i의 값 : " << i << " k의 값 : " << k << std::endl;
		}
	}
	/*
	i의 값 : 0 k의 값 : 0
	i의 값 : 0 k의 값 : 1
	i의 값 : 0 k의 값 : 2
	i의 값 : 1 k의 값 : 0
	i의 값 : 1 k의 값 : 1
	i의 값 : 1 k의 값 : 2
	i의 값 : 2 k의 값 : 0
	i의 값 : 2 k의 값 : 1
	i의 값 : 2 k의 값 : 2

	스코프를 들어가고 나간다는 개념에 대해 이해해야 한다.
	*/
	
	std::cout << std::endl;
	//출력할 총 줄의 수
	for (int i = 1; i <= 5; i++) 
	{
		for (int k = 1; k <= i; k++) 
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}
	
}

