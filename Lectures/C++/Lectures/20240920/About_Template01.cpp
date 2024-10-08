/*

*/
//기본 클래스 : Shape -< 추상

#include <iostream>

template<typename T>
class Shape
{
public:
	virtual void Draw()const = 0;
	virtual T area()const = 0;
};
//circle : shape를 상속받는 템플릿 클래스
template<typename T>
class Circle : public Shape<T>
{
private:
	T radius;
public:
	Circle(T r) : radius(r) {}
	void Draw()const override 
	{
		std::cout << "원의 반지름 : " << radius << std::endl;
	};
	T area()const override
	{
		return 3.14 * radius * radius;
	}
};
template <typename T>
	class Rectangle : public Shape<T>
{
private:
	T width;
	T height;
public:
	Rectangle(T w, T h) :width(w), height(h) {}
	void Draw()const override
	{
		std::cout << "가로 : " << width << " 세로 : " << height << std::endl;
	}
	T area()const override
	{
		return width * height;
	}
};

template<typename T>
void DrawShape(const Shape<T>* shape)
{
	shape->Draw();
	std::cout << "면적 : " << shape->area() << std::endl;
}

int main()
{
	Circle<double> circle(3.14);
	Rectangle<int> rectangle(5, 7);
	DrawShape(&circle);
	DrawShape(&rectangle);
}
