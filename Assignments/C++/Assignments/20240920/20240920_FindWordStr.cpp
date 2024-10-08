/*
과제3. 문자열 내 단어찾기
*/

#include <iostream>
#include <string>

using namespace std;

int CountWord(const string& str)
{
	int word = 1;
	
	
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] == ' ')
		{
			word++;
		}
	}

	return word;
}

int main ()
{
	string str = "나는 서울에 사는 홍길동 입니다 라고 할 줄 알았지";
	cout << str << endl;
	cout << "문자열 내 단어 갯수는 : " << CountWord(str) << endl;
}