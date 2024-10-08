#include <iostream>

int main()
{
	int seasons;
	int input;

	std::cout << "1~12월 중 하나를 입력해주세요" << std::endl;
	std::cin >> input;
	if (input > 0) 
	{
		if ( input >= 3 && input <= 5)
		{
			std::cout << "계절은 봄입니다." << std::endl;
		}
		if ( input >= 6 && input <= 8)
		{
			std::cout << "계절은 여름입니다." << std::endl;
		}
		if ( input >= 9 && input <= 11)
		{
			std::cout << "계절은 가을입니다." << std::endl;
		}
		if ( input >= 12 && input <= 2)
		{
			std::cout << "계절은 겨울입니다." << std::endl;
		}

	}
	else
	{
		std::cout << "1~12 사이의 유효한 숫자를 입력해주세요";
	}
	

}