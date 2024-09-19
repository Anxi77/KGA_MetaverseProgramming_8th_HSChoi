
#include<iostream>
using namespace std;

/*
==========================================
-namespace
ㄴ이름공간.이름충돌을 방지하기 위한 녀석.
==========================================

*/
namespace A {
	void Print() {
		cout << "나는 A공간에 살고있는 김철수라고행~";
	}
}
namespace B {
	void Print() {
		cout << "나는 B공간에 살고 있는 김철수 라고행";
	}
}
namespace out {

	namespace in {
		void Show() {
			cout << "dd" << endl;
		}
	}
}
namespace math 
{
	int sum(int a, int b)
	{
		return a + b;
	}
}
int main() 
{
	A::Print();
	B::Print();
	out::in::Show();
	//math::sum
}