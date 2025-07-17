
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