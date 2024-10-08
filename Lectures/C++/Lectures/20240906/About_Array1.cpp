#include<iostream>

int main() 
{
	//int arr[4];

	int arr[4][3];

	arr[0][0] = 1;
	arr[0][1] = 2;
	arr[0][2] = 3;

	arr[1][0] = 4;
	arr[1][1] = 5;
	arr[1][2] = 6;
	
	arr[2][0] = 7;
	arr[2][1] = 8;
	arr[2][2] = 9;
	
	arr[3][0] = 10;
	arr[3][1] = 11;
	arr[3][2] = 12;

	std::cout << " " << arr[0][0] << " , " << arr[0][1] << " , " << arr[0][2] << std::endl;
	std::cout << " " << arr[1][0] << " , " << arr[1][1] << " , " << arr[2][2] << std::endl;
	std::cout << " " << arr[2][0] << " , " << arr[2][1] << " , " << arr[2][2] << std::endl;
	std::cout << " " << arr[3][0] << " , " << arr[3][1] << " , " << arr[3][2] << std::endl;

	std::cout << "================================================================" << std::endl;
	
	std::cout << " " << &arr[0][0] << " | " << &arr[0][1] << " | " << &arr[0][2] << std::endl;
	std::cout << " " << &arr[1][0] << " | " << &arr[1][1] << " | " << &arr[2][2] << std::endl;
	std::cout << " " << &arr[2][0] << " | " << &arr[2][1] << " | " << &arr[2][2] << std::endl;
	std::cout << " " << &arr[3][0] << " | " << &arr[3][1] << " | " << &arr[3][2] << std::endl;

	int arr1[4][3] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int arr2[4][3] = { 1,2,3,4,5 };

	for (int i = 0; i < 4; i++)
	{
		std::cout << std::endl;
		for (int k = 0; k < 3; k++) 
		{
			std::cout << arr1[i][k] << " ";
		}
	}
	
	for (int i = 0; i < 4; i++)
	{
		std::cout << std::endl;
		for (int k = 0; k < 3; k++)
		{
			std::cout << arr2[i][k] << " ";
		}
	}
	std::cout << std::endl;
	std::cout << "========================================" << std::endl;

	int arr3[4][3] = { {1,2},{3},{4},{5} };
	int arr4[4][3] = { {1,2,3},{4,5,6},{7,8,9},{10} };

	for (int i = 0; i < 4; i++)
	{
		std::cout << std::endl;
		for (int k = 0; k < 3; k++)
		{
			std::cout << arr3[i][k] << " ";
		}
	}

	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
	{
		std::cout << std::endl;
		for (int k = 0; k < 3; k++)
		{
			std::cout << arr4[i][k] << " ";
		}
	}
}