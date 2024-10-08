//4. 가위바위보 업그레이드 하기
//-가위바위보의 종료조건 넣기
//ㄴ10판으로 제한
//ㄴ베팅액이 소지금보다 큰 경우
//-플레이어 소지금 보유 (10000원)
//-베팅을 할수 있다.(소지금보다 큰 금액X(예외처리), 최소 베팅액은 100)
//-플레이어 승리시 -> 배팅금의 *2 얻음
//-무승부시 -> 베팅금 사라짐
//-플레이어 패배시 ->베팅금의 *2 잃음

#include <iostream>

int gamemoney(int gmoney, int betmoney, int result) // 돈 계산 함수
{
	int sum;

	if (result == 0)
	{
		sum = gmoney + betmoney;
	}
	else if (result == 1)
	{
		sum = gmoney - betmoney * 2;
	}
	else if (result == 2)
	{
		sum = gmoney - betmoney;
	}

	return  sum; 

	
}


int maingame()
{
	int player;
	std::srand(std::time(NULL));
	int cpu = std::rand() % 3 + 1;


	std::cout << "1) 가위 2) 바위 3) 보 중 한개를 입력해주세요" << std::endl;
	std::cin >> player;
	if (4 > player > 0)
	{
		switch (player)
		{
		case 1:
			std::cout << "가위를 입력해주셨습니다 ." << std::endl;
			break;
		case 2:
			std::cout << "바위를 입력해주셨습니다 ." << std::endl;
			break;
		case 3:
			std::cout << "보를 입력해주셨습니다 ." << std::endl;
			break;
		default:
			break;
		}
	}
	std::cout << "CPU의 결과를 추첨하겠습니다 ." << std::endl;

	if (3 > cpu > 0)
	{
		switch (cpu)
		{
		case 1:
			std::cout << "CPU의 결과는 가위" << std::endl;
			break;
		case 2:
			std::cout << "CPU의 결과는 바위" << std::endl;
			break;
		case 3:
			std::cout << "CPU의 결과는 보" << std::endl;
			break;
		}
	}

	std::cout << "가위 바위 보 의 결과는 : ";

	int count;
	count = 0;

	if (player >= 1 && player <= 3)
	{
		if ((player == 1 && cpu == 1) || (player == 2 && cpu == 2) || (player == 3 && cpu == 3))
		{
			std::cout << "무승부 입니다 !!!" << std::endl;
			count = 2;
		}
		else if ((player == 1 && cpu == 2) || (player == 2 && cpu == 3) || (player == 3 && cpu == 1))
		{
			std::cout << "플레이어의 패배 !!!" << std::endl;
			count = 1;
		}
		else if ((player == 1 && cpu == 3) || (player == 2 && cpu == 1) || (player == 3 && cpu == 2))
		{
			std::cout << "플레이어의 승리 !!!" << std::endl;
			count = 0;
		}
	}
	else
	{
		std::cout << "유효하지 않은 숫자입니다." << std::endl;
	}

	return count;

}

int rsp()
{
	std::cout << "=====================가위바위보 게임========================" << std::endl;
	int usermoney;
	usermoney = 10000; // 플레이어의 보유 금액 초기화
	for (int i = 10; i >= 0; i--)
	{
		if (usermoney < 0)
		{
			std::cout << "플레이어의 패배 !!! " << std::endl;
			return 0;
		}
		std::cout << "베팅을 시작하겠습니다 ." << std::endl;
		std::cout << "베팅은 100 gold 이상 부터 가능합니다 ." << std::endl;
		std::cout << std::endl;
		std::cout << "현재 플레이어의 보유금 : " << usermoney << " Gold" << std::endl;
		std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

		int betmoney;
		std::cout << "베팅하실 금액을 입력해주세요 : ";
		std::cin >> betmoney; // 플레이어의 베팅 금액 설정
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << std::endl;
		if (betmoney >= 100 && betmoney < usermoney)
		{
			int count; // 게임 승패 여부 변수
			count = maingame(); // 승패 여부에 대한 변수 가위바위보 게임 함수에서 받아오기
			usermoney = gamemoney(usermoney, betmoney, count);
			std::cout << " 플레이어의 현재 남은 금액 : " << usermoney << std::endl;
			std::cout << "=====================================================" << std::endl;
			std::cout << std::endl;
		}
		else (betmoney <= 100 || betmoney > usermoney);
		{
			std::cout << "유효한 숫자를 입력해 주세요" << std::endl;
			std::cout << "=====================================================" << std::endl;
		}
		

	}
}

int main()
{
	rsp();
}