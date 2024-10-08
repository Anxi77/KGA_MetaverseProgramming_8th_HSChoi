/*
2.피보나치수열 구현(첫번째 두번째 항이 1이고 그 다음 항부터는 앞 두 항의 합과 같음)
EX) 1, 1, 2, 3, 5, 8, 13
피보나치 수열의 n번째 항은(n - 1) + (n - 2)
*/

#include <iostream>
#include <vector>
using namespace std;

class fibonacci 
{
public:
	vector<unsigned long long>F;
	long fibo(int n)
	{
		cout << "계산중" << endl;
		if (n <= 1)
		{
			return 1;
		}
		return fibo(n - 1) +
			fibo(n - 2);
	}
	long long fiboVec(int n)
	{
		unsigned long long result;
		F.push_back(0); //F[0]=0
		F.push_back(1); //F[1]=1
		if (n < 2) //F[0]=0, F[1]=1 저장
		{
			return n;
		}
		else
		{
			for (int i = 2; i <= n; i++)
			{
				F.push_back(F[i - 1] + F[i - 2]);
				//F[i-1],F[i-2]를 다시 계산하지 않고 저장된 값을 꺼내서 씀.
			}
		}
		return F[n];
	}
};




int main()
{
	fibonacci* f = new fibonacci;
	int n = 0;
	cout << "숫자 입력 : ";
	cin >> n;
	system("cls");
	cout << "피보나치 수열의 (" << n+1 << ") 번째 항은 : " << f->fiboVec(n) << endl;
} 