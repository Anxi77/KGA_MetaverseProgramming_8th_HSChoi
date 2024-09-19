/*
string
-C++에서 제공하는 문자열을 다루기 위한 클래스
-C 스타일의 문자배열보다 쉽고 안전하고 유용하다.
-문자열의 크기를 자동으로 조정
-문자열 비교 연결 추출 검색 수정 다양한 멤버 함수들을 지원한다.

*/

#include <iostream>

using namespace std;

int main()
{
	string str = "Hello";
	string name = "Kyungil";
	string result;
	cout << "string 클래스를 사용한 출력 : " << str << endl;
	
	//문자열의 길이 계산(길이 반환)
	cout << "str의 길이 : " << str.length() << endl;
	cout << "str의 길이 : " << str.size() << endl;
	
	//문자열의 연결
	result = str + " , " + name + " !! ";
	cout << "연결결과 : " << result << endl;
	//substr : 부분 문자열 추출 : 특정 위치에서 지정된 길이만큼 부분 문자열을 추출한다.
	string sub = result.substr(0, 5);
	cout << sub << endl;
	cout << endl;
	//replace : 문자열 교체(문자열의 특정 부분을 다른 문자열로 교체)
	//.replace(0(시작위치),3(바꿀 길이),"Hi"(대체할 문자열))
	result.replace(0, 3, "Hi");
	cout << result << endl;
	cout << endl;
	//.empty : 해당 문자열이 비어있는지 확인
	if(str.empty())
	{
		cout << "비어있음"<<endl;
	}
	else
	{
		cout << "비어있지 않다"<<endl;
	}
	cout << endl;
	//append : 문자열의 끝에 다른 문자열 추가
	result.append("game");
	cout << result << endl;
	cout << endl;
	string test = "Hello World";
	//insert : 문자열의 지정한 위치에 다른 문자열 삽입
	test.insert(5, "-");
	cout << "insert : " << test << endl;
	//erase : 문자열의 지정한 위치에 지정한 길이만큼의 문자열 삭제
	test.erase(5, 2);
	cout << "erase : " << test << endl;
}
