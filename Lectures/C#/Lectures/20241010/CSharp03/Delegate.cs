namespace CSharp03
{
    internal class Program
    {
        /*
         델리게이트
        - 특정 반환형식과 매개변수를 가지는 메서드의 참조를 저장하는 형식
        - 대리자 인스턴스를 통해 함수를 호출할 수 있다
        - 델리리게이트는 메서드에 대한 참조이며 델리게이트의 메소드의 주소를 할당한 후
        델리게이트를 호출하면 이 델리게이트가 메서들 호출해줌
        -델리게이트는 메서드에 대한 참조이기 떄문에 자신 참조할 반환형식과 메서드를 명시해주어야 한다.

        한정자 delegate int(자료형) 델리게이트 이름(매개변수1,매개변수2...)

        [요약]
        1.델리게이트 선언
        2.선언한 델리게이트가 참조할 메서드를 선언
        3.델리게이트의 인스턴스를 만들고 델리게이트가 참조할 메서드를 매개변수로 넘긴다
        4.델리게이트 호출

        - 메서드를 동적으로 바인딩 할 수 있어 유연성이 좋음
        - 이벤트 처리나 콜백 메서드에 자주 사용
               

        -ToDo-
        delegate , event , Action , Func 에 대한 이해가 필요
        Func와 Action 의 차이에 대해 알아야 함
        delegate의 유형 - event action func
        Action , Func 등은 내부적으로 delegate를 지원한다.
        Lambda에 대한 이해
         */

        //1.델리게이트 선언
        //반환형이 int 타입이고 매개변수가 int형을 받는 델리게이트를 선언
        public delegate int MyDel(int a, int b);

        //2.참조할 메서드 선언
        static int Plus(int a, int b)
        {
            return a + b;
        }
        static int Minus(int a, int b)
        {
            return a - b;
        }
        //반환형과 매개변수가 다르기 때문에 델리게이트에서 참조할 수 없다.
        static void Message(string msg) { Console.WriteLine(msg); }


        static void Main(string[] args)
        {
            MyDel callback;
            callback = new MyDel(Plus);

            Console.WriteLine(callback(1,2));

            MyDel callback2 = Minus;

        }
    }
}
