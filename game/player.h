#ifndef PLAYER_H
#define PLAYER_H



/*
enum class PlayerType {
    Rylan,
    Cayden,
    Caden, 
    Connor,
    Tim,
    Dylan
};
*/

class Player {
public:

    Player(const std::string& character);
    Player(json& j);//TODO : Implement contructor from json, for load function
    std::vector<InventoryEntry> inventory;


    //FIXME Should this be initialized as nullptr?
    Item* equippedWeapon = nullptr;
    Item* equippedArmor = nullptr;
    std::string locationID;
    std::string name;
    int health;
    int max_health;
    int mana;
    int max_mana;
    int lvl;
    int strength; //base attack + weapon?? multiplier?
    int armor_stat; //starting is 0, everytime armor is equipped, replace this value INSTEAD of accessing the armor data value for every damage
    int damage_stat;//^^
    // Class System? Specific boosts?

    void level_up();
    void restoreHealth(const int amnt);
    void takeDamage(const int amnt);    
    void equipArmor(InventoryEntry* armor);
    void equipWeapon(InventoryEntry* weapon);

    void to_json(json& j, const Player& p);
    
};

#endif