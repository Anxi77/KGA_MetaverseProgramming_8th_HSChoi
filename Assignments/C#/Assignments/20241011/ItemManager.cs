﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static CharacterManager;

public class ItemManager
{
    public ItemManager() 
    {
    }

    public void itemGen(CharacterManager characterManager)
    {
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
