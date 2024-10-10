/*
C#은 다중상속이 불가(인터페이스 사용하여 다중상속 비슷함)
C#은 가비지컬렉터 사용하여 메모리 관리 자동
C++ 템플릿 비슷 C# 제네릭
CLR C#(NATIVE) != SCRIPTING C#(UNITY)
*/

namespace _20241007
{
    internal class Program
    {
        static void Main(string[] args)
        {

            //1.기본출력

            Console.WriteLine("Hello, World!");

            /*2.변수            
            int a = 1;
            Console.WriteLine(a);
            */

            /*3.Format 메서드
            중괄호를 이용하여 코드에서 사용하는 변수나 서식을 넣어주는 방법
            중괄호 내부에 넣는 숫자를 첨자라 칭함 , 첨자의 시작은 0부터
            문자열이 끝나고 콤마 뒤에 순서대로 0,1,2에 맞게 넣을 변수들을 입력한다.
            Console.WriteLine("경일: {0},{1}", "HH", "1234");
            */

            int num = 1;
            string str3 = string.Format("경일: {0},{1},{2}", "HH", 1234, num);
            Console.WriteLine(str3);

            /*4.문자열 보간을 이용한 방법
             format방식과 달리 string안에 직접 변수이름을 넣는다.
            */

            int a = 10;
            int b = 10;

            Console.WriteLine($"테스트 : {a}+{b} = {a+b}");

            /*Data Types

            bool

            byte
            sbyte

            short
            int
            long

            ushort
            uint
            ulong
            
            float
            double

            char
            string
            */

            /*상수            
            const int Max = 200;
            const int min; //초기화 없이 사용 불가
            Max = 111; // 데이터 변경 불가
            */

            /*형변환 <TypeCasting>
            <명시적 형변환>
             - 변환할 데이터의 앞에 변환할 자료형을 괄호안에 넣어 형변환 진행
               //int intvalue = 1.2; //명시적 형변환 없이 변환 불가
               int intvalue = (int)1.2; //명시적 형변환 없이 변환 불가
               Console.WriteLine(intvalue);

            <묵시적 형변환>
            - 변수에 데이터를 넣는 과정에서 자료형이 더 큰 범위를 표현하는 경우 자동으로 형변환 진행
              float floatvalue = 3;//부동소수점형 변수에 정수형 데이터를 넣을 경우 자동형변환 가능
              double doubleValue = 1.2f;//double은 float 을 포함하는 큰 범위이기 때문에 자동형변환 가능

            <문자열 형변환>
            - 문자열은 단순 형변환이 불가하다
            - 각 자료형의 parse,TryParse를 이용하여 문자열에서 자료형으로 변환
              int value = int.Parse("1234");//Parse 매서드를 통하여 string 데이터를 int type으로 casting
            - ToString : 문자열로 형변환
              string text1 = (true).ToString();
              string text2 = (1234).ToString();
            */

            /*Object , Value / Ref
            int , double과 같은 형식은 값 형식이기에 stack에 데이터를 할당한다.
            object는 참조타입이기에 heap에 데이터를 할당한다.
            object는 값형식의 데이터를 heap에 할당하기위해서 Boxing이라는 기능을 제공
            object 형식에 값 형식의 데이터를 할당하려고 한다면 오브젝트 형식은 Boxing을 지원해서 해당 데이터를 heap에 할당
            object 변수가 heap에 할당되어있는 데이터의 주소를 참조

            //1.object a = 3;
            //2.int b = (int)a;

            //1에서의 a는 3이 박싱되어 저장된 heap을 참조
            //2에서의 b는 a가 참조하고 있는 메모리부터 값을 복사하려고 함.
            //1에서 박싱된 a의 3이라는 데이터를 언팩하여 추출 , b에 복사 후 저장.
            //stack -> a(heap 에 있는 데이터 3 참조) , b = 3
            //heap -> 3

            */

            int a1 = 11234;
            object b = a1;//a에 담긴 값을 박싱해서 heap에 저장
            int c = (int)b;//b에 담긴 값을 언박싱해서 스택에 저장

            /*값형식*/
            int n1 = 5;
            int n2 = n1;

            /*참조형식
             1.같은 heap 영역의 주소를 가지는 s1 , s2가 된다 
             2.s2에 s1이 가리키는 주소를 복사 한다.
             
             값 형식과 참조 형식의 차이점
             박싱과 언박싱이 빈번하게 일어난다면 메모리 할당과 해제의 추가적인 작업이 필요하기에 성능저하가 발생함.
             박싱으로 힙에 할당된 인스턴스들이 많아지게 되면 가비지 컬렉션이 많이 발생됨(부담이 된다).
             피하기 위하여 제네릭을 활용할수 있음
             stringbuilder
            */

            string s1 = "dd";
            string s2 = s1;
            
            /*
             제네릭
             박싱이 일어날수 있는 코드를 가급적 피하는 것이 좋다
             피하기 위해 제네릭을 보편적으로 사용한다.
            */

            //1.값 형식과 참조 형식의 차이점
            //2.박싱과 언박싱
            //3.StringBuilder vs String
            //4.배열
            //ㄴ학생성적 입력받아 배열에 저장
            //ㄴ입력된 성적중 가장 높은 성적과 낮은 성적 출력
            //ㄴ평균 성적 계산
            //ㄴ오름차순 정렬
            //5.문자열 내 단어 뒤집기
            //ㄴ문자열을 입력받고 해당 문자열의 간 단어를 뒤집는다.
            //ㄴ입력예시)"abcd efgh"
            //ㄴ출력예시)dcba hgfe
        }
    }
}
