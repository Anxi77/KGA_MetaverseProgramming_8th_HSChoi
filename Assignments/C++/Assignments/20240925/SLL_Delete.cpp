#include "SLL.h"

SLL::SLL() : pHead(nullptr) {}

SLL::~SLL()
{
	//널 포인터가 아닐때까지 돌면서
	while (pHead != nullptr)
	{
		//현재 노드를 가리키는 포인터를 임시 노드에 저장
		node* temp = pHead;
		//다음 노드를 현재 노드로 설정
		pHead = pHead->pNext;
		//이전 노드를 삭제
		delete temp;
	}
}

void SLL::Insert(int num)
{
	//새로운 노드를 만들고
	node* newNode = new node(num);
	//만약 비어있다면(헤드가 없으면)
	if (pHead == nullptr)
	{
		//새로운 노드를 첫 노드로 설정
		pHead = newNode;
		return;
	}
	//아니면 돌면서 연결
	else
	{
		//리스트를 순회할 포인터
		node* temp = pHead;
		//리스트를 순회할 포인터가 null이 아닐때까지 돌면서
		while (temp->pNext != nullptr)
		{
			temp = temp->pNext;
		}
		temp->pNext = newNode;
	}
}

void SLL::Delete(int num)
{
	//리스트 자체가 비어있는 경우
	if (pHead == nullptr) {
		std::cout << "Empty" << std::endl;
		return;
	}

	// 첫 번째 노드가 삭제하려는 노드인 경우
	if (pHead->value == num) {
		node* temp = pHead;
		pHead = pHead->pNext;
		delete temp;
		return;
	}

	// 찾을 노드의 전 주소를 설정
	node* prev = pHead;
	// 찾을 노드를 설정
	node* curr = pHead->pNext;
	while (curr != nullptr)
	{
		if (curr->value == num)
		{
			// 삭제할 노드를 찾은 경우
			prev->pNext = curr->pNext;
			delete curr;
			return;
		}
		//순회 
		prev = curr;
		curr = curr->pNext;
	}

	std::cout << "Not Found " << std::endl;
}

void SLL::Print()
{
	node* temp = pHead;
	std::cout << "=========출력========" << std::endl;
	while (temp != nullptr)
	{
		std::cout << temp->value << " ";
		temp = temp->pNext;
	}
}

using namespace std;


int main()
{
	SLL s;

	s.Insert(1);
	s.Insert(1);
	s.Insert(2);
	s.Insert(1);


	s.Delete(1);

	s.Print();
}