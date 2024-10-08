using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UserDataType
{
    internal class Class03
    {
        /*프로퍼티
         ㄴ클래스의 필드에 간접적으로 접근할수 잇게 해주는 것.
         ㄴ데이터 캡슐화 접근 제어를 가능하게 한다.
         */
        class Circle
        {
            double pi = 3.14;
            //구방식(메서드를 통해 필드로 접근)
            double GetArea(double rad) 
            {
                return rad * rad * pi;
            }
            //명시적인 프로퍼티
            //get , set
            public double Pi 
            {
                get { return pi; }
                set { pi = value; } //value = 접근자 내부에서 사용되는 키워드(외부에서 프로퍼티에 설정하려는 값).
            }            
        }
        class Person 
        {
            //자동구현 프로퍼티
            public string name { get; set; } 

            /*아래와 같은 형태로 만들어줌
            private string _name;
            public string Name 
            {
                get { return _name; }
                set { _name = value; }
            }
            */
        }
        class Person1
        {
            /*읽기전용 프로퍼티
              아래와 같은 형태는 초기화 된후 변경할 수 없다.
              생성자를 통해 값을 설정해야함.
             */
            public string name { get; }

            public Person1(string name) 
            {
                this.name = name;
            }
        }
        class Person2 
        {
            //외부에서 값을 설정할 수 있지만 읽을수 없다.
            private string _name;
            public string Name { set { _name = value; } }
        }
        static void Main(string[] args) 
        {
            Person person = new Person();

            person.name = "test";
            Console.WriteLine(person.name);
            //읽기전용이므로 생성자를 통해 넣어주어야 한다.
            Person1 person1 = new Person1("김");
            Console.WriteLine(person1.name);
            //쓰기전용이므로 불러올수 없다.
            Person2 person2 = new Person2();
            person2.Name = "345";
            //Console.WriteLine(person2.Name); <-오류
        }
    }
}
