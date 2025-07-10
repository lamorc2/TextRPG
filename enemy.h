#ifndef ENEMY_H
#define ENEMY_H
#include <string>




class Enemy{

	std::string name;
	int health;
	int max_health;
	int damage;
	bool canHeal;
	std::vector<Action*> actions;


	Enemy(const std::string& name_, const int max_HP, const int atk){
		max_health = max_HP;
		health = max_health;
		damage = atk;
	}

	virtual void Turn(Player& player){// how is this gonna work???

		if(canHeal && health < (0.15*max_health)){
			health = 1.25*health;

		}else{							 
			player->takeDamage(damage);
		}
		//TODO : add any status effects eg. On Fire - Take X damage, frozen - Take X dmg OR Lose a turn, Poison - Take X dmg, do less damage
	}



}; // End of class