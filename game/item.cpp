#include "item.h"


	Item::Item(const ItemType& type_, const int& stat_value, const std::string& name_, const std::string& description_, bool stack){
        type = type_;
        name = name_;
        stackable = stack;
        description = description_;
        switch(type_){

        case ItemType::Drink:
            healthRestore = stat_value;
            break;

        case ItemType::Doobie:
            manaRestore = stat_value;
            break;

        case ItemType::Weapon:
            damage = stat_value;
            break;

        case ItemType::Armor;
            defense = stat_value;
            break;

        }
    };

    void Item::use(Player& player) const{
        switch(type){

            case ItemType::Drink:
                //Drink code
                player->restoreHealth(stat_value);
                break;
            case ItemType::Weapon:
                //Weapon
                player.equipArmor(this);
                break;
            case ItemType::Doobie:
                //Doobie
                break;
            case ItemType::Armor:
                //Armor
                std::cout << "You equip the \033[33m" << name << "\033[0m!" << std::endl;
                break;
            default:
                std::cerr << "Error 001 : Item Type not Recognized" << std::endl;
                break;

        }

};