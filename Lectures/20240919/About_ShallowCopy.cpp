
/*
==========================================
얕은복사

==========================================

*/


#include<iostream>

using namespace std;

class MyArray 
{

private:

	int size;//멤버변수
	int* data;//포인터 멤버변수

public:
	MyArray(int size):size(size), data(new int[size]){}

	// 기본복사 생성자(얕은복사)->자동으로 넣어줌
	//MyArray(const MyArray& other) :size(other.size), data(other.data) {
	//	cout << "얕은 복사 생성자 호출" << endl;
	//}
	~MyArray() {
	
		delete[] data;
	}
	
public:
	void SetValue(int index, int value) { data[index] = value; }
	int GetValue(int index) { return data[index]; }

	int* GetDataAddr() { return data; }
};

int main() 
{
	MyArray arr1(10);
	arr1.SetValue(0, 42);

	MyArray arr2(arr1);//얕은 복사 생성자를 호출

	cout << "arr1의 첫번째 값 : " << arr1.GetValue(0) << endl;
	cout << "arr2의 첫번째 값 : " << arr2.GetValue(0) << endl;

	arr1.SetValue(0, 84);

	cout << "arr1의 값 변경후 : " << arr1.GetValue(0) << endl;
	cout << "arr2의 첫번째 값(arr1이 변경된 후) : " << arr2.GetValue(0) << endl;

	cout << arr1.GetDataAddr() << endl;
	cout << arr2.GetDataAddr() << endl;



}