using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static CharacterManager;

public class ItemManager
{
    private static ItemManager _instance;
    public static ItemManager Instance
    {
        get
        {
            if (_instance == null)
            {
                _instance = new ItemManager();
            }
            return _instance;
        }
    }   
    private ItemManager() 
    {
        // itemGen() 메서드를 여기서 직접 호출하지 않음
    }
    public void itemGen(CharacterManager characterManager)
    {
        List<Item> items = new List<Item>();
        Item Knife = new Knife();
        Item Helm = new Helm();
        Item RedPotion = new RedPotion();
        Item BronzeArmor = new BronzeArmor();
        characterManager.currentPlayer.character.Inventory.Add(Knife.Type, Knife);
        characterManager.currentPlayer.character.Inventory.Add(Helm.Type, Helm);
        characterManager.currentPlayer.character.Inventory.Add(RedPotion.Type, RedPotion);
        characterManager.currentPlayer.character.Inventory.Add(BronzeArmor.Type, BronzeArmor);
    }
}
