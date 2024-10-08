/*
Stack VS Queue

Last In Fist Out (LIFO) - 마지막에 들어온 데이터가 가장 먼저 나간다. (후입선출)

|		|
|		|
|		|
|		|
|		|
---------

-push : stack에 새로운 요소를 추가하는 연산.
-pop : 최상단 요소를 제거하고 반환
-top(peek) : 스택의 최상단 요소를 반환
-empty : 스택이 비어있는지 확인

*/

#include <iostream>
#include <assert.h>

template<typename T>
class Stack
{
private:
	static const int MAX_VALUE = 5;
	int top;
	T value[MAX_VALUE];
public:
	Stack():top(-1)
	{
		for(int i = 0; i < MAX_VALUE; ++i)
		{
			value[i] = T();
		}
	}
	void Push(T val)
	{
		//assert
		//프로그램에서 치명적일수 있는 문제에서 프로그램을 중단하고 오류를 표시
		//프로그램을 중단시키고 오류를 표시하기 때문에 개발자의 디버깅에 용이
		assert(top + 1 < MAX_VALUE);//스택이 오버플로우하지 않도록 확인

		value[++top] = val;
	}
	T Pop()
	{
		assert(!Empty());

		T val = value[top];//스택의 최상위값을 임시로 저장하고
		value[top--] = T();
		return val;
	}
	T Top()
	{
		return value[top];
	}
	bool Empty()const
	{
		return top < 0;
	}
};

using namespace std;

int main()
{
	Stack<int> stack;

	stack.Push(10);
	stack.Push(20);
	stack.Push(30);
	stack.Push(40);
	stack.Push(50);


	cout << "Top : " << stack.Top() << endl;
	cout << "Pop : " << stack.Pop() << endl;
	cout << "Pop : " << stack.Pop() << endl;
	cout << "Pop : " << stack.Pop() << endl;
	cout << "Pop : " << stack.Pop() << endl;
	cout << "Top : " << stack.Top() << endl;

	//과제

}