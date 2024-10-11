using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace Csharp04
{
    public enum ItemType 
    {
        Weapon,Armor,Potion,Helmet
    }
    public abstract class Item
    {
        protected int iAtk;
        protected int iDef;

        public string name { get; set; }
        public ItemType Type { get; set; }
        public virtual void itemEffects(Character character) 
        {
            character.ATK += this.iAtk;
            character.DEF += this.iDef;
        }
        public virtual void unEquipEffect(Character character) 
        {
            character.DEF -= this.iDef;
            character.ATK -= this.iAtk;
        }

        public Item(string name, ItemType Type, int iAtk, int iDef) { this.name = name; this.Type = Type; this.iAtk = iAtk; this.iDef = iDef; }
    }
    public class Knife : Item 
    {
        public Knife() : base("칼", ItemType.Weapon, 50, 0) { }
    }
    public class Helm : Item 
    {
        public Helm() : base("헬름", ItemType.Helmet, 0, 25) { }
    }
    public class BronzeArmor : Item 
    {
        public BronzeArmor() : base("청동 갑옷", ItemType.Armor, 0, 50) { }
    }
    public class RedPotion : Item 
    {
        public RedPotion() : base("빨간포션", ItemType.Potion, 0, 0) { }

        public override void itemEffects(Character character)
        {
            int iHp = 50;
            Console.WriteLine($"플레이어 {character.name} 이/가 빨간 포션을 복용");
            character.HP += iHp;
        }
    }
    public class Character
    {
        public Dictionary<ItemType, Item> equippedItems = new Dictionary<ItemType, Item>();
        public Dictionary<ItemType, Item> Inventory = new Dictionary<ItemType, Item>();
        public string name;

        /*람다를 이용한 프로퍼티 원형은 get { return atk; } set { atk = value; }
        public int ATK { get => atk > 10 ? 20 : atk; set => atk = value; }
                        이 람다의 뜻은
                        atk가 10보다 크다면 atk가 20이 되는거고 , false라면 atk 원본을 리턴한다는 뜻이다.
         */
        public int ATK { get; set; }
        public int DEF { get; set; }
        public int HP { get; set; }
        public Character(string name , int atk, int def) 
        {
            this.name = name;
            this.ATK = atk;
            this.DEF = def;
        }
        public void EquipItem(Item item) 
        {
            //동일 타입의 아이템이 이미 장착되어 있고 인벤토리에 아이템이 있다면
            if (equippedItems.ContainsKey(item.Type) && Inventory.ContainsValue(item)) 
            {
                equippedItems.Remove(item.Type);
                equippedItems.Add(item.Type, item);
                Inventory.Remove(item.Type);
                item.itemEffects(this);                
            }
            else 
            {
                equippedItems.Add(item.Type, item);
                Inventory.Remove(item.Type);
                item.itemEffects(this);
            }
        }
        public void unEpuipItem(Item item) 
        {
            if (equippedItems.ContainsValue(item)) 
            {
                equippedItems.Remove(item.Type);
                Inventory.Add(item.Type, item);
            }
            else 
            {
                Console.WriteLine($"{item.Type} 부위에 장착한 아이템이 없습니다");
            }
        }

    }
    public class Knight : Character 
    {
        public Knight() : base("기사",25,50) { }
    }
    public class Archer : Character 
    {
        public Archer() : base("궁수", 50, 10) { }
    }
    public class Mage : Character 
    {
        public Mage() : base("마법사", 70, 5) { }
    }
    public class Player
    {
        public string name { get; set; }
        public Character character { get; set; }
        //public Character character { get => character; set => character = value; }
    }


    /* 컬렉션이란
     * 같은 성격을 띄는 데이터의 모음을 저장하고 관리하는 자료구조
     * 저장, 검색, 수정 삭제를 효율적으로 하기위해 데이터를 그룹화 한다.
     * 
     * 제네릭 타입
     * List, Dictionary, Queue, Stack
     * 
     */

    internal class Collection
    {
        public static void characterGen(List<Player> players)
        {

            Player player = new Player();

            while (true)
            {
                Console.Write("캐릭터의 이름을 입력해주세요: ");
                string name = Console.ReadLine();

                Player existing = players.Find(c => c.name == name);

                if (existing == null) 
                {
                    player.name = name;
                    break;
                }
                else 
                {
                    Console.WriteLine("이미 존재하는 이름입니다 .");
                }
                
            }


            Console.Write("1)기사, 2)궁수, 3)마법사: ");
            int classSelect;
            //ToDo tryparse 왜씀?(메모리상의 이득? , 아님 그냥 줄줄이기)

            while (!int.TryParse(Console.ReadLine(), out classSelect) || classSelect < 1 || classSelect > 3)
            {
                Console.WriteLine("잘못된 입력입니다. 1, 2, 3 중 하나를 선택해주세요.");
                Console.Write("1)기사, 2)궁수, 3)마법사: ");
            }


            switch (classSelect)
            {
                case 1:
                    player.character = new Knight();
                    break;
                case 2:
                    player.character = new Archer();
                    break;
                case 3:
                    player.character = new Mage();
                    break;
            }

            players.Add(player);
            Console.WriteLine($"{player.name} 캐릭터가 생성되어 플레이어 목록에 추가되었습니다.");
        }

        public static void SetPlayer(List<Player> player,ref Player currentPlayer) 
        {
            Console.WriteLine("현재 캐릭터 목록 ");
            Console.WriteLine();
            for(int i = 0; i < player.Count; i++) 
            {
                Console.WriteLine($"\t{i+ 1}) 이름 : {player[i].name} 직업 : {player[i].character.name}");
            }
            Console.WriteLine();
            Console.Write("선택할 캐릭터의 이름을 입력해주세요");
            string name = Console.ReadLine();
            
            foreach (var plen in player) 
            {
                if (plen.name == name)
                {
                    Console.WriteLine($"{name} 을 선택");
                    currentPlayer = plen;
                }
                else 
                {
                    Console.WriteLine("캐릭터가 존재하지 않습니다 .");
                }
            }
        }

        public static void selectItem(ref Player currentPlayer) 
        {
            ShowItem(ref currentPlayer);

            Console.Write("착용하실 아이템의 이름을 입력해주세요 : ");
            string itemName = Console.ReadLine();

            Item selectedItem = null;

            foreach (var item in currentPlayer.character.Inventory.Values)
            {
                if (item.name.Equals(itemName, StringComparison.OrdinalIgnoreCase))
                {
                    selectedItem = item;
                    break;
                }
            }

            //Item selectedItem = currentPlayer.character.Inventory.Values.FirstOrDefault(item => item.name.Equals(itemName, StringComparison.OrdinalIgnoreCase));

            if (selectedItem != null)
            {
                currentPlayer.character.EquipItem(selectedItem);
                Console.WriteLine($"{itemName}을(를) 장착했습니다.");
            }
            else
            {
                Console.WriteLine($"{itemName}은(는) 인벤토리에 없습니다.");
            }
        }
        public static void ShowItem(ref Player currentPlayer) 
        {
            Console.WriteLine("보유한 아이템");
            foreach (var inven in currentPlayer.character.Inventory)
            {
                //inven.Value로 출력하게 되면 inven의 밸류가 item 객체 자체가되기 때문에 앞에 네임스페이스.클래스 이름으로 출력되게 된다.
                Console.WriteLine($" {inven.Key} {inven.Value.name}");
            }
            Console.WriteLine("장착한 아이템");
            foreach (var equipped in currentPlayer.character.equippedItems)
            {
                Console.WriteLine($"{equipped.Key} {equipped.Value.name}");
            }
        }
        public static void UnEquipItem(ref Player currentPlayer) 
        {
            ShowItem(ref currentPlayer);
            Console.WriteLine("장착 해제하실 아이템의 이름을 입력해주세요");
            string temname = Console.ReadLine();
            Item selectedItem = null;
            foreach (var item in currentPlayer.character.equippedItems.Values)
            {
                if (item.name.Equals(temname, StringComparison.OrdinalIgnoreCase))
                {
                    selectedItem = item;
                    break;
                }
            }
            if(selectedItem != null) 
            {
                currentPlayer.character.unEpuipItem(selectedItem);
            }
        }
        public static void itemGen (ref Player currentPlayer) 
        {
            List<Item> items = new List<Item>();
            Item Knife = new Knife();
            Item Helm = new Helm();
            Item RedPotion = new RedPotion();
            Item BronzeArmor = new BronzeArmor();
            currentPlayer.character.Inventory.Add(Knife.Type, Knife);
            currentPlayer.character.Inventory.Add(Helm.Type, Helm);
            currentPlayer.character.Inventory.Add(RedPotion.Type, RedPotion);
            currentPlayer.character.Inventory.Add(BronzeArmor.Type, BronzeArmor);
        }
        public static void showPlayerInfo(ref Player currentPlayer) 
        {
            if (currentPlayer == null) return;
            else 
            {
                Console.WriteLine($"이름 : {currentPlayer.name}");
                Console.WriteLine($"공격력 : {currentPlayer.character.ATK}");
                Console.WriteLine($"방어력 : {currentPlayer.character.DEF}");
            }
        }
        public static void DeleteCharacter(List<Player> players) 
        {
            Console.Write("삭제하실 캐릭터의 이름을 입력해주세요 : ");
            string name = Console.ReadLine();
            foreach(Player player in players) 
            {
                if(player.name == name) 
                {
                    players.Remove(player);
                }
                else 
                {
                    Console.WriteLine("존재하지 않는 캐릭터 이름입니다.");
                }
            }
        }
        static void Main(string[] args)
        {
            Console.Clear();
            List<Player> player = new List<Player>();
            Player currentPlayer = new Player();

            while (true) 
            {
                Console.WriteLine("1) 캐릭터 생성");
                Console.WriteLine("2) 캐릭터 선택");
                Console.WriteLine("3) 아이템 장착");
                Console.WriteLine("4) 현재 캐릭터");
                Console.WriteLine("5) 캐릭터 삭제");
                Console.WriteLine("6) 아이템 장착 해제");
                Console.Write("원하는 메뉴의 번호를 입력하세요 : ");
                int menuTrig = int.Parse(Console.ReadLine());
                switch (menuTrig) 
                {
                    case 1:
                        characterGen(player);
                        break;
                    case 2:
                        //클래스 자체는 참조 타입이나 , 클래스를 인스턴스화 하게 되어 매개변수로 사용하게 된다면 값 타입으로 넘어가게 된다.
                        SetPlayer(player, ref currentPlayer);
                        itemGen(ref currentPlayer);
                        break;
                    case 3:
                        selectItem(ref currentPlayer);
                        break;
                    case 4:
                        showPlayerInfo(ref currentPlayer);
                        break;
                    case 5:
                        DeleteCharacter(player);
                        break;
                    case 6:
                        UnEquipItem(ref currentPlayer);
                        break;
                    default:
                        Console.WriteLine("Invalid Number");
                        continue;
                }
            }
        }
    }
}
