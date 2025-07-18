
Location(const std::string& name_, const std::string& checkPrompt_, const std::string& enterPrompt_){
	name
}


bool Location::Enter(){ // returns true if surprise combat

		std::cout << enterPrompt;

		return (!enemies.empty() && combatTrigger);// If enemies havent already been beat && there is surprise combat

	}
	
	void Location::addEnemy(Enemy* enemy){
		enemies.push_back(Enemy(enemy));
	}



	void Location::to_json(json& j, const Player& p) {
		j = json{{"location",name}};


	}