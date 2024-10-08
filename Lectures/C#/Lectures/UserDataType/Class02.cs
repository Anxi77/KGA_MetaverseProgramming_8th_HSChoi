using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UserDataType
{
    internal class Class02
    {

        //생성자를 다시 봅시다
        //1.생성자가 없어도 기본 생성자 호출
        class Person 
        {
            
        }
        //2. 매개변수가 있는 생성자
        class Person1 
        {
            public int age;
            public string name;

            public Person1(int age, string name)
            {
                this.age = age;
                this.name = name;
            }
        }
        //3.생성자 오버로딩
        class Person2 
        {
            public string name;
            public int age;

            //오버로딩이 가능하다.
            public Person2()
            {
                name = "ggg";
                age = 1;
            }
            public Person2(string name) 
            {
                this.name = name;
                age = 2;
            }
        }
        class Person3 
        {
            public string name;
            public int age;
            public Person3() : this("홍길동", 3) { }
            //this 생성자가 밑의 생성자를 호출
            public Person3(string name, int age)
            {
                this.name = name;
                this.age = age;
            }
        }
        class Person4 
        {
            public static int age;
            public Person4() 
            {
                age = 4;
            }
        }
        /*정적변수(static Variable)
         - 인스턴스가 아닌 클래스 자체에 포함.
         - 인스턴스 참조를 통하여 액세스 할수 없고 클래스 자체를 참조하여 액세스한다.
         - 하나의 정적 필드는 모든 인스턴스가 동일한 값을 공유한다.
         

         -정적 함수/메서드(static function/method)
         - 인스턴스가 없어도 호출
         - 인스턴스 멤버에는 접근 x
         - 객체의 인스턴스와 무관하게 클래스 자체에 속하는 메서드
         
        
         -정적 클래스(static class)
         - 인스턴스를 생성할수 없음.
         */
        static void Main(string[] args) 
        {
            Person p1 = new Person(); //1.기본 생성자 호출
            Person1 p2 = new Person1(16, "김"); //2.매개변수가 있는 생성자
            Person2 p3 = new Person2(); //3.오버로딩
            Person3 p4 = new Person3(); //4.this 생성자
            Person4 p5 = new Person4(); //5.static

            Console.WriteLine(Person4.age); //static으로 선언하였기에 불러올때 클래스명으로 멤버에 접근한다.
        }
    }
}
