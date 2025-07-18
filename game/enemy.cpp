
Enemy::Enemy(const std::string& name_, int max_HP, int atk, int mana_){
		canHeal = true;
		max_health = max_HP;
		health = max_health;
		damage = atk;
		mana = mana_
		max_mana = mana_;
	}

Enemy::Enemy(Enemy e){
	name = e.name;
	max_health = e.max_health;
	health = e.health;
	damage = e.damage;
	actions = e.actions;
	mana = e.mana;
}


void Enemy::restoreMana(const int amnt){
    mana += amnt;
    if(mana > max_mana){
        mana = max_mana;
    }
    std::cout << "Mana restored! You now have \033[33m" << mana << "\033[0m Mana remaining." << std::endl;
}


void Enemy::restoreHealth(const int amnt){
    health += amnt;
    if(health > max_health){
        health = max_health;
    }
    std::cout << "Hana restored! You now have \033[33m" << mana << "\033[0m Health remaining." << std::endl;
}