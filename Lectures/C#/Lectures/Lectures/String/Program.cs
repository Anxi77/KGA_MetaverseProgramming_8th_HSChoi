using System.Diagnostics;
using System.Globalization;
using System.Text;

namespace String
{
    internal class Program
    {
        static void Main(string[] args)
        {
            /*-string
            string은 내부적으로 char배열로 구현되어있다.
            */

            Console.WriteLine("Hello, World!");

            //C#에서의 struct(구조체)는 값형식 이다.
            string str = "abdce";
            Console.WriteLine(str);
            Console.WriteLine(str[0]);

            //문자열의 배열접근은 Read-Only이기에 인덱스로 접근하여 수정이 불가능하다
            //str[1] = "d"; 

            /*<string의 불변성(immutablity)>
             string은 특징상 다른 기본자료형과 다르게 크기가 정해져 있지 않은 기본 자료형이다.
             이유는 string은 char의 집합이므로 char의 갯수에따라 크기가 유동적이기에
             따라서 string은 런타임 당시에 크기가 결정 , 그 크기는 일정하지 않다.
             이에 string은 다른 기본자료형과 다르게 구조체가 아닌 class로 구현되어 있다(런타임시 크기를 정할 수 있는 메모리는 heap영역을 사용).
             단, 기본자료형과 같이 값형식을 구현하기 위해 string 클래스의 처리를 값형식처럼 동작하도록 구현
             이를 구현하기 위해 string 간의 대입이 있을 경우 참조에 의한 주소값 복사가 아닌 깊은 복사를 진행한다.
             결과적으로 데이터 자체를 복사하는 값형식으로 사용하지만 heap영역을 사용하기 때문에 string이 설정되면
             변경할수 없도록 하는 불변성을 가지게 됨.
             */

            string str1 = "abcde"; // heap 영역에 abcde 문자열을 저장하며 이를 str1이 참조
            str1 = "abc"; //새로운 heap 영역에 abc 문자열을 저장하며 이를 str1이 참조
            str1 = str1 + "123";//새로운 heap영역에 abc123 문자열을 저장하며 이를 str1이 참조

            string str2 = str1; //클래스지만 string은 값형식처럼 사용되어야 하기 때문에
            //힙 영역에 abc123 문자열을 복사하여 str2가 참조하도록 함.

            /*<메모리 파편화>
             string이 불변성 특정을 가지기 때문에 새로운 데이터를 string에 할당 할때마다 기존 데이터는 버려짐.
             버려지는 heap영역의 데이터는 가비지 컬렉터의 대상.
             */

            string str3 = "abc" + 123 + "def" + 456;

            /*이렇게 되면 +를 할때마다 가비지컬렉터가 이전 데이터를 삭제하고 새로운 데이터를 heap영역에 할당하기에 굉장히 비효율적이다.
            반복문을 쓰거나 문자열을 결합할 때에는 stringbuilder를 사용하는것이 훨씬 효율적이다.*/

            /*stringbuilder 와 그냥 대입의 시간복잡도 차이
            const int iter = 5000;
            Stopwatch stringStop = Stopwatch.StartNew();

            string res = "";

            for (int i = 0; i < iter; i++)
            {
                res += "a";
            }
            stringStop.Stop();
            Console.WriteLine($"스트링 : {stringStop.ElapsedMilliseconds}");

            Stopwatch StringBuilderStop = Stopwatch.StartNew();

            StringBuilder stringBuilder = new StringBuilder();

            for (int i = 0; i < iter; i++)
            {
                stringBuilder.Append("a");
            }
            StringBuilderStop.Stop();
            Console.WriteLine($"스트링빌더 : {StringBuilderStop.ElapsedMilliseconds}");
            */

            /*string 메서드
             * indexOf : 현재 문자열에서 찾고자 하는 지정된 문자 또는 문자열을 찾는다.
             * LastIndexOf : 위와 동일하나 뒤에서 부터
             * StringWith : 현재 문자열이 지정된 문자열로 시작하냐?
             * EndWith : 현재 문자열이 지정된 문자열로 끝나냐?
             * Contains : 현재 문자열이 지정된 문자열을 포함하냐?
             * Replace : 현재 문자열에서 지정된 문자열이 다른 지정된 문자열로 모두 바뀐 새로운 문자열을 반환
             * Length : 길이
             * Equals : 같냐?
             * SubString : 지정된 인덱스로부터 문자 추출
             * Trim : 공백을 제거해준다.
             * Split : 문자열을 분할.
             */

            string str5 = "Kyungil Game Academy";
            //대소문자 구분, 실패하면(없으면) -1을 반환
            Console.WriteLine("Game이 시작되는 위치는 어디냐 : {0}", str5.IndexOf("Game"));

            Console.WriteLine("Kyungil로 시작되냐 : {0}", str5.StartsWith("Kyungil")); //true
            Console.WriteLine("Academy로 시작되냐 : {0}", str5.StartsWith("Academy")); //false

            Console.WriteLine("Academy를 test로 : {0}", str5.Replace("Academy","test"));

            string original = "Hello, World";
            string substr = original.Substring(7, 5); //7번째 인덱스로부터 5개문자 추출
            Console.WriteLine(substr);//world
            
            //공백을 제거하는데 맨 앞과 맨 뒤만 제거해준다.
            string Space = "   Hello,   World      ";
            string SpaceTrim = Space.Trim();
            Console.WriteLine(SpaceTrim);

            //공백으로 문장을 나누기(Split 활용)
            string sentence = "공백으로 문장을 잘게 잘 게 나눠볼 까";
            string[] words = sentence.Split(' ');
            foreach (var word in words)
            {
                Console.WriteLine(word);
            }
        }
    }
}
