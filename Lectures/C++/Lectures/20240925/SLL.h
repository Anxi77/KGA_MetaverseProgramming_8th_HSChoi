#pragma once
#include <iostream>

struct node
{
	int value;      // 노드가 저장하는 실제 데이터 값
	node* pNext;    // 다음 노드를 가리키는 포인터

	node(int n) : value(n), pNext(nullptr) {} // 노드의 생성자로 노드의 값을 매개변수로 받고 , 다음 노드의 주소를 가리키는  pNext 의 주소를 null로 초기화
};
//SLL Class
class SLL
{
private:
	//SLL의 첫번째 노드를 가리키는 포인터
	node* pHead;
public:

	SLL();
	~SLL();

	void Insert(int num);

	void Delete(int num);

	void Print();

};

