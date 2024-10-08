#include <iostream>
#include <vector>

using namespace std;

int checkRow(const vector<vector<int>>& grid, int size, int y, int x)
{
	int count = 0;
	for (int x = size - 1; x >= 0; --x)
	{
		if(x == size -1)
		{
			if (grid[y][x] == grid[y][x - 1])
			{
				count++;
			}
		}
		else if (grid[y][x] == grid[y][x + 1])
		{
			count++;
		}
	}
	return count;

}

int checkColumn(const vector<vector<int>>& grid, int size, int y, int x)
{
	int count = 0;
	for (int y = size - 1; y >= 0; --y)
	{
		if(y == size - 1)
		{
			if (grid[y][x] == grid[y - 1][x])
			{
				count++;
			}
		}
		else if (grid[y][x] == grid[y + 1][x])
		{
			count++;
		}
	}
	return count;

}

bool GameVali(vector<vector<int>>& grid, int size)
{
	bool Zeros = false;
	int count = 0;
	for (int y = 0; y < size; ++y)
	{
		for (int x = 0; x < size; ++x)
		{
			if (grid[x][y] == 0)
			{
				Zeros = true;
			}
		}
	}
	if (Zeros != true)
	{
		for (int y = 0; y < size; ++y)
		{
			for (int x = 0; x < size; ++x)
			{
				count += checkRow(grid, size, y, x);
				count += checkColumn(grid, size, y, x);
			}
		}
	}
	if (count == 0)
	{
		return false;
	}
	return true;
}


int main()
{
	vector<vector<int>> Grid = {
		{2 , 4 , 2},
		{4 , 2 , 4},
		{2 , 4 , 8}, };

	if (GameVali(Grid, 3) == true)
	{
		cout << "움직일 수 있음 !";
	}
	else
	{
		cout << "움직일 수 없음 !";
	}
}