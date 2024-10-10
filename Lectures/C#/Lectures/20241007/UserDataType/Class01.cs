using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace UserDataType
{
    internal class Class01
    {
        class Student 
        {
            public string name;
            public int math;
            public int eng;
            public int science;

            public float GetAverage()
            {
                return (math + eng + science) / 3.0f;
            }
        }
        void Main1() 
        {
            Student kim = null;//지역변수를 생성하고 null(아무것도 없음)을 참조
            kim = new Student();//클래스 인스턴스를 생성하고 지역변수가 인스턴스를 참조
            kim.name = "kim"; //인스턴스의 변수에 접근하기 위해선 참조한 변수뒤에 .을 붙여 사용

            float average = kim.GetAverage();//클래스의 함수에 접근하기 위해서 참조한 변수뒤에.을 붙여 함수를 사용
        }
        class Car 
        {
            public string name;
            public string color;

            //기본 생성자는 다른 생성자를 포함하지 않은 경우에만 자동생성
            //public Car() 
            //{

            //}
            public Car(string name, string color) 
            {
                this.name = name;
                this.color = color;
            }
        }
        void Main2() 
        {
            Car car;
            //car.name = "ddd";//클래스의 지역변수는 인스턴스없이 사용불가
            Car truck = new Car("트럭", "빨강이");
            //Car taxi = new Car(); -> error 기본 생성자는 다른 생성자를 포함하지 않은 경우에만 자동생성
        }
        /*<클래스 얕은복사>
        클래스에 대입 연산자를 통해 같은 인스턴스를 참조
        */
        class MyClass 
        {
            public int value1;
            public int value2;
        }

        public static void Main3() 
        {
            MyClass s = new MyClass();
            s.value1 = 1;   
            s.value2 = 2;

            MyClass t = s;//같은 인스턴스 참조
            t.value1 = 3;

            //같은 인스턴스를 참조하기에 복사본을 변경하는 경우 원본도 변경된다.
            Console.WriteLine(s.value1);//3
            Console.WriteLine(s.value2);//2

            Console.WriteLine(t.value1);//3
            Console.WriteLine(t.value2);//2
            


        }
        struct valueType 
        {
            public int value;
        }
        class RefType 
        {
            public int value;
        }

        /*값에 의한 호출 CallByValue
        //값형식의 데이터가 전달되며 데이터가 복사되어 전달.
        함수의 매개변수로 전달하는 경우 복사한 값이 전달되며 원본은 유지됨.*/

        //참조에 의한 호출 CallByRef
        //참조형식의 데이터가 전달됨 , 주소가 복사되어 전달
        //함수의 매개변수로 전달하는 경우 주소가 전달. 주소를 통해 접근하기 때문에 원본을 전달하는 효과
        static void Swap(valueType left, valueType right) 
        {
            int temp = left.value;
            left.value = right.value;
            right.value = temp;
        }
        //데이터가 복사되어 함수로 넘어가기 때문에 원본이 변하지 않는다.
        static void Swap(RefType left,RefType right) 
        {
            int temp = left.value;
            left.value = right.value;
            right.value = temp;
        }
        static void Main5() 
        {
            valueType leftValue = new valueType() { value = 10 };
            valueType rightValue = new valueType() { value = 20 };
            Swap(leftValue, rightValue);//데이터의 복사본이 함수로 들어가기에 원본이 바뀌지 않음
            Console.WriteLine($"{leftValue.value},{rightValue.value}");

            RefType leftRef = new RefType() { value = 10 };
            RefType rightRef = new RefType() { value = 20 };
            //Swap(leftRef,rightRef);
        }

        static void Main6() 
        {
            RefType original = new RefType();
            
            //얕은복사
            RefType shallowcopy = original;

            //깊은복사 , 복사를 받아 별도의 heap 공간에 객체를 생성하려면
            RefType deepcopy = new RefType();
            deepcopy.value = original.value;

            //.net에서 지원하는 interface : Icloneable 인터페이스의 clone메서드를 오버라이딩 해서 쓰면 됨.

        }
        //데이터가 참조타입(원본 데이터를 가리키는 주소)으로 함수로 넘어가기에 원본이 변한다.
        static void Main(string[] args)
        {
            Main3();
            Main5();
            Main6();
        }
    }
}
