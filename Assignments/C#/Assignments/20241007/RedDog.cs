using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Metadata.Ecma335;
using System.Text;
using System.Threading.Tasks;

/*월남뽕 C# 으로 구현 과제*/

namespace _20241007
{
    class Game
    {
        public void Separator()
        {
            for (int i = 97; i > 0; i--)
            {
                Console.Write("*");
            }
            Console.WriteLine();
        }

        public int Lobby()
        {
            int gameStart = 0;
            bool bgameStart = true;
            while (bgameStart)
            {
                Console.WriteLine("=================================Welcome to Red Dog================================");
                Console.WriteLine();
                Console.WriteLine("1) Start Game");
                Console.WriteLine("2) Quit");
                Console.WriteLine();
                Console.WriteLine("Please Type 1 or 2 : ");
                string input = Console.ReadLine();
                int.TryParse(input, out gameStart);
                if (gameStart == 1)
                {
                    Console.WriteLine();
                    Console.WriteLine("=============================================Game Start==========================================");
                    Console.WriteLine();
                    bgameStart = false;
                }
                else if(gameStart == 2) 
                {
                    Console.WriteLine("=============================================GG==========================================");
                    bgameStart=false;
                }
                else
                {
                    Console.WriteLine();
                    Console.WriteLine("***Please Enter Valid Number***");
                    Console.WriteLine();
                }
            }
            return gameStart;
        }

        public void game()
        {
            Random random = new Random();
            int pMoney = 10000;
            int count = 0;
            int[] pickedcards = new int[3];
            int playercard = 0;
            int playerpick = 0;
            int nonPickedCard = 0;
            int[,] cards = new int[4,13];
            int[,] dumpcards =new int [4,13];
            int picksuits, picknums = 0;
            bool gametrig = true;

            //카드 생성
            for (int num = 0; num < 13; num++)
            {
                cards[0,num] = num + 1;
                cards[1,num] = num + 1;
                cards[2,num] = num + 1;
                cards[3,num] = num + 1;
            }


            while (gametrig)
            {

                int bMoney = 0;
                Console.WriteLine($"Your Current Money is : {pMoney} Gold");                
                Separator();
                Console.WriteLine("Place your Bet Please : ");    
                string input = Console.ReadLine();
                int.TryParse( input, out bMoney );
                int min = 0;
                int max = 0;
                int[] cardComp = new int[3];
                int playercontinue = 0;


                if (bMoney > 0 && bMoney <= pMoney)
                {
                    Console.WriteLine();
                    Console.WriteLine($"You Have Placed : {bMoney} Gold to Bet");
                    Console.WriteLine();
                    Console.WriteLine("Pick One of Between Two Cards");
                    Separator();
                    Console.WriteLine();

                    //첫번째 두카드 뽑기

                    for (int i = 0; i < 2; i++)
                    {
                        picksuits = random.Next(4);
                        picknums = random.Next(13);

                        while (true)
                        {
                            picksuits = random.Next(4);
                            picknums = random.Next(13);
                            if (cards[picksuits,picknums] != -1)
                            {
                                pickedcards[i] = cards[picksuits,picknums];
                                if (i == 0)
                                {
                                    Console.Write("1) ");
                                }
                                if (i == 1)
                                {
                                    Console.Write("2) ");
                                }

                                if (picksuits == 0)
                                {
                                    if (cards[picksuits,picknums] > 1 && cards[picksuits, picknums] < 11)
                                    {
                                        Console.WriteLine($"{cards[0,picknums]} of Spade");
                                    }
                                    if (cards[picksuits, picknums] == 1)
                                    {
                                        Console.WriteLine("Ace of Spade");
                                    }
                                    if (cards[picksuits, picknums] == 11)
                                    {
                                        Console.Write("Jack of Spade");
                                    }
                                    if (cards[picksuits, picknums] == 12)
                                    {
                                        Console.Write("Queen of Spade");
                                    }
                                    if (cards[picksuits, picknums] == 13)
                                    {
                                        Console.Write("King of Spade");
                                    }
                                }
                                if (picksuits == 1)
                                {
                                    if (cards[picksuits, picknums] > 1 && cards[picksuits, picknums] < 11)
                                    {
                                        Console.WriteLine($"{cards[0, picknums]} of Diamond");
                                    }
                                    if (cards[picksuits, picknums] == 1)
                                    {
                                        Console.WriteLine("Ace of Diamond");
                                    }
                                    if (cards[picksuits, picknums] == 11)
                                    {
                                        Console.WriteLine("Jack of Diamond");
                                    }
                                    if (cards[picksuits, picknums] == 12)
                                    {
                                        Console.WriteLine("Queen of Diamond");
                                    }
                                    if (cards[picksuits, picknums] == 13)
                                    {
                                        Console.WriteLine("King of Diamond");
                                    }

                                }
                                if (picksuits == 2)
                                {
                                    if (cards[picksuits, picknums] > 1 && cards[picksuits, picknums] < 11)
                                    {
                                        Console.WriteLine($"{cards[0, picknums]} of Heart");
                                    }
                                    if (cards[picksuits, picknums] == 1)
                                    {
                                        Console.WriteLine("Ace of Heart");
                                    }
                                    if (cards[picksuits, picknums] == 11)
                                    {
                                        Console.WriteLine("Jack of Heart");
                                    }
                                    if (cards[picksuits, picknums] == 12)
                                    {
                                        Console.WriteLine("Queen of Heart");
                                    }
                                    if (cards[picksuits, picknums] == 13)
                                    {
                                        Console.WriteLine("King of Heart");
                                    }

                                }
                                if (picksuits == 3)
                                {
                                    if (cards[picksuits, picknums] > 1 && cards[picksuits, picknums] < 11)
                                    {
                                        Console.WriteLine($"{cards[0, picknums]} of Clover");
                                    }
                                    if (cards[picksuits, picknums] == 1)
                                    {
                                        Console.WriteLine("Ace of Clover");
                                    }
                                    if (cards[picksuits, picknums] == 11)
                                    {
                                        Console.WriteLine("Jack of Clover");
                                    }
                                    if (cards[picksuits, picknums] == 12)
                                    {
                                        Console.WriteLine("Queen of Clover");
                                    }
                                    if (cards[picksuits, picknums] == 13)
                                    {
                                        Console.WriteLine("King of Clover");
                                    }

                                }
                                cards[picksuits, picknums] = -1;
                                break;
                            }

                        }
                    }
                    Console.WriteLine();
                    Console.Write("Type 1 or 2 to Pick Card : ");
                    string playerCardinput = Console.ReadLine();
                    int.TryParse(playerCardinput, out playercard);


                    if (playercard == 1)
                    {
                        playercard = pickedcards[0];
                        nonPickedCard = pickedcards[1];

                    }
                    if (playercard == 2)
                    {
                        playercard = pickedcards[1];
                        nonPickedCard = pickedcards[0];
                    }

                    //마지막 카드 뽑기


                    while (true)
                    {
                        picksuits = random.Next(4);
                        picknums = random.Next(13);
                        if (cards[picksuits, picknums] != -1)
                        {
                            pickedcards[2] = cards[picksuits, picknums];
                            Console.WriteLine("Last Card is : ");

                            if (picksuits == 0)
                            {
                                if (cards[picksuits, picknums] > 1 && cards[picksuits, picknums] < 11)
                                {
                                    Console.WriteLine($"{cards[0, picknums]} of Spade");
                                }
                                if (cards[picksuits, picknums] == 1)
                                {
                                    Console.WriteLine("Ace of Spade");
                                    }
                                if (cards[picksuits, picknums] == 11)
                                {
                                    Console.Write("Jack of Spade");
                                }
                                if (cards[picksuits, picknums] == 12)
                                {
                                    Console.Write("Queen of Spade");
                                }
                                if (cards[picksuits, picknums] == 13)
                                {
                                    Console.Write("King of Spade");
                                }
                            }
                            if (picksuits == 1)
                            {
                                if (cards[picksuits, picknums] > 1 && cards[picksuits, picknums] < 11)
                                {
                                    Console.WriteLine($"{cards[0, picknums]} of Diamond");
                                }
                                if (cards[picksuits, picknums] == 1)
                                {
                                    Console.WriteLine("Ace of Diamond");
                                }
                                if (cards[picksuits, picknums] == 11)
                                {
                                    Console.WriteLine("Jack of Diamond");
                                }
                                if (cards[picksuits, picknums] == 12)
                                {
                                    Console.WriteLine("Queen of Diamond");
                                }
                                if (cards[picksuits, picknums] == 13)
                                {
                                    Console.WriteLine("King of Diamond");
                                }

                            }
                            if (picksuits == 2)
                            {
                                if (cards[picksuits, picknums] > 1 && cards[picksuits, picknums] < 11)
                                {
                                    Console.WriteLine($"{cards[0, picknums]} of Heart");
                                }
                                if (cards[picksuits, picknums] == 1)
                                {
                                    Console.WriteLine("Ace of Heart");
                                }
                                if (cards[picksuits, picknums] == 11)
                                {
                                    Console.WriteLine("Jack of Heart");
                                }
                                if (cards[picksuits, picknums] == 12)
                                {
                                    Console.WriteLine("Queen of Heart");
                                }
                                if (cards[picksuits, picknums] == 13)
                                {
                                    Console.WriteLine("King of Heart");
                                }

                            }
                            if (picksuits == 3)
                            {
                                if (cards[picksuits, picknums] > 1 && cards[picksuits, picknums] < 11)
                                {
                                    Console.WriteLine($"{cards[0, picknums]} of Clover");
                                }
                                if (cards[picksuits, picknums] == 1)
                                {
                                    Console.WriteLine("Ace of Clover");
                                }
                                if (cards[picksuits, picknums] == 11)
                                {
                                    Console.WriteLine("Jack of Clover");
                                }
                                if (cards[picksuits, picknums] == 12)
                                {
                                    Console.WriteLine("Queen of Clover");
                                }
                                if (cards[picksuits, picknums] == 13)
                                {
                                    Console.WriteLine("King of Clover");
                                }

                            }
                            cards[picksuits, picknums] = -1;
                            break;
                        }

                    }


                    Array.Sort(pickedcards);

                    min = pickedcards.Min();
                    max = pickedcards.Max();


                    if (playercard > min && playercard < max)
                    {
                        pMoney += bMoney * 2;
                        Console.WriteLine();
                        Separator();
                        Console.WriteLine("You Won !!!");
                        Separator();
                    }
                    else
                    {
                        pMoney -= bMoney * 2;
                        Console.WriteLine();
                        Separator();
                        Console.WriteLine("You Lost");
                        Separator();
                    }



                    count += 3;

                }
                else
                {
                    Console.WriteLine();
                    Console.WriteLine("Please Bet Right Amount !!!!");
                    Console.WriteLine();
                }
                Console.WriteLine();
                Separator();
                Console.WriteLine("Type 1) to Continue or 2) to Quit : ");
                while (playercontinue != 1 || playercontinue != 2)
                {
                    string contin = Console.ReadLine();
                    int.TryParse(contin, out playercontinue);
                }

                if (pMoney <= 0)
                {
                    gametrig = false;
                }
                if (count > 17)
                {
                    gametrig = false;
                }


            }

        }

    }
    internal class RedDog
    {
        static void Main(string[] args)
        {
            Game g = new Game();
            if(g.Lobby() == 1) 
            {
                g.game();
            }
        }
        
    }
}
