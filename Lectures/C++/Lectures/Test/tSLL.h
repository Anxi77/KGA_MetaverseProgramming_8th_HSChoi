#pragma once

struct Node
{
	int value;
	Node* pNext;

	Node(int num) :value(num), pNext(nullptr) {}
};

class tSLL
{
private:

	Node* pHead;

public:

	tSLL() :pHead(nullptr) {};
	~tSLL();
	void tInsert(int num);
	void tDelete(int num);
	void tPrint();
};

