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

    //각 매니저 클래스들을 프라이빗으로 선언만 하고
    private CharacterManager _characterManager;
    private SceneManager _sceneManager;
    private ItemManager _itemManager;

    //실제 매니저 클래스들의 인스턴스의 생성자를 분리하여 관리
    public CharacterManager CharacterManager 
    {
        get
        {
            if (_characterManager == null)
            {
                _characterManager = CharacterManager.Instance;
            }
            return _characterManager;
        }
    }
    public SceneManager SceneManager
    {
        get
        {
            if (_sceneManager == null)
            {
                _sceneManager = SceneManager.Instance;
            }
            return _sceneManager;
        }
    }
    public ItemManager ItemManager
    {
        get
        {
            if (_itemManager == null)
            {
                _itemManager = ItemManager.Instance;
            }
            return _itemManager;
        }
    }
    private GameManager() 
    {
        GameStart();
    }
    //각 매니저 클래스들이 필요할때 gamestart에서 생성되어 순환 참조를 방지한다.
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
                        ItemManager.Instance.itemGen(CharacterManager.Instance);
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




