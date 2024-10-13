using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;
using static CharacterManager;

public class SceneManager
{
    public SceneManager() { }
    public void equipItemScene(CharacterManager characterManager)
    {
        Console.Clear();
        if (characterManager.currentPlayer == null)
        {
            Console.WriteLine("캐릭터가 선택되지 않았습니다.");
            return;
        }

        ShowItemScene(characterManager);

        Console.Write("착용하실 아이템의 이름을 입력해주세요 : ");
        string itemName = Console.ReadLine();

        Item selectedItem = characterManager.currentPlayer.character.Inventory.Values
            .FirstOrDefault(item => item.name.Equals(itemName, StringComparison.OrdinalIgnoreCase));

        if (selectedItem != null)
        {
            characterManager.currentPlayer.character.EquipItem(selectedItem);
            Console.WriteLine($"{itemName}을(를) 장착했습니다.");
        }
        else
        {
            Console.WriteLine($"{itemName}은(는) 인벤토리에 없습니다.");
        }
    }
    public void ShowItemScene(CharacterManager characterManager)
    {
        if (characterManager.currentPlayer == null)
        {
            Console.WriteLine("캐릭터가 선택되지 않았습니다.");
            return;
        }

        Console.WriteLine("보유한 아이템");
        foreach (var inven in characterManager.currentPlayer.character.Inventory)
        {
            Console.WriteLine($" {inven.Key} {inven.Value.name}");
        }
        Console.WriteLine("장착한 아이템");
        foreach (var equipped in characterManager.currentPlayer.character.equippedItems)
        {
            Console.WriteLine($"{equipped.Key} {equipped.Value.name}");
        }
    }
    public void UnEquipItemScene(CharacterManager characterManager)
    {
        Console.Clear();
        if (characterManager.currentPlayer == null)
        {
            Console.WriteLine("캐릭터가 선택되지 않았습니다.");
            return;
        }

        ShowItemScene(characterManager);

        Console.WriteLine("장착 해제하실 아이템의 이름을 입력해주세요");

        string temname = Console.ReadLine();
        Item selectedItem = characterManager.currentPlayer.character.equippedItems.Values
            .FirstOrDefault(item => item.name.Equals(temname, StringComparison.OrdinalIgnoreCase));

        if (selectedItem != null)
        {
            characterManager.currentPlayer.character.unEpuipItem(selectedItem);
        }
    }
    public void characterGenScene(CharacterManager characterManager)
    {
        Console.Clear();
        string name;
        while (true)
        {
            Console.Write("캐릭터의 이름을 입력해주세요: ");
            name = Console.ReadLine();

            if (characterManager.playerGen(name) != null)
            {
                break;
            }
            else
            {
                Console.WriteLine("이미 존재하는 이름입니다.");
            }
        }

        selectClassScene(characterManager, name);
    }
    public void selectClassScene(CharacterManager characterManager, string name) 
    {
        Console.Write("1)기사, 2)궁수, 3)마법사: ");
        int classSelect;

        while (!int.TryParse(Console.ReadLine(), out classSelect) || classSelect < 1 || classSelect > 3)
        {
            Console.WriteLine("잘못된 입력입니다. 1, 2, 3 중 하나를 선택해주세요.");
            Console.Write("1)기사, 2)궁수, 3)마법사: ");
        }

        if (characterManager.selectClass(classSelect, name))
        {
            Console.WriteLine($"{name} 캐릭터가 생성되어 플레이어 목록에 추가되었습니다.");
        }
        else
        {
            Console.WriteLine("캐릭터 생성에 실패했습니다.");
        }
    }
    public void showPlayerInfoScene(CharacterManager characterManager)
    {
        Console.Clear();
        if (characterManager.currentPlayer == null)
        {
            Console.WriteLine("캐릭터가 선택되지 않았습니다.");
            return;
        }

        Console.WriteLine($"이름 : {characterManager.currentPlayer.name}");
        Console.WriteLine($"공격력 : {characterManager.currentPlayer.character.ATK}");
        Console.WriteLine($"방어력 : {characterManager.currentPlayer.character.DEF}");
    }
    public void DeleteCharacterScene(CharacterManager characterManager)
    {
        Console.Clear();
        Console.Write("삭제할 캐릭터의 이름을 입력해주세요: ");
        string name = Console.ReadLine();

        if (characterManager.DeleteCharacter(name))
        {
            Console.WriteLine($"{name} 캐릭터가 삭제되었습니다.");
        }
        else
        {
            Console.WriteLine("존재하지 않는 캐릭터 이름입니다.");
        }
    }
    public void showCharactersScene(CharacterManager characterManager)
    {
        Console.Clear();
        Console.WriteLine("현재 캐릭터 목록 ");
        Console.WriteLine();
        for (int i = 0; i < characterManager.players.Count; i++)
        {
            Console.WriteLine($"\t{i + 1}) 이름 : {characterManager.players[i].name} 직업 : {characterManager.players[i].character.name}");
        }
    }
    public void SetPlayerScene(CharacterManager characterManager)
    {
        Console.Clear();
        showCharactersScene(characterManager);
        Console.WriteLine();
        Console.Write("선택할 캐릭터의 이름을 입력해주세요 : ");
        string name = Console.ReadLine();
        if (characterManager.SetPlayer(name))
        {
            Console.WriteLine($"{name} 을 선택");
        }
        else
        {
            Console.WriteLine("캐릭터가 존재하지 않습니다.");
        }
    }
}
