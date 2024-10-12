using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public enum ItemType
{
    Weapon, Armor, Potion, Helmet
}
public abstract class Item
{
    protected int iAtk;
    protected int iDef;

    public string name { get; set; }
    public ItemType Type { get; set; }
    public Item(string name, ItemType Type, int iAtk, int iDef) { this.name = name; this.Type = Type; this.iAtk = iAtk; this.iDef = iDef; }
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


