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
	std::vector<Enemy*> enemies;

	//TODO : add an interactable object, store a list of interactables in a location


public:


	Location(const std::string& name, const std::string& checkPrompt_, const std::string& enterPrompt_);


	//Build Location map/node connections in main code using pointer logic i.e Kitchen->left = 
	Location* north;
	Location* south;
	Location* east;
	Location* west;


	//NOTE: should enter() be main code or attribute of location 
	// both? keep an enemy list in room , have bool enter function that returns true if surprie combat, and also outputs initial room check
	bool Enter(){ // returns true if surprise combat

		std::cout << enterPrompt;

		return combatTrigger;

	}
	
	void addEnemy(Enemy* enemy){
		enemies.push_back(enemy);
	}



}


#endif