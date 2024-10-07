/*
//1. °úÁ¦
	*
	**
	***
	****
	*****

		*
	   **
	  ***
	 ****
	*****

	*****
	 ****
	  ***
	   **
		*

	*****
	****
	***
	**
	*

*/

#include <iostream>


int main()
{
	for (int line = 1; line <= 5; line++)
	{
		for (int star = 1; star <= line; star++)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (int line = 1; line <= 5; line++)
	{
		for (int space = 5; space > line; space--)
		{
			std::cout << " ";
		}
		for (int star = 1; star <= line; star++)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (int line = 0; line <= 5; line++)
	{
		for (int star = 1; star <= 5 - line; star++)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (int line = 0; line <= 5; line++)
	{
		for (int space = 0; space < line; space++)
		{
			std::cout << " ";
		}
		for (int star = 1; star <= 5 - line; star++)
		{
			std::cout << "*";
		}
		std::cout << std::endl;

	}
	std::cout << std::endl;


}