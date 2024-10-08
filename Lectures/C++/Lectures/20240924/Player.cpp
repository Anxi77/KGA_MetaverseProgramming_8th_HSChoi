#include "Player.h"

Player::Player():attack(0),defense(0){}

void Player::equipItem(Item& item)
{
    //장착을 해야되는데 이미 장착이 되어있는 경우라면? 함수종료
    if (isItemEquipped(item)) 
    {
        std::cout << "해당 아이템은 장착이 되어있다!" << std::endl;
        return;
    }
    //장착
    equippedItems.push_back(item);
    //장착한걸로 바꾸고
    item.setEquipped(true);
    //공격력
    attack += item.getAttack();
    //방어력
    defense += item.getDefense();
    //아이템 장착함 출력정도?
    std::cout << item.getName() << "(" << item.getType() << ") 아이템 장착!" << std::endl;
}
void Player::UnEquipItem(Item& item)
{
    //반복자로 벡터를 돌면서
    for (auto it = equippedItems.begin(); it != equippedItems.end(); ++it) 
    {
        //찾으려고 하는 아이템이 아이템의 이름과 동일하면(찾으면)
        if ((*it).getName() == item.getName()) 
        {
            //공격력 빼고
            attack -= (*it).getAttack();
            //방어력 빼고
            defense -= (*it).getDefense();
            //장착해제로 바꾸고
            (*it).setEquipped(false);
            //벡터에서 제거
            equippedItems.erase(it);

            std::cout << item.getName() << "(" << item.getType() << ") 아이템 탈착" << std::endl;
            return;
        }
    }//end of for(it)
    std::cout << item.getName() << "(" << item.getType() << ") 아이템이 장착되어 있지 않음" << std::endl;
}

void Player::displayEquippedItems() const
{
    //비어 있으면
    if (equippedItems.empty()) {
        std::cout << "장착된 아이템 없음!" << std::endl;
        return;
    }
    std::cout << "장착된 아이템 목록 : " << std::endl;

    //돌면서 출력
    for (const auto& item : equippedItems)
    {
        std::cout << item.getName() << "(" << item.getType() << ") = 공격력 : " 
            << item.getAttack() << " , 방어력 : " << item.getDefense();

        //장착되어 있으면
        if (item.isEquipped()) 
        {
            std::cout << " <장착중>";
        }
        std::cout << std::endl;
    }
}
//사용가능한 아이템을 출력
void Player::displayAvailableItems(const std::vector<Item>& availableItems) const
{
    if (availableItems.empty()) {
        std::cout << "사용가능한 아이템 없음!" << std::endl;
        return;
    }
    std::cout << "사용가능한 아이템 목록" << std::endl;

    for (size_t i = 0; i < availableItems.size(); ++i)
    {
        const Item& item = availableItems[i];

        std::cout << i + 1 << ". " << item.getName() << "(" << item.getType() << ") = 공격력 : " 
            << item.getAttack() << " , 방어력 : " << item.getDefense();

        //장착중 이면
        if (isItemEquipped(item)) 
        {
            std::cout << "<장착중>";
        }
        std::cout << std::endl;
    }
}

bool Player::isItemEquipped(const Item& item) const
{
    for (const auto& equippeditem : equippedItems)
    {
        if (equippeditem.getName() == item.getName()) 
        {
            return true;
        }
    }
    return false;
}
