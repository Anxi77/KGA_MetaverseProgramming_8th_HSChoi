/*

switch
-여러 조건을 처리해야 할 때 사용.
-주로 상수값을 기준으로 분기할때 사용.
-코드가 깔끔하고 가독성이 좋다.
-중첩이 가능하다. (If문과 혼용도 가능하다)
-정수값이나 특정값을 열거하고 비교할때 유리하다.

switch 의 구조
1. 하나의 변수를 검사하고 그 변수의 값에 따라 여러 Case 블록 중 하나를 실행
2. break 키워드를 통해 각 case의 실행을 종료한다.
3. break가 없으면 다음 case 블록이 연속적으로 실행된다.
4. 표현식은 문자 , 정수 , 열거타입이 들어올 수 있음.

- 상수값을 기준으로 여러 선택지 중 한개를 선택하는 상황에서 사용하기 편리
- 코드의 가독성을 높이고 효율성을 개선할수 있지만 표현식의 제한이 있다.

-break?
ㄴ반복문이나 switch 문을 제어할때 사용
ㄴbreak가 실행되면 해당 루프나 switch문을 종료하고 break다음으로 이동하여 실행된다.
ㄴ다중 switch나 중첩반복문에서는 break가 있는 해당 스코프(중괄호)만 빠져나간다.
	switch (표현식)
	{
	case 값(상수값): //if와 동일함
		//실행될 코드들이 들어옴
		break;
	case 값(상수값):
		//실행될 코드들이 들어옴
		break;
	case 값(상수값):
		//실행될 코드들이 들어옴
		break;
	case 값(상수값):
		//실행될 코드들이 들어옴
		break;
	default: //else와 동일함
		//어떤 case에도 해당하지 않을때 실행된다.(생략가능)
		break;
	}

*/

#include<iostream>

int main()
{
	std::cout << "게임을 선택하시오. " << std::endl;
	std::cout << "1. 오버워치" << std::endl;
	std::cout << "2. 발로란트" << std::endl;
	std::cout << "3. 디아블로" << std::endl;
	std::cout << "4. 스타" << std::endl;
	std::cout << "5. 롤" << std::endl;

	int choice;

	std::cin >> choice;
	switch (choice)
	{
	case 1:
		std::cout << "오버워치를 선택" << std::endl;
	case 2:
		std::cout << "발로란트를 선택" << std::endl;
	case 3:
		std::cout << "디아블로를 선택" << std::endl;
	case 4:
		std::cout << "스타를 선택" << std::endl;
	case 5:
		std::cout << "롤을 선택" << std::endl;
	}

	int jobSelect, SkillSelect;

	std::cout << "직업을 선택하시오 . 1)마법사 , 2) 기사 3) 드워프 ";
	std::cin << jobSelect;

	switch (jobSelect)
	{
	case 1:
		std::cout << "마법사를 선택했다 . 어떤 스킬을 사용할까 1)파이어볼 , 2)아이스볼";
		std::cin >> SkillSelect
			switch (SkillSelect)
			{
			case 1:
				std::cout << "파이어볼 시전!!!" << std::endl;
				break;
			case 2:
				std::cout << "아이스볼 시전!!!" << std::endl;
				break;
			}
	case 2:
		std::cout << "기사를 선택했다 . 어떤 스킬을 사용할까 1) 방패공격 2) 기본공격";
	}

	//현재 시간을 이용하여 시드값을 설정하는 방법
	std::srand(std::time(NULL));
	//0~RAND_MAX값중 하나를 랜덤하게 뽑아준다.
	int random = std::rand()%9;//0~8
	std::cout << random << std::endl;
	
	//1.과제
	//if 문을 사용하여 계절을 맞춰 봅시다.
	// 1~12월까지만
	//ex)7을 입력하면 여름이 나와야 한다.
	//3월~5월 봄
	//6~8 여름
	//9~11 가을
	//12~2 겨울

	//2.가위바위보 게임 만들기
	//문자열 X , 정수로만 입력받는다.
	//1.플레이어는 입력을 받는다. (1: 가위 , 2 : 바위 , 3 : 보)
	//2.컴퓨터있음. -> 랜덤하게 가위, 바위 , 보를 선택함
	//3.승패를 나타내는 출력하기 


}