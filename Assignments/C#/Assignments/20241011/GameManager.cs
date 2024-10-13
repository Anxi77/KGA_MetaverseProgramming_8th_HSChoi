using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static ItemManager;
using static SceneManager;
using static CharacterManager;

public class GameManager
{
    private static GameManager _instance;
    public static GameManager Instance
    {
        get
        {
            if (_instance == null)
            {
                _instance = new GameManager();
            }
            return _instance;
        }
    }

    public CharacterManager CharacterManager { get; private set; }
    public SceneManager SceneManager { get; private set; }
    public ItemManager ItemManager { get; private set; }


    private GameManager() 
    {
        CharacterManager = new CharacterManager();
        SceneManager = new SceneManager();
        ItemManager = new ItemManager();
        GameStart();
    }

    public void GameStart() 
    {
        
        while (true)
        {
            Console.Clear();
            if (CharacterManager.currentPlayer != null && CharacterManager.currentPlayer.character != null)
            {
                Console.WriteLine($"현재 캐릭터 이름 : {CharacterManager.currentPlayer.name}");
                Console.WriteLine($"현재 캐릭터 직업 : {CharacterManager.currentPlayer.character.name}");
                Console.WriteLine($"현재 캐릭터 공격력 : {CharacterManager.currentPlayer.character.ATK}");
                Console.WriteLine($"현재 캐릭터 방어력 : {CharacterManager.currentPlayer.character.DEF}");
            }
            Console.WriteLine("==============================================================");
            Console.WriteLine("1) 캐릭터 생성");
            Console.WriteLine("2) 캐릭터 선택");
            Console.WriteLine("3) 아이템 장착");
            Console.WriteLine("4) 현재 캐릭터");
            Console.WriteLine("5) 캐릭터 삭제");
            Console.WriteLine("6) 아이템 장착 해제");
            Console.WriteLine("7) 캐릭터 목록");
            Console.Write("원하는 메뉴의 번호를 입력하세요 : ");
            
            if (int.TryParse(Console.ReadLine(), out int menuTrig))
            {
                switch (menuTrig)
                {
                    case 1:
                        SceneManager.characterGenScene(CharacterManager);
                        break;
                    case 2:
                        SceneManager.SetPlayerScene(CharacterManager);
                        if (CharacterManager.currentPlayer.character != null)
                        {
                            ItemManager.itemGen(CharacterManager);
                        }
                        else 
                        {
                            Console.WriteLine("선택된 캐릭터가 없습니다.");
                        }
                        break;
                    case 3:
                        SceneManager.equipItemScene(CharacterManager);
                        break;
                    case 4:
                        SceneManager.showPlayerInfoScene(CharacterManager);
                        break;
                    case 5:
                        SceneManager.DeleteCharacterScene(CharacterManager);
                        break;
                    case 6:
                        SceneManager.UnEquipItemScene(CharacterManager);
                        break;
                    case 7:
                        SceneManager.showCharactersScene(CharacterManager);
                        break;
                    default:
                        Console.WriteLine("Invalid Number");
                        break;
                }
            }
            else
            {
                Console.WriteLine("Invalid input. Please enter a number.");
            }
        }
    }
}    




