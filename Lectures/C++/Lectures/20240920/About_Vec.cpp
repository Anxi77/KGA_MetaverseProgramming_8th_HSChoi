/*
STL(스탠다드 템플릿 라이브러리)
-프로그램에 필요한 자료구조와 알고리즘을 템플릿으로 제공하는 라이브러리

STL구성요소
-컨테이너 : 객체를 보관하는 객체(일종의 커다란 창고)
ㄴ클래스 템플릿의 형태로 구현되어있다.
ㄴ각각의 원소에 접근할수 있도록 다양한 멤버함수들을 제공한다.
ㄴ접근하는 방법 : 직접함수를 호출하거나, 반복자(iterator)라는것을 이용해 접근
ㄴ이터레이터 : 포인터와 비슷한 개념. 컨테이너에 원소를 가리키고 가리키는 원소에 접근하여 다음 원소를 가리키게 하는 기능.

-시퀀스 컨테이너(선형 구조) : 컨테이너 원소가 자신만의 삽입위치(순서)를 가지는 컨테이너
ㄴvector, list, deque

-연관 컨테이너 (비선형 구조) : 저장원소가 삽입 순서와는 다르게 특정 정렬기준에 의거해 자동정렬되는 형태
ㄴset, multiset, map, multimap

vector , deque : 배열 - 데이터 여러개가 하나의 메모리 단위
list , set , multiset, map , multimap : 노드기반 - 데이터 하나를 하나의 메모리 단위

C++ : vector , map
C# : dic, list

C++에서의 list는 더블링크드(양방향 연결) 리스트 (노드(데이터를 저장하는 데이터 필드와 , 다음 데이터를 가리키는 포인터를 가지고 있음)기반 , 양방향)
C#에서의 list는 동적배열 구조이다.

중간 삽입삭제가 빈번한 경우에는 list가 유리함

-알고리즘 : 정렬, 삭제, 검색 등을 해결하는 일반화된 방법을 제공하는 함수템플릿.

-Vector
ㄴ가변길이배열
ㄴ순차적으로 저장되어 있고(메모리상) 외부적으로 동적배열을 사용하여 크기를 자동으로 조절한다.
ㄴ인덱스를 통해 임의의 원소에 접근 가능(배열의[], 멤버함수 at)

-동적배열과 Vector의 차이

-동적배열 : 프로그래머가 직접 메모리를 할당하고 해제.
ㄴ크기를 변경하려면 새로운 메모리를 할당하고 기존에 있던 요소를 복사를 한 다음 이전 메모리를 해제해야함.
ㄴ기본적인 배열 연산만 가능하다(인덱스를 통한 접근)

Vector : 직접 메모리를 할당하거나 해제할 필요가 없다 크기를 자동으로 조절하며 필요한 경우 새로운 메모리를 할당하고 기존요소를 복사한다.
ㄴ동적배열과 다르게 다양한 메소드를 제공,범위검사 , 예외처리 , 반복자 등을 지원한다.
 
 요약
 동적배열은 크기 변경이 필요없고 요소 접근만 가능하다면 오히려 성능적인 측면에서 나을 수 있다.
 만약 크기 변경시 새로운 메모리 할당과 기존요소 복사로 인해 성능저하가 발생될 수 있다.
 벡터가 일반적으로 동적배열보다 사용하기 쉽다 (알고 있다는 가정하에)
*/


#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int>v1;//int 타입 벡터 v1 생성
	vector<int>v2(10);//10개의 기본값(0)으로 초기화된 벡터 생성
	vector<int>v3(10, 5);//10개의 5를 초기화한 벡터 생성
	vector<int>v4 = { 1,2,3,4,5,6,7,8,9,10 };//초기화 리스트를 사용한 벡터 생성

	//벡터의 사이즈 size() : 원소의 갯수를 리턴
	cout << "백터의 사이즈 v1 : " << v1.size() << endl;
	cout << "백터의 사이즈 v2 : " << v2.size() << endl;
	cout << "백터의 사이즈 v3 : " << v3.size() << endl;
	cout << "백터의 사이즈 v4 : " << v4.size() << endl;
	cout << endl;
	cout << "===========================================" << endl;
	cout << endl;
	//capacity : 현재 할당된 메모리 내에서 저장할수 있는 최대 원소의 수
	cout << "벡터의 capacity v1 : " << v1.capacity() << endl; 
	cout << "벡터의 capacity v2 : " << v2.capacity() << endl;
	cout << "벡터의 capacity v3 : " << v3.capacity() << endl;
	cout << "벡터의 capacity v4 : " << v4.capacity() << endl;
	cout << endl;
	cout << "===========================================" << endl;
	cout << endl;
	//push_back : 벡터의 끝에 새로운 요소를 추가한다.
	//만약 크기가 현재 용량을 초과한다면 새로운 메모리를 할당하고 기존 요소를 새로운곳에 복사한다.
	v4.push_back(10);
	cout << "벡터의 capacity v4(push_back 후) : " << v4.capacity() << endl;
	//중간 삽입삭제가 빈번하게 일어나는 경우라면 속도가 느리다(고려해볼 필요가 있다). (한개씩 주소를 당기고 밀기 때문에)

	vector<int>v5;

	v5.push_back(1);
	v5.push_back(2);
	v5.push_back(3);

	for(int i = 0; i < v5.size(); i++)
	{
		cout << "for문으로 vector v5 출력 : " << v5[i] << endl;
	}

	cout << "=========================================" << endl;

	//범위기반 for(C++11 부터 지원한다)
	//컨테이너의 모든 요소를 간단하고 직관적으로 순회한다.
	//일반 for문은 더 많은 제어를 제공하지만 코드가 다소 복잡할 수 있다.
	//차이 : 범위기반은 문법이 간단하고 읽기가 쉽다 . 반복의 범위를 자동으로 설정
	//특정조건이나, 일부순회는 어렵다. 내부적으로 반복자를 사용한다.
	//벡터의 요소값을 int형 변수 i에 저장하고 출력된다 (복사형태)

	for(int i : v5)
	{
		cout << "범위기반으로 vector v5 출력 : " << i << endl;
	}
	for (int& i : v5)
	{
		cout << "범위기반으로(참조) vector v5 출력 : " << i << endl;
	}
	cout << endl;
	//auto : 타입추론 -> 컴파일러가 타입을 자동으로 추론
	//특히나 복잡한 타입을 사용할때 유용하다.(반복자 등)
	for (auto& i : v5)
	{
		i += 1;//참조의 형태로 값 변경도 가능하다.
		cout << "범위기반으로(참조 & 값변경) vector v5 출력 : " << i << endl;
	}
	//변경이 일어나지 않는 경우라면 const를 사용한다.
	for (const auto& i : v5)
	{
		cout << "범위기반으로(참조 & 값변경) vector v5 출력 : " << i << endl;
	}
	cout << endl;
	/*
	empty() : 벡터가 비어있는지 확인
	clear() : 벡터의 모든 요소 제거
	at() : 벡터의 요소에 접근
	front() : 벡터의 첫번째 요소를 반환.
	back() : 벡터의 마지막 요소를 반환.
	pop_back() : 벡터의 끝에서 요소를 제거
	insert() : 지정한 위치의 요소를 삽입
	erase() : 지정한 위치의 요소를 제거
	reserve() : 벡터의 용량을 지정
	shrint_to_fit() : 벡터의 현재 크기에 맞게 줄이
	swap() : 두 벡터를 교환
	*/
	cout << "============================================" << endl;
	vector<int>v6;
	v6.push_back(1);
	v6.push_back(2);
	v6.push_back(3);
	v6.push_back(4);
	v6.insert(v6.begin() + 1, 10); //인덱스 1에 10을 삽입
	v6.erase(v6.begin() + 3);//인덱스 3의 요소 제거
	v6.pop_back();//마지막 요소 제거

	for (auto& i : v6)
	{
		cout << i << endl;
	}
	cout << endl;
	cout << "============================================" << endl;

	vector<int>v7;
	v7.push_back(1);
	v7.push_back(2);
	v7.push_back(3);
	v7.push_back(4);
	v7.push_back(5);
	
	//반복자
	//반복자는 포인터와 비슷하게 동작한다. 컨테이너의 저장한 원소를 순회하고 접근하는 방법을 제공
	//begin() : 시작을 나타냄(실제 원소가 있는 위치)
	//end() : 실제 원소가 아닌 끝을 나타냄(마지막 요소의 다음)
	for (vector<int>::iterator it = v7.begin();it!=v7.end(); it++)
	{
		cout << *it << " "; //포인터와 비슷하게 역참조를 사용하여 값을 불러올 수 있다.
	}
	cout << endl;
	vector<int>::iterator iter = v7.begin();//시작원소를 가리키는 반복자
	cout << iter[0] << endl;
	cout << iter[1] << endl;
	cout << iter[2] << endl;
	cout << iter[3] << endl;
	cout << iter[4] << endl;
	cout << endl;

	vector<int>vec = { 10,20,30,40,50 };
	//반복자라는 것을 스스로 추론
	for(auto it = vec.begin(); it !=vec.end(); ++it)
	{
		cout << *it << endl;
	}
}