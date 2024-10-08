/*
=======================================
<Tree>

-계층적인 자료를 나타내는데 자주 사용하는 자료구조
-부모노드가 여러 자식노드를 가질 수 있는 1대 다 구조
-한 노드에서 출발하여 다시 자기 자신의 노드로 돌아오는 순환구조를 가지지 않는다.

<트리 구성>

-부모 노드 : 루트 노드 방향으로 직접 연결된 노드
-자식 노드 : 루트 노드 반대 방향으로 직접 연결된 노드
-뿌리 노드 : 부모 노드가 없는 최상위 노드. Tree 의 Depth 0에 한개만 존재한다.
-가지 노드 : 부모 노드와 자식 노드가 모두 있는 노드. 트리의 중간에 위치
-잎 노드 : 자식 노드가 없는 노드 . 트리의 끝에 존재

-길이 : 출발 노드에서 도착노드까지 거치는 수
-깊이 : 루트 노드부터의 길이
-차수 : 자식 노드의 갯수

<사용처>

-주로 계층구조를 가질 수 있는 자료나 효율적인 검색에 많이 사용
-e.g) 윈도우의 폴더 구조,문서의 목차 , DB , 검색엔진의 구조등등
-상위 스킬을 배워야 하위스킬을 배울 수 있는 스킬트리

<트리의 구현>

-노드를 기반으로 부모노드와 자식노드를 보관할 수 있도록 구성

<Binary Tree>
                                                                                                                 
-부모 노드가 자식 노드를 최대 2개까지만 가질 수 있는 트리


[순회 방법]

- 트리는 비선형적인 자료구조이기 때문에 순차적으로 처리하기 순회에 대한 규칙이 있다.
	
	1.전위순회(PreOrder) : 노드 , 왼쪽 , 오른쪽 
	2.중위순회(InOrder) : 왼쪽 , 노드 , 오른쪽
	3.후위순회(PostOrder) : 왼쪽 , 오른쪽 , 노드

		  A	
		/   \
	   B     C
      / \   / \
	 D   E F   G

	전위순회(PreOrder) : A,(B,D,E),(C,F,G) => A-B-D-E-C-F-G
	중위순회(InOrder) : A,(B,D,E),(C,F,G) => D-B-E-A-F-C-G
	후위순회(PostOrder) : A,(B,D,E),(C,F,G) => D-E-B-F-G-C-A

=======================================
*/

#include <iostream>

using namespace std;

template <typename T>
class BinaryTree
{
public:
	struct Node
	{
		T data; //저장될 데이터
		Node* parent; //부모
		Node* left; //왼쪽 자식 노드
		Node* right; //오른쪽 자식노드

		Node(T data) : data(data), parent(nullptr), left(nullptr), right(nullptr) {}
	};
	Node* root; // 루트 노드

public:
	//루트 노드 반환
	Node* Root()
	{
		return root;
	}
	BinaryTree(T data)
	{
		root = new Node(data);
	}

	~BinaryTree()
	{
	}
	//왼쪽 자식 노드 추가
	Node* AddLeft(Node* parent,T data)
	{
		//이미 왼쪽에 자식이 있다면
		if(parent->left != nullptr)
		{
			cout << "이미 왼쪽에 자식이 있다" << endl;
			return nullptr;
		}
		//새로운 노드를 만들고 부모노드 왼쪽에 연결
		parent->left = new Node(data);
		//부모를 설정해주고 
		parent->left->parent = parent;
		//반환
		return parent->left;
	}
	Node* AddRight(Node* parent,T data)
	{
		//이미 오른쪽에 자식이 있다면
		if (parent->right != nullptr)
		{
			cout << "이미 오른쪽에 자식이 있다" << endl;
			return nullptr;
		}
		//새로운 노드를 만들고 부모노드 왼쪽에 연결
		parent->right = new Node(data);
		//부모를 설정해주고 
		parent->right->parent = parent;
		//반환
		return parent->right;
	}
	void deleteTree(Node* node)
	{
		if (node == nullptr) 
		{
			return;
		}
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}
	
	//출력 (중위)
	void PrintInOrder(Node* node) 
	{
		if(node==nullptr)
		{
			return;
		}
		PrintInOrder(node->left);
		cout << node->data << " ";
		PrintInOrder(node->right);
	}

	//출력 (전위)
	void PrintPreOrder(Node* node)
	{
		if(node==nullptr)
		{
			return;	
		}
		cout << node->data << " ";
		PrintPreOrder(node->left);
		PrintPreOrder(node->right);
	}

	//출력 (순회)
	void PrintPostOrder(Node* node)
	{
		if(node==nullptr)
		{
			return;
		}

		PrintPreOrder(node->left);
		PrintPreOrder(node->right);
		cout << node->data << " ";
	}
};

int main()
{
	//객체생성
	BinaryTree<int>* tree = new BinaryTree<int>(20);
	BinaryTree<int>::Node* node = nullptr;

	node = tree->AddLeft(tree->Root(), 30);
	tree->AddLeft(node, 100);
	tree->AddRight(node, 200);

	node = tree->AddLeft(tree->Root(), 40);
	tree->AddLeft(node, 400);
	tree->AddRight(node, 6000);

	tree->PrintInOrder(tree->Root());
}



