//2. for문을 이용해서 구구단을 출력 (2단~9단)


#include <iostream>

int main() 
{
	for (int i = 2; i <= 9; i++)
	{
		for (int k = 1; k <= 9; k++)
		{
			int res;
			res = i * k;
			std::cout << i << " x " << k << "=" << res << std::endl;
		}
	}
}