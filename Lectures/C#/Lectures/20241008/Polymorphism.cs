using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20241008
{
    /*가상함수
     ㄴ부모 클래스의 함수중 자식클래스에 의해서 재정의 할수 있는 함수를 지정

    오버라이딩 : 부모클래스의 가상함수를 같은 함수이름과 같은 매개변수로 재정의하여 자식만의 반환값을 가지는 함수를 지정.
     */
    internal class Polymorphism
    {
        class Skill 
        {
            public virtual void Execute() 
            {
                Console.WriteLine("스킬 재사용 대기시간을 진행한다");
            }
        }
        class FireBall : Skill 
        {
            public override void Execute()//오버라이딩
            {
                base.Execute();
                Console.WriteLine("화염구 발사");
            }
        }
        class Dash : Skill 
        {
            public override void Execute()
            {
                base.Execute();
                Console.WriteLine("돌진 공격");
            }    
        }
        
        class Player 
        {
            Skill skill;
            public void SetSkill(Skill skill) 
            {
                this.skill = skill;
            }
            public void UseSkill() 
            {
                skill.Execute();
            }
        }
        static void Main(string[] args)
        {
            Player player = new Player();
            Skill fire = new FireBall();
            player.SetSkill(fire);
            player.UseSkill();
        }
    }
}
