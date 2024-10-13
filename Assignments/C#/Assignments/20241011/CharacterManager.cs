using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static Character;
using static CharacterManager;


public class CharacterManager
{
    public List<Player> players { get; private set; }
    public Player currentPlayer { get; set; }

    public CharacterManager()
    {
        players = new List<Player>();
        currentPlayer = new Player();
    }

    public bool SetPlayer(string name)
    {
        var player = players.FirstOrDefault(p => p.name == name);
        if (player != null)
        {
            currentPlayer = player;
            return true;
        }
        return false;
    }
    public bool DeleteCharacter(string name)
    {
        var player = players.FirstOrDefault(p => p.name == name);
        if (player != null)
        {
            players.Remove(player);
            if (currentPlayer == player)
            {
                currentPlayer = null;
            }
            return true;
        }
        return false;
    }
    public Player playerGen(string name)
    {
        if (players.All(p => p.name != name))
        {
            Player player = new Player { name = name };
            players.Add(player);
            return player;
        }
        return null;
    }
    public bool selectClass(int classSelect, string playerName)
    {
        Player player = players.Find(p => p.name == playerName);
        if (player == null)
        {
            return false;
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
            default:
                return false;
        }

        return true;
    }

    public class Player
    {
        public string name { get; set; }
        public Character character { get; set; }
    }
}
