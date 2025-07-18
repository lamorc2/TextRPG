#ifndef ITEM_H
#define ITEM_H



enum class ItemType {
    Drink,
    Weapon,
    Doobie,
    Armor,
    Special
};

class Item{
public:
    
    ItemType type;
    std::string name;
    std::string description;
    int damage = 0;
    int manaRestore = 0;
    int healthRestore = 0;
    int defense = 0;
    bool stackable; 

    Item(const ItemType& type_, const int& stat_value, const std::string& name_, const std::string& description_, bool stack);


    /*
    const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string CYAN = "\033[36m";
const std::string BOLD = "\033[1m";
*/

    void use(Player& player) const;
    
    
    
    
#endif