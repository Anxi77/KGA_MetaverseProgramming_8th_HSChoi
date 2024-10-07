//2-1. while을 이용해서 원하는 구구단 출력
//ㄴ2를 입력하면 2를 출력
#include<iostream>

int main()
{
	std::cout << "1~9 사이의 숫자를 입력해주세요" << std::endl;
	int input;
	input = 0;
	while (true)
	{
		std::cin >> input;
		if (input > 9 || input < 1)
		{
			std::cout << "잘못된 숫자입니다 다시 입력해주세요" << std::endl;
		} 
		else
		{
			break;
		}
	}
	for (int k = 1; k <= 9; k++)
	{
		int res;
		res = input * k;
		std::cout << input << " x " << k << "=" << res << std::endl;
	}
}