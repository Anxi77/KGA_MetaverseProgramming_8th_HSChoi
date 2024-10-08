#include<iostream>

using namespace std;


class Parent {
	
private:

	int privateValue;

protected:
	int protectedValue;

public:
	int publicValue;
	
	Parent() : privateValue(1), publicValue(2), protectedValue(3){}

	void ShowValue()
	{
		cout << "부모클래스 privateValue : " << privateValue << endl;
		cout << "부모클래스 publicValue : " << publicValue << endl;
		cout << "부모클래스 protectedValue : " << protectedValue << endl;
	}
};

class ChildPulbic : public Parent {
public:
	void ShowValue() 
	{
		cout << "자식 클래스에서의  publicValue" << publicValue << endl;
		cout << "자식 클래스에서의  protectedValue" << protectedValue << endl;
		//엑세스 불가
		//cout << "자식 클래스에서의  privateValue" << privateValue << endl;
	}
};
class ChildProtected : protected Parent {
public:
	void ShowValue() {
		cout << "자식 클래스에서의  publicValue" << publicValue << endl;
		cout << "자식 클래스에서의  protectedValue" << protectedValue << endl;
		//엑세스 불가
		//cout << "자식 클래스에서의  privateValue" << privateValue << endl;
	}
};
class ChildPrivate : private Parent {
public:
	void ShowValue() {
		cout << "자식 클래스에서의  publicValue" << publicValue << endl;
		cout << "자식 클래스에서의  protectedValue" << protectedValue << endl;
		//엑세스 불가
		//cout << "자식 클래스에서의  privateValue" << privateValue << endl;
	}
};

int main()
{
	ChildPulbic c1;
	c1.ShowValue();

	cout << "c1.publicValue" << c1.publicValue << endl;
	//접근불가
	//cout << "c1.protectedValue" << c1.protectedValue << endl;
	//접근불가
	//cout << "c1.protectedValue" << c1.privateValue << endl;

	ChildProtected c2;
	c2.ShowValue();
	//접근불가
	//cout << "c1.publicValue" << c2.publicValue << endl;
	//cout << "c1.protectedValue" << c2.protectedValue << endl;
	//접근불가
	//cout << "c1.protectedValue" << c2.privateValue << endl;


	ChildPrivate c3;
	c3.ShowValue();
	//접근불가
	//cout << "c1.publicValue" << c3.publicValue << endl;
	//cout << "c1.protectedValue" << c3.protectedValue << endl;
	//접근불가
	//cout << "c1.protectedValue" << c3.privateValue << endl;
}