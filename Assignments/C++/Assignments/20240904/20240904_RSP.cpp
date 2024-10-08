#include <iostream>

int main() 
{
	int player;
	std::srand(std::time(NULL));
	int cpu = std::rand()%3+1;
	

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

	if (player >= 1 && player <= 3)
	{
		if ((player == 1 && cpu == 1) || (player == 2 && cpu == 2) || (player == 3 && cpu == 3))
		{
			std::cout << "무승부 입니다 !!!" << std::endl;
		}
		else if ((player == 1 && cpu == 2) || (player == 2 && cpu == 3) || (player == 3 && cpu == 1)) 
		{
			std::cout << "플레이어의 패배 !!!" << std::endl;
		}
		else if ((player == 1 && cpu == 3) || (player == 2 && cpu == 1) || (player == 3 && cpu == 2)) 
		{
			std::cout << "플레이어의 승리 !!!" << std::endl;
		}
	}
	else
	{
		std::cout << "유효하지 않은 숫자입니다." << std::endl;
	}
}