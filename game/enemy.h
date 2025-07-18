#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include <vector>
#include "StatusEffect.h"
#include "Action.h"
#include "InventoryEntry.h"



class Enemy{

public:
	
	std::string name;
	StatusEffect StatusEffect = StatusEffect::None;
	int health;
	int max_health;
	int max_mana;
	int mana;
	int damage;
	bool canHeal;
	std::vector<Action*> actions;


	Enemy(const std::string& name_,  int max_HP,  int atk, int mana_=0);

	Enemy(Enemy e);


	void restoreMana(const int amnt);
	void restoreHealth(const int amnt);


	/*
	//NOTE: Scrapped for a more data driven combat manager in main code
	virtual void Turn(Player& player){// how is this gonna work???

		if(canHeal && health < (0.15*max_health)){
			health = 1.25*health;

		}else{							 
			player->takeDamage(damage);
		}
		//TODO : add any status effects eg. On Fire - Take X damage, frozen - Take X dmg OR Lose a turn, Poison - Take X dmg, do less damage
	}
	*/


}; // End of class