using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20241008
{
    internal class Abstract
    {
        /*추상화
         - 클래스를 정의할때 구체화 시킬수 없는 기능을 추상적 표현으로 정의한다.
         - 인스턴스화 할수 없는 클래스이며 abstract 키워드를 사용하여 추상 클래스를 정의한다.
         - 하나 이상의 추상함수를 포함하는 클래스를 의미한다.
         - 클래스가 추상적인 표현을 정의하는 경우 자식에서 구체화 시켜 구현할것을 염두하고 추상화시킨다

        추상함수와 가상함수
         - 비슷한 역할(다형성)을 하지만 목적과 사용방법이 다르다.
         - 가상함수는 기본구현을 포함하고 자식 클래스에서의 필요에 따라 오버라이딩이 가능하다().
         - 오버라이딩을 사용하지 않는다면 부모클래스의 기본구현을 그대로 사용한다.

        [추상함수]
         - 반드시 추상함수는 자식에서 오버라이딩 해야한다.
         - 구현이 없고 자식클래스에서 구현
         - 다형성을 강제한다.

        [가상함수]
         */
        abstract class Item //추상클래스
        {
            public abstract void Use();//추상함수
            //일반 메서드도 포함 가능하다
            public void Print() 
            {
            }
        }
        class Potion : Item 
        {
            public override void Use() 
            {
                Console.WriteLine("포션으로 체력회복");
            }
        }
        abstract class Animal 
        {
            //어떤 동물이 어떻게 울건지 모른다.
            public abstract void Cry();
        }
        //상위클래스에서 구현하기 어려운 기능을 추상화 시켜놓은 뒤 자식클래스에서 구현한다.
        class Cat : Animal 
        {
            public override void Cry()
            {
                Console.WriteLine("야옹야옹");
            }
        }
        abstract class Shape //추상 함수를 포함하려면 abstract 키워드가 있어야 한다.
        {
            //추상
            public abstract void Draw();
            //가상
            public virtual void Show() 
            {
                Console.WriteLine("Shape 출력");
            }
        }
        class Circle : Shape
        {
            //추상함수 -> 강제성을 띈다
            public override void Draw()
            {
                
            }
            //가상함수 재정의 -> 필요에 의해서
            public override void Show()
            {
                Console.WriteLine("Circle 출력");
            }
        }
        static void Main(string[] args)
        {
            //Item item = new Item(); 추상 클래스는 인스턴스를 생성할 수 없다.

            //구체화한 자식에서는 인스턴스 생성이 가능하고 기능을 사용할 수 있다.
            Item item = new Potion();

        }
    }
}
