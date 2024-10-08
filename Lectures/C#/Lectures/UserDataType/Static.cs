using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

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
 - 모든 멤버가 정적이어야 한다.
 - 상속이 불가능하다.
 */

namespace UserDataType
{
    //정적 클래스
    static class Math 
    {
        //int a; 정적 클래스에는 인스턴스 멤버를 선언할수 없다.

        //void Print() { } 마찬가지로 메서드를 선언할 수 없다.

        public static int b;

        public static int Sum(int a, int b)
        {
            return a + b;
        }

    }
    class Math1 
    {
        public static int b;
        public Math1() 
        {

        }
        public static int Sum(int a, int b) 
        {
            return a + b;
        }
    }
    internal class Static
    {
        static void Main(string[] args) 
        {
            int sum = Math1.Sum(1, 2);

            Math.Sum(1, 2);
        }
       
    }
}
