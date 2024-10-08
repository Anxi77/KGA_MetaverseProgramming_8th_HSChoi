/*
Map
-연관컨테이너, 비선형적 구조이다.
-연관 컨테이너 중 빈번하게 사용한다.
ㄴ key 와 value 쌍으로 저장된다 (pair)
ㄴ 외부적으로 2진검색 트리로 구성되어있다 (Red Black Tree)
ㄴ 내부가 해시테이블로 구성되어 있다.
ㄴ key(고유함)는 컨테이너에 중복저장이 될 수 없다.
*/

#include <iostream>
#include <map>

using namespace std;
int main() 
{
	map<string, int>data;
	//반복자
	map<string, int>::iterator iter;

	//1.value_type을 이용하여 값을 저장
	//기본적인 키 값 쌍 타입을 나타낸다. 이 방법은 명시적으로 pair 객체를 생성하여 insert에 전달
	//가독성이 다소 떨어짐
	data.insert(map<string, int>::value_type("G", 5));

	//2.make_pair : pair 객체를 생성하는 함수 템플릿.
	//(make_pair("A", 7)) std::pair<string , int>타입의 객체를 생성
	//간결한 방법
	//템플릿 인자를 자동으로 추론하므로 타입이 명확하지 않을 수 있음
	//복잡한 타입을 다룰 때에는 명시적인 타입 선언이 필요할수 있다.
	data.insert(make_pair("A", 7));

	//3.pair를 이용한 방법 : 키-값 쌍으로 명시적으로 생성하여 삽입
	//명확한 타입 선언을 통해 가독성을 높일 수 있다.
	data.insert(pair<string, int>("월", 12));
	data.insert(pair<string, int>("화", 12));
	data.insert(pair<string, int>("수", 12));
	data.insert(pair<string, int>("목", 12));
	data.insert(pair<string, int>("금", 12));

	//4. 객체를 직접 생성하는 방법
	//pair의 템플릿 인자는 map의 key, value 타입과 일치해야한다.
	//객체를 생성한 후에 insert를 하기 때문에 필요에 따라 객체를 수정하거나 재사용 할 수 있다.
	pair<string, int>pt1("토", 300);
	data.insert(pt1);
	//객체 삭제
	data.erase("토");
	//출력
	for(auto& pair : data)
	{
		 cout << "키값 : " << pair.first << " , 데이터 : " << pair.second << endl;
	}
	
	/*
	find : 주어진 key를 찾아 iterator를 반환. 키가 존재하지 않으면 end를 반환.
	clear : map의 모든 요소를 삭제
	at : 주어진 키에 해당하는 값을 리턴
	*/

	//1.맵을 선언
	map<string, int>myMap;
	//2.insert를 사용하여 데이터를 추가.
	myMap.insert(make_pair("사과", 1));
	myMap.insert(make_pair("바나나", 2));
	myMap.insert(make_pair("파인애플", 3));
	myMap.insert(make_pair("포도", 4));
	//반복자를 사용하여 키와 값을 출력
	for(auto it = myMap.begin(); it!=myMap.end();++it)
	{
		cout << "키 : " << it->first << " , 값 : " << it->second << endl;
	}
	cout << endl;
	//반복자를 사용하여 키와 값을 역순으로 출력
	for (auto rit = myMap.rbegin(); rit != myMap.rend(); ++rit)
	{
		cout << "키 : " << rit->first << " , 값 : " << rit->second << endl;
	}
}