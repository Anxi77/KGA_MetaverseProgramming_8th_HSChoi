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
        Console.Clear();
        while (true)
        {
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
                        ItemManager.itemGen(CharacterManager);
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




