#ifndef LOCATION_H
#define LOCATION_H
#include enemy.h
#include <vector>
class Location{


private:

	

	bool combatTrigger; // to trigger combat upon entering
	std::string name;
	std::string checkPrompt;
	std::string enterPrompt;
	

	//TODO : add an interactable object, store a list of interactables in a location


public:




	//Build Location map/node connections in main code using pointer logic i.e Kitchen->left = 
	std::vector<std::string> locationIDs;
	std::vector<Enemy> enemies;


	Location(const std::string& name_, const std::string& checkPrompt_, const std::string& enterPrompt_);
	


	void addConnection(const std::string& ID){
		locationIDs.push_back(ID);
	}


	//NOTE: should enter() be main code or attribute of location 
	// both? keep an enemy list in room , have bool enter function that returns true if surprie combat, and also outputs initial room check
	bool Enter(){ // returns true if surprise combat

		std::cout << enterPrompt;

		return (!enemies.empty() && combatTrigger);// If enemies havent already been beat && there is surprise combat

	}
	
	void addEnemy(Enemy* enemy){
		enemies.push_back(enemy);
	}



	void to_json(json& j, const Player& p) {
		bool hasEnemies = false;
		if(!enemies.empty()){
			hasEnemies = true;
		}
		j = json{{"location",name},{"enemies",hasEnemies}};


	}



}


#endif