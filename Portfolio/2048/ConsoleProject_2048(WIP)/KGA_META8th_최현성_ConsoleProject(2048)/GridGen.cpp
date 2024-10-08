#include "GridGen.h"

using namespace std;

GridGen::GridGen(int size) :size(size), gen(random_device{}()), isGridFUll(false)
{
	// x축과 y축 동일하지만 구분을 위해 나눔
	int x = size;
	int y = size;
	// 2D Vector grid 안에 x개의 행과 , y의 열을 가지고 있게끔 벡터 초기화
	grid = vector<vector<int>>(y, vector<int>(x, 0));
}

void GridGen::GridInitialLize()
{
    grid = vector<vector<int>>(size, vector<int>(size, 0));
}

bool GridGen::SpawnRandomNumber()
{
#pragma region Genarate size*size Coordinate Method
    /* 
      0부터(size * size - 1)까지의 균일 분포 난수 생성기 설정
      이는 그리드의 모든 셀에 대한 인덱스 범위를 커버합니다
      uniform_int_distribution 객체 생성
      - uniform_int_distribution<>: 균일 분포의 정수 난수를 생성하는 클래스
      - <>: 템플릿 인자를 비워두면 기본적으로 int 타입으로 설정됨
      - dis: 생성된 분포 객체의 이름
      - (0, size * size - 1): 난수 범위를 0부터 (size * size - 1)까지로 설정
      * 0: 범위의 최소값 (포함)
      * size * size - 1: 범위의 최대값 (포함)
      * 이 범위는 2D 그리드의 모든 셀을 1D 인덱스로 표현할 수 있게 함
    */   
    uniform_int_distribution<> dis(0, size * size - 1);
    /*
     size * size - 1을 사용하는 이유:
     1. 그리드는 2차원이며, 총 셀의 수는 size * size입니다.
     2. 인덱스는 0부터 시작하므로, 마지막 셀의 인덱스는 (size * size - 1)입니다.
     3. 이렇게 하면 모든 셀에 대해 균일한 확률로 접근할 수 있습니다.
     4. size - 1을 사용하면 첫 번째 행의 셀들만 선택될 수 있습니다.
    */
    vector<int> emptyCells;
    /*
     빈 셀(값이 0인 셀)의 인덱스를 저장할 벡터
     이 코드가 작동하는 이유:
     1. 1차원 벡터를 사용하여 2차원 그리드의 인덱스를 저장합니다.
     2. 각 셀의 위치는 단일 정수로 표현됩니다 (i = y * size + x(나누면 y의 값 나머지는 x의 값)).
     3. 나중에 이 정수를 다시 x, y 좌표로 변환할 수 있습니다 (y = i / size, x = i % size).
        - i를 size로 나누면 y 좌표(행)를 얻을 수 있습니다.
        - i를 size로 나눈 나머지는 x 좌표(열)가 됩니다.
        - 이 방법으로 1차원 인덱스를 2차원 그리드의 위치로 쉽게 변환할 수 있습니다.
     4. 이 방법은 메모리를 절약하고 코드를 단순화합니다.
     5. 2차원 좌표를 직접 저장하는 것보다 효율적입니다.

    1(0,0)	2(0,1)	3(0,2)	4(0,3)	5(0,4)
    5(1,0)	6(1,1)	7(1,2)	8(1,3)	9(1,4)
    10(2,0)	11(2,1)	12(2,2)	13(2,3)	14(2,4)
    15(3,0)	16(3,1)	17(3,2)	18(3,3)	19(3,4)
    20(4,0)	21(4,1)	22(4,2)	23(4,3)	24(4,4)

    */
    // 모든 셀을 순회하면서 빈 셀 찾기
    for (int i = 0; i < size * size; ++i) 
    {
        // i를 size로 나눈 몫은 행(y) 인덱스, 나머지는 열(x) 인덱스
        if (grid[i / size][i % size] == 0) 
        {
            // 빈 셀이면 해당 인덱스를 emptyCells 벡터에 추가
            emptyCells.push_back(i);
        }
    }

    // 빈 셀이 하나라도 있다면
    if (!emptyCells.empty()) 
    {
            //emptyCells의 인덱스 !!!!!!!
        int index = emptyCells[dis(gen) % emptyCells.size()];

        int y = index / size;  // 행 인덱스
        int x = index % size;  // 열 인덱스

        // 90% 확률로 2, 10% 확률로 4를 생성
        // dis(gen) % 10은 0부터 9까지의 난수를 생성
        // 이 값이 9보다 작으면(90% 확률) 2를, 그렇지 않으면(10% 확률) 4를 할당
        grid[y][x] = (dis(gen) % 10 < 9) ? 2 : 4;
        newSpawn = {y,x};
    }
    else
    {
        return false;
    }
#pragma endregion
#pragma region Genarate Separate X,Y Coordinate Method
    /*
    random_device rd;
    mt19937 gen(rd());
    vector<vector<int>> grid(5, vector<int>(5, 0));
    vector<vector<int>> emptycells(5, vector<int>(5));
    uniform_int_distribution<> ranCoord(0, 4);
    uniform_int_distribution<> ranNumProb(0, 100);

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (grid[i][j] == 0)
            {
                emptycells[i][j] = 0;
            }
        }

    }

    if (!emptycells.empty())
    {
        int x = ranCoord(gen);
        int y = ranCoord(gen);
        if (grid[y][x] == 0)
        {
            grid[y][x] = (ranNumProb(gen) < 90) ? 2 : 4;
        }
    }
    */
#pragma endregion
}

void GridGen::testprint()
{
	for (int y = 0; y < size; ++y)
	{
		for (int x = 0; x < size; ++x)
		{
            if(grid[y][x] == 0)
            {
                cout << "[ ]" << "\t";
            }
            else 
            {
                cout << "[" << grid[y][x] << "]" << "\t";
            }
		}
		cout << endl << endl;
	}
}


