using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
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
    public Character(string name, int atk, int def)
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
    public Knight() : base("기사", 25, 50) { }
}
public class Archer : Character
{
    public Archer() : base("궁수", 50, 10) { }
}
public class Mage : Character
{
    public Mage() : base("마법사", 70, 5) { }
}


