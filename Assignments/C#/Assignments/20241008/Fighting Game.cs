/*
     과제
    1.
     - 공격 , 방어 , 움직임 등등 인터페이스를 만들고
     - 특정 캐릭터(3개)가 상속을 받는다.
     ㄴ 각각의 캐릭터들이 행동을 수행하는 결과를 출력한다.
    
    2.추상클래스와 인터페이스의 차이
    
    3.업 vs 다운캐스팅

    
*/

using System.Collections.Specialized;
using System.Threading;
using static System.Net.Mime.MediaTypeNames;
using System.Xml.Linq;

//4.클래스를 활용하여 대전게임을 만들어라.(프로퍼티 활용)

namespace _20241008
{
    internal class Program
    {


        public class Player
        {
            public string name = "Player";
            public Characters Character { get; set; }
        }

        public class CPU
        {
            public string name = "CPU";
            public Characters Character { get; set; }
        }
        
        public class Characters
        {
            public string name { get; set; }
            public int hp { get; set; }
            public int atk { get; set; }
            public int def { get; set; }

            public virtual void Attack(Characters Defender, bool isCPU)
            {
                int damage = atk - Defender.def / 2;
                if (damage > 0)
                {
                    Defender.hp -= damage;
                    if (isCPU)
                    {
                        Console.WriteLine($"CPU {name}의 공격!");
                        Console.WriteLine($"플레이어 {Defender.name}이/가 {damage} 만큼의 피해를 입음!");
                    }
                    else
                    {
                        Console.WriteLine($"플레이어 {name}의 공격!");
                        Console.WriteLine($"CPU {Defender.name}이/가 {damage} 만큼의 피해를 입음!");
                    }
                }
                else
                {
                    Console.WriteLine("아무일도 일어나지 않았다.");
                }
            }

            public bool Move()
            {
                Random random = new Random();
                Console.Write("회피를 시도 !!");
                if (random.Next(3) == 1)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }

            public void Guard(Characters Attacker, bool isCPU)
            {
                int damage = Attacker.atk - (def / 2);
                if (damage > 0)
                {
                    hp -= damage;
                    if (isCPU)
                    {
                        Console.WriteLine($"CPU {name}이/가 방어를 시도 !");
                        Console.WriteLine($"CPU {name}이/가 {damage} 만큼의 피해를 입음 !");
                    }
                    else
                    {
                        Console.WriteLine($"{name}이/가 방어를 시도 !");
                        Console.WriteLine($"{name}이/가 {damage} 만큼의 피해를 입음 !");
                    }

                }
                else
                {
                    Console.WriteLine($"{name}의 방어 성공 !!");
                }
            }

            public Characters(string name, int hp, int atk, int def)
            {
                this.name = name;
                this.hp = hp;
                this.atk = atk;
                this.def = def;
            }
        }

        public class Ganryu : Characters
        {
            public Ganryu() : base("간류", 100, 25, 30) { }

            public override void Attack(Characters defender, bool isCPU)
            {
                if (isCPU)
                {
                    Console.WriteLine($"CPU 간류의 옆치기!");
                }
                else
                {
                    Console.WriteLine($"플레이어 간류의 옆치기!");
                }
                int damage = (atk + 5) - defender.def / 2;
                if (damage > 0)
                {
                    defender.hp -= damage;
                    if (isCPU)
                        Console.WriteLine($"플레이어 {defender.name}이/가 {damage} 만큼의 피해를 입음!");
                    else
                        Console.WriteLine($"CPU {defender.name}이/가 {damage} 만큼의 피해를 입음!");
                }
                else
                {
                    Console.WriteLine("아무일도 일어나지 않았다.");
                }
            }
        }
        public class Jin : Characters
        {
            public Jin() : base("진 카자마", 110, 30, 25) { }

            public override void Attack(Characters defender, bool isCPU)
            {
                if (isCPU)
                    Console.WriteLine($"CPU 진 카자마의 나락!");
                else
                    Console.WriteLine($"플레이어 진 카자마의 나락!");

                int damage = (atk + 5) - defender.def / 2;
                if (damage > 0)
                {
                    defender.hp -= damage;
                    if (isCPU)
                        Console.WriteLine($"플레이어 {defender.name}이/가 {damage} 만큼의 피해를 입음!");
                    else
                        Console.WriteLine($"CPU {defender.name}이/가 {damage} 만큼의 피해를 입음!");
                }
                else
                {
                    Console.WriteLine("아무일도 일어나지 않았다.");
                }
            }
        }
        public class Steve : Characters
        {
            public Steve() : base("스티브", 95, 35, 20) { }

            public override void Attack(Characters defender, bool isCPU)
            {
                if (isCPU)
                {
                    Console.WriteLine($"CPU 스티브의 스크류 어퍼!");
                }
                else
                {
                    Console.WriteLine($"플레이어 스티브의 스크류 어퍼!");
                }
                int damage = (atk + 5) - defender.def / 2;
                if (damage > 0)
                {
                    defender.hp -= damage;
                    if (isCPU)
                    {
                        Console.WriteLine($"플레이어 {defender.name}이/가 {damage} 만큼의 피해를 입음!");
                    }
                    else
                    {
                        Console.WriteLine($"CPU {defender.name}이/가 {damage} 만큼의 피해를 입음!");
                    }
                }
                else
                {
                    Console.WriteLine("아무일도 일어나지 않았다.");
                }
            }
        }

        static void Main(string[] args)
        {
            Random rand = new Random();
            bool PlayerTrig = true;
            while (PlayerTrig)
            {
                Console.WriteLine("Welcome to TEKKEN");
                Console.Write("Type 1) Ganryu , 2) Jin , 3) Steve : ");
                int CharacterSelect = int.Parse(Console.ReadLine());

                Player player = new Player();
                CPU cpu = new CPU();


                switch (CharacterSelect)
                {
                    case 1:
                        player.Character = new Ganryu();
                        break;
                    case 2:
                        player.Character = new Jin();
                        break;
                    case 3:
                        player.Character = new Steve();
                        break;
                    default:
                        Console.WriteLine("잘못된 선택입니다. 다시 선택해주세요.");
                        continue;
                }


                int cpuSelect = rand.Next(1, 4);
                switch (cpuSelect)
                {
                    case 1:
                        cpu.Character = new Ganryu();
                        break;
                    case 2:
                        cpu.Character = new Jin();
                        break;
                    case 3:
                        cpu.Character = new Steve();
                        break;
                }
                Console.WriteLine("================================");
                Console.WriteLine($"플레이어가 선택한 캐릭터: {player.Character.name}");
                Console.WriteLine($"CPU가 선택한 캐릭터: {cpu.Character.name}");
                Console.WriteLine("================================");
                while (player.Character.hp > 0 && cpu.Character.hp > 0)
                {
                    Console.WriteLine($"플레이어 HP: {player.Character.hp}, CPU HP: {cpu.Character.hp}");

                    Console.WriteLine("1) 공격, 2) 방어, 3) 회피");
                    Console.Write("행동을 선택하세요: ");
                    int playerAction = int.Parse(Console.ReadLine());

                    int cpuAction = rand.Next(1, 4);


                    switch (playerAction)
                    {
                        case 1:
                            if(cpuAction == 2) 
                            {
                                cpu.Character.Guard(player.Character, true);
                            }
                            else if (cpuAction == 3)
                            {
                                Console.WriteLine($"CPU {cpu.Character.name}이 회피 시도하였다 !");
                                if (cpu.Character.Move())
                                {
                                    Console.WriteLine($"CPU {cpu.Character.name}이 회피 성공 !");
                                }
                                else
                                {
                                    Console.WriteLine($"CPU {cpu.Character.name}이 회피를 실패 !");
                                    player.Character.Attack(cpu.Character, false);
                                }
                            }
                            else 
                            {
                                player.Character.Attack(cpu.Character, false);
                            }                            
                            break;
                        case 2:
                            if (cpuAction == 1)
                            {
                                player.Character.Guard(cpu.Character, false);
                            }
                            else
                            {
                                Console.WriteLine($"CPU {cpu.Character.name}이/가 공격을 시도하지 않았습니다.");
                            }
                            break;
                        case 3:
                            if (cpuAction == 1)
                            {
                                if (player.Character.Move())
                                {
                                    Console.WriteLine($"플레이어 {player.Character.name}이/가 회피에 성공했습니다!");
                                }
                                else
                                {
                                    Console.WriteLine($"플레이어 {player.Character.name}의 회피 실패!");
                                    cpu.Character.Attack(player.Character, true);
                                }
                            }
                            else
                            {
                                Console.WriteLine("아무 일도 일어나지 않았습니다.");
                            }
                            break;
                        default:
                            Console.Clear();
                            Console.WriteLine("잘못된 선택입니다. 턴을 넘깁니다.");
                            break;
                    }


                    if (playerAction != 1 && cpuAction == 1)
                    {
                        cpu.Character.Attack(player.Character, true);  // true는 CPU의 공격을 의미
                    }
                }

                Console.Write("다시 플레이하시겠습니까? (Y/N): ");
                string playAgain = Console.ReadLine().ToUpper();
                PlayerTrig = (playAgain == "Y");
            }
        }
    }
}
