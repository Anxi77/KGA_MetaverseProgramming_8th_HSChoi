#include <iostream>

//1.box 구조체를 값으로 전달받아 각 멤버의 값을 출력하는 함수를 만들것.
//2.box 구조체를 전달받아 volume 멤버 변수를 다른 세가지 멤버의 곱으로 설정하는 함수를 만들것.

using namespace std;

struct Box
{
	string name;
	float height;
	float width;
	float length;
	float volume;
};
void boxinput(Box* b);
void boxinfo(Box& b);
void boxVolume(Box* b);


int main()
{
	Box b;
	
	boxinput(&b);
	boxinfo(b);
	boxVolume(&b);

}



void boxinfo(Box& b)
{
	cout << endl;
	cout << "입력하신 박스의 정보" << endl;
	cout << "=============================" << endl;
	cout << "박스의 이름 : " << b.name << endl;
	cout << "=============================" << endl;
	cout << "박스의 높이 : " << b.height << endl;
	cout << "박스의 너비 : " << b.width << endl;
	cout << "박스의 길이 : " << b.length << endl;
	
}

void boxVolume(Box* b)
{

	b->volume = b->height * b->width * b->length;
	cout << "=============================" << endl;
	cout << "박스의 부피 : " << b->volume;
}

void boxinput(Box* b)
{
	cout << "박스의 이름을 입력 해 주세요 : ";
	cin >> b->name;
	cout << "박스의 높이를 입력 해 주세요 : ";
	cin >> b->height;
	cout << "박스이 너비를 입력 해 주세요 : ";
	cin >> b->width;
	cout << "박스의 길이를 입력해 주세요 : ";
	cin >> b->length;
}

