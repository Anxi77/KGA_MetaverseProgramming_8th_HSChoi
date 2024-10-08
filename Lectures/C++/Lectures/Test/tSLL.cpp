#include "tSLL.h"
#include <iostream>

using namespace std;

tSLL::~tSLL()
{
	while(pHead!=nullptr)
	{
		Node* temp = pHead;
		pHead = pHead->pNext;
		delete pHead;
	}
}

void tSLL::tInsert(int num)
{
	Node* newNode = new Node(num);

	if(pHead == nullptr)
	{
		pHead = newNode;
		return;//뒤에것 실행하지 않는다
	}
	else
	{
		Node* temp = pHead;
		while(temp->pNext != nullptr)
		{
			temp->pNext = temp;
		}
		temp->pNext = newNode;
	}
}

void tSLL::tDelete(int num)
{
	if(pHead == nullptr)
	{
		cout << "there is no list to delete" << endl;
		return;
	}
	if (pHead->value == num)  //삭제 하려는 노드가 맨 앞에 있을때
	{
		Node* temp = pHead;
		pHead = pHead->pNext;
		delete temp;
		return;
	}
	
	Node* Prev = pHead;
	Node* Curr = pHead->pNext;
	while (Curr != nullptr) 
	{
		if (Curr->value == num) // 삭제하려는 노드가 중간에 있을때(앞 뒤의 노드가 존재할때)
		{
			Prev->pNext = Curr->pNext;
			delete Curr;
			return; // 중간에 있어서 삭제 했으니 뒤에 오는 코드 실행 안하고 종료
		}
		Prev = Curr;
		Curr = Curr->pNext;
	}
	cout << "Not Found" << endl;

}

void tSLL::tPrint()
{
	Node* temp = pHead;
	cout << "=================출력===================" << endl;
	while(temp != nullptr)
	{
		cout << temp->value << " ";
		temp = temp->pNext;
	}
}
