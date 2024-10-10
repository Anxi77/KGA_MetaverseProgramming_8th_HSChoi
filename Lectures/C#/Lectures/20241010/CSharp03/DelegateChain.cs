using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/*[델리게이트 체인]

  델리게이트 하나가 복수의 메서드를 동시에 참조할 수 있다.
 */

namespace CSharp03
{
    delegate void Student(string s);

    class Test
    {
        public void Print01(string str)
        {
            Console.WriteLine($"학생 {str}이/가 등교");
        }
        public void Print02(string str)
        {
            Console.WriteLine($"학생 {str}이/가 점심");
        }
        public void Print03(string str)
        {
            Console.WriteLine($"학생 {str}이/가 집에감");
        }
    }


    /*이벤트
    일련의 사건이 발생했다는 사실을 다른 객체에게 전달

    -이벤트의 구현과정-
    1.델리게이트 선언
    2.클래스 내에서 선언한 델리게이트 인스턴스를 event 한정자로 선언한다.
    3.이벤트 핸들러를 작성.
    4.클래스의 인스턴스를 생성하고 이 객체의 이벤트에 이벤트 핸들러를 등록
    5.이벤트가 발생하면 이벤트 핸들러가 호출
     */

    delegate void EventHandler(string str); //string을 매개변수로 받는 메서드를 참조할수 있는 델리게이트

    class EventTest 
    {
        public event EventHandler eve; //이벤트 선언
        public void Func(int num) 
        {
            int temp = num % 10;
            if (temp != 0 && temp % 3 == 0)
            {
                eve($"{num}");
            }
        }
    }

    

    internal class DelegateChain
    {

        ///////////////////////////

        public static void MyHandler(string str)
        {
            Console.WriteLine($"{str}");
        }

        ///////////////////////////

        public delegate void TestDel(int a, int b);

        public static void SumNumber(int a, int b) 
        {
            Console.WriteLine($"덧셈 : {a + b}");
        }

        public static void MulNumber(int a, int b)
        {
            Console.WriteLine($"곱셈 : {a * b}");
        }
        static void Main(string[] args)
        {
            Test t = new Test();
            t.Print01("홍길동");

            Student student = new Student(t.Print01);
            t.Print02("홍길서");

            student += t.Print02; //델리게이트는 연산자를 통하여 연결이 가능하다.
            t.Print02("홍길남");

            student += t.Print03;

            TestDel testDel = SumNumber;
            testDel = SumNumber;
            testDel += MulNumber;
            testDel -= MulNumber; //체인에 연결되어있는 메서드를 제거한다.

            testDel.Invoke(10, 20); //Invoke : 델리게이트에 연결되어 있는 메서드들을 순차적으로 실행해준다.

            //이벤트 객체 생성
            EventTest eventTest = new EventTest();

            eventTest.eve += MyHandler; //이벤트 핸들러 등록

            for(int i = 0; i < 30; i++) 
            {
                //event occurs when num ends with 3 , 6 , 9
                eventTest.Func(i);
            }
        }
    }
}
