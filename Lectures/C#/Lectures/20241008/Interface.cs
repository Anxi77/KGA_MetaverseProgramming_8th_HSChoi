using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace _20241008
{
    /*추상클래스와 인터페이스의 차이*/
    /*
     인터페이스 (interface)
     - 추상클래스와 동일한 부분은 다형성을 지원한다.
     - 통상적으로 함수의 구현은 하지 않고 정의만 한다.
     - 다중 상속이 가능하다.
     - 생성자로 초기화가 불가능하다(인스턴스 생성이 불가능하다).
     - 선언된 모든 메서드의 구현을 강제한다.
     - 인터페이스의 기본적인 접근지정자는 public 이다.
     - 메서드를 구현할수있지만 인터페이스의 원형 자체가 결국엔 선언만 하고 구현은 상속을 받아 만들기 때문에 통상적으로 사용하지 않는다.
     - 추상 클래스도 인터페이스를 상속받을 수 있다.

     과제
    1.
     - 공격 , 방어 , 움직임 등등 인터페이스를 만들고
     - 특정 캐릭터(3개)가 상속을 받는다.
     ㄴ 각각의 캐릭터들이 행동을 수행하는 결과를 출력한다.
    
    2.추상클래스와 인터페이스의 차이
    
    3.업 vs 다운캐스팅

    4.클래스를 활용하여 대전게임을 만들어라.(프로퍼티 활용)
     */
    public abstract class AClass //추상클래스
    {
        int a;//멤버변수
        //생성자
        AClass() 
        {
            a = 10;
        }
        private int c;
    }
    public interface IClass //인터페이스
    {
        /*
        int a; 멤버변수를 가질 수 없다.
        IClass() 
        {

        }
        생성자도 포함할수 없다
        private int c; 
        */
        //public void Print();
        public void Test() 
        {
            Console.WriteLine("ddd");
        }
    }
    public interface IEnterable 
    {
        void Enter();
    }
    public interface IOpenable 
    {
        void Open();
    }
    public class Door: IEnterable , IOpenable
    {
        public void Enter() 
        {
            
        }
        public void Open() 
        {
            
        }
    }

    /*인터페이스를 이용하여 기능을 구현할 경우
    클래스와 상속관계와 무관하게 행동의 가능 여부로 상호작용이 가능하다.
     */
    public class Player 
    {
        public void Enter(IEnterable enterable) 
        {
            Console.WriteLine("플레이어가 들어가기를 시도한다");
            enterable.Enter();            
        }
    }
    class Test : IClass 
    {
    }
    internal class Interface
    {

        static void Main(string[] args)
        {
            Test t = new Test();
        }
    }
}
