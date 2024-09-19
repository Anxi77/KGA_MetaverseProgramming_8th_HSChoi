#include<iostream>

int main() {

	int input;
	int input2;
	
	int inpRes;

	
	std::cout << "첫번째 숫자를 입력해주세요" << std::endl;
	std::cin >> input;
	std::cout << "두번쨰 숫자를 입력해주세요" << std::endl;
	std::cin >> input2;

	inpRes = input > input2;
	
	std::cout << "첫번째 숫자가 두번째 숫자보다 큰가? : " << inpRes << std::endl;

}