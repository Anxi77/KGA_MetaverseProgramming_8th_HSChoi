/*
*문자배열*

-말 그대로 문자를 저장하는 배열.
-문자열을 저장할때는 배열의 마지막에 null 문자를 추가하여 문자열의 끝을 표시해야함.


**C 스타일의 문자열 함수 종류
 -strlen(const char* str) : 문자열의 길이를 반환한다.
 -strcpy(char* dest, char* src) : 문자열 복사.
 -strcat : 문자열 연결
 -strcmp : 문자열 크기 비교
*/
#include <iostream>


using namespace std;


int main()
{
	//char str[6];
	//char str1[6] = {'H','e', 'l', 'l', 'o','\0'};//'\0' 널문자로 문자열의 마지막을 표시한다는 뜻이다.

	//for (int i = 0; i < 6; i++) 
	//{
	//	cout << str1[i];
	//}
	//
	//char str2[] = "Hello"; //자동으로 배열의 크기 배정 , 널문자도 들어간다.

	//for(int i = 0; i < str2[i]!='\0'; i++)
	//{

	//}

	//char str3[] = "한글"; //한글은 한 글자당 2바이트를 차지한다.

	char str1[20] = "Hello";
	char str2[10] = "Kyungil";
	char str3[10];

	cout << "str1의 길이 : " << strlen(str1) << endl;
	cout << "str2의 길이 : " << strlen(str2) << endl;
	cout << endl;
	strcpy_s(str3, str1);
	cout << "strcpy : " << str3 << endl;
	strcat_s(str1, str2);
	cout << "strcat_s : " << str1 << endl;

}