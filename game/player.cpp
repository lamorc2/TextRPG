#include "player.h"


Player::Player(const std::string& character ){// Dear Velan Studios : Please hire me 
    name = character;
    armor_stat = 0;
	if(character == "Connor"){ // Base Class
        max_health = 100;
        health = max_health;
        max_mana = 50;
        mana = max_mana;
        lvl = 0;
        money = 0
        strength = 3;

    }else if(character == "Cayden"){//Cayden, extra health,  extra attack, no starting mana //
    	max_health = 150;
        health = max_health;
        max_mana = 0;
        mana = max_mana;
        lvl = 0;
        money = 0
        strength = 7;

    }else if(character == "Rylan"){//Rylan, starts with extra money?? when will money be involved? will it? thats all i got for him
    	max_health = 100;
        health = max_health;
        max_mana = 50;
        mana = max_mana;
        lvl = 0;
        money = 0
        strength = 3;

    }else if(character == "Dylan"){//Dylan lower mana, higher health 
    	max_health = 125;
        health = max_health;
        max_mana = 25;
        mana = max_mana;
        lvl = 0;
        money = 0
        strength = 3;

    }else if(character == "Caden"){//Caden,  
    	max_health = 100;
        health = max_health;
        max_mana = 50;
        mana = max_mana;
        lvl = 0;
        money = 0
        strength = 3;

    }else if(character == "Tim"){//Tim, Didn't drink, starts at level 3 b/c no hangover (still have to decide base. so 145 HP and maybe only like 30 Mana)
    	max_health = 145;
        health = max_health;
        max_mana = 30;
        mana = max_mana;
        lvl = 3;
        money = 0
        strength = 6;
    }else if(character == "Logan"){//Velie
        max_health = 100;
        health = max_health;
        max_mana = 30;
        mana = max_mana;
        lvl = 3;
        money = 0
        strength = 6;
    }
}

/*
const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string CYAN = "\033[36m";
const std::string BOLD = "\033[1m";


*/
Player::level_up(){
	max_health += 15;
	max_mana += 10;
	strength += 2;
	mana = max_mana;
	health = max_health;
	lvl++;
	std::cout << "You've leveled up, you are now level " << lvl << ".\n Maximum Health increased to "<< max_health << ".\n Maximum Mana increased to " << max_mana << "!" << std::endl;
}

void Player::restoreHealth(const int amnt){
    health += amnt;
    if(health > max_health){
        health = max_health;
    }
    std::cout << "Health restored! You now have \033[33m" << health << "\033[0m health remaining." << std::endl;
}

void Player::takeDamage(const int amnt){
    dmg = amnt - armor_stat;
    if(dmg <= 0){
        std::cout << "Your armor reverberates with a clang, but you take no damage" << std::endl;
    }else{
        health = health - dmg
        std::cout << "You take \033[31m" << dmg << "\033[0m damage. You have \033[33m" << health << "\033[0m health remaining." << std::endl;
    }
}

void Player::equipArmor(Item* armor){
        equippedArmor = armor;
        armor_stat = armor->item->damage;
        std::cout << "You equip the \033[33m" << armor->item->name << "\033[0m."

    }

void Player::equipWeapon(Item* weapon){
        equippedWeapon = weapon;
        damage_stat = weapon->item->damage; 

    };
