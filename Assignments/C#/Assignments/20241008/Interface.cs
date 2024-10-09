using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20241008
{
    internal class Interface
    {
        public interface IActions 
        {
            public void Move();
            public void Attack();
            public void Defense();
        }



        public class Knight : IActions 
        {
            public void Move() 
            {
                Console.WriteLine("기사가 움직인다.");
            }

            public void Attack() 
            {
                Console.WriteLine("기사가 공격한다.");
            }

            public void Defense() 
            {
                Console.WriteLine("기사가 방어를 시도");
            }

            public Knight() 
            {
                Move();
                Attack();
                Defense();
            }
        }
        public class Archer : IActions
        {
            public void Move()
            {
                Console.WriteLine("궁수가 움직인다.");
            }

            public void Attack()
            {
                Console.WriteLine("궁수가 활을 발사.");
            }

            public void Defense()
            {
                Console.WriteLine("궁수가 회피를 시도");
            }

            public Archer()
            {
                Move();
                Attack();
                Defense();
            }
        }
        public class Mage : IActions
        {
            public void Move()
            {
                Console.WriteLine("기사가 움직인다.");
            }

            public void Attack()
            {
                Console.WriteLine("마법사의 스킬 아이스볼트.");
            }

            public void Defense()
            {
                Console.WriteLine("마법사의 매직 실드");
            }

            public Mage()
            {
                Move();
                Attack();
                Defense();
            }
        }

        static void Main(string[] args)
        {
            bool trig = true;
            while (trig)
            {
                Console.Write("1) 기사 , 2) 궁수 , 마법사 : ");
                int input = int.Parse(Console.ReadLine());

                switch (input)
                {
                    case 1:
                        Knight knight = new Knight();
                        trig = false;
                        break;
                    case 2:
                        Archer archer = new Archer();
                        trig = false;
                        break;
                    case 3:
                        Mage mage = new Mage();
                        trig = false;
                        break;
                    default:
                        Console.WriteLine("Invalid Input !!");
                        continue;
                }
            }
        }

    }
}
