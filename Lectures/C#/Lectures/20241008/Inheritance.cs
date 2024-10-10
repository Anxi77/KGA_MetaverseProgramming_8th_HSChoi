using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20241008
{

    /*
     상속
    -is-a 관계 : 부모클래스가 자식클래스를 포함하는 상위개념일 경우 상속관계가 적합.
     */
    internal class Inheritance
    {
        class Monster
        {
            protected string name;
            protected int hp;
            public void Move() 
            {
                Console.WriteLine($"{name}이/가 움직입니다.");
            }
            public void TakeHit(int damage) 
            {
                hp -= damage;
                Console.WriteLine($"{name}이/가 {damage}를 받아 체력이 {hp}가 되었다.");
            }
        }
        class Dragon : Monster 
        {
            public Dragon() 
            {
                name = "드래곤";
                hp = 100;
            }
            public void Breath() 
            {
                Console.WriteLine($"{name}이/가 브레스를 뿜는다.");
            }

        }
        class Slime : Monster
        {
            public Slime()
            {
                name = "슬라임";
                hp = 10;
            }
            public void Split()
            {
                Console.WriteLine($"{name}이/가 분열합니다.");
            }

        }
        class Hero 
        {
            int damage = 3;
            public void Attack(Monster monster) 
            {
                monster.TakeHit(damage);
            }
        }
        static void Main(string[] args)
        {
            Dragon dragon = new Dragon();
            Slime slime = new Slime();

            //부모클래스 Monster를 상속한 자식클래스는 모두 부모클래스의 메서드를 가지고 있다.
            dragon.Move();
            slime.Move();

            //자식클래스는 부모클래스가 가지고 있는 메서드 + 자식만의 메서드를 추가 할 수 있다.
            dragon.Breath();
            slime.Split();

            Hero hero = new Hero();
            hero.Attack(slime);
            hero.Attack(dragon);

            /*업캐스팅 & 다운캐스팅

             - 주로 상속관계에서 부모클래스와 자식클래스간의 형 변환에 사용한다.

             업캐스팅 : 자식 클래스는 부모클래스 자료형으로 묵시적 형변환이 가능하다.
             자식 클래스 객체는 항상 부모클래스의 객체로 취급될 수 있기 때문에 별도의 캐스팅 연산자가 필요하지 않다.

             다운캐스팅 : 부모 클래스타입을 다시 자식 클래스타입으로 변환(명시적 캐스팅)
             자식클래스에서 추가된 멤버에 접근하기 위해 사용한다 . 단, 안전하지 않기 떄문에 캐스팅 전에 실제 타입을 확인해야 한다.

            [업캐스팅 특징]
            1.명시적 캐스팅 없이 자동으로 이루어진다.
            2.부모 클래스에서 정의된 멤버들만 접근 가능하다.
            3.자식 클래스에서 추가된 기능은 접근할수 없다.

            [다운캐스팅 특징]
            1. 명시적인 캐스팅 연산자가 필요하다.
            2. is 또는 as 연산자를 사용하여 캐스팅 전 type을 확인하는것이 안전하다.


            [사용 이유]
            - 업캐스팅 : 다형성을 활용하여 부모클래스타입을 사용해 자식 클래스의 객체를 처리할수 있게 해준다.
                        코드의 재사용성을 높이고 인터페이스나 추상 클래스에서 자식 클래스들을 통일된 방식으로 다루는데 유용하다.
            - 다운캐스팅 : 자식클래스에서만 제공하는 기능에 접근할 필요가 있을 때 사용한다.
             */

            //업캐스팅(Dragon(자식) 인스턴스를 Monster(부모) 인스턴스로 변환)
            Monster monster = new Dragon();
            hero.Attack(monster);

            //다운캐스팅
            Dragon dd = (Dragon)monster;

            //Slime ss = (Slime)monster; <-- monster의 타입이 dragon이기에 ERR

            /*is를 활용한 다운캐스팅
             is : 객체가 특정한 타입인지 확인하기 위해 사용한다.
             */
            if(monster is Dragon) 
            {
                Dragon isDragon = (Dragon)monster;//가능하면 변환
            }
            
            /*as를 활용한 다운캐스팅
             as: 캐스팅을 시도하고 실패한다면 null을 반환한다.
             */
            Dragon asDragon = monster as Dragon;
            if(asDragon != null) 
            {
                asDragon.Move();
            }
        }

    }
}
