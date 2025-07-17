#include "Item.h"
#include "Item.cpp"
#include "player.h"
#include "player.cpp"
#include <string>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include "json.hpp"
#include "Logger.h"
#include <random>
#include "random_util.h"
using json = nlohmann::json;



enum class StatusEffect {Burning, Frozen, Shaded} //TODO just make status effects // Burning - persistent dmg, Freeze - Lose turn, Shaded - anti-heal (disable canHeal bool)
enum class ItemType { Drink, Weapon, Doobie, Armor, Special };
enum class Direction {NORTH,SOUTH,EAST,WEST}
enum class ActionType {Heal, Buff, Debuff, Attack, manaRestore, dmgSpell };
enum class ConditionType {Always, PlayerLow, SelfLow, LastEnemy} //TODO : brainstorm other conditions for combat manager


const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string CYAN = "\033[36m";
const std::string BOLD = "\033[1m";


/*TODO : 

Save System (Save + Load Function)
Game Over function
CleanUp Function
Move System - Location Database
Create Items + Item Initializer Function [item database]
Finish Combat System
Custom Character???
Interactables
New Item Type: Cure - Removes all negative statuses
Implement Enemy CopyConstructor
Item use dialogue??

*/


//==== GLOBAL DATABASES ==== \\
//Maps IDs to unique ptrs for easy access
std::unordered_map<std::string, std::unique_ptr<Item>> ItemDatabase; 
std::unordered_map<std::string, std::unique_ptr<Location>> LocationDatabase;
std::unordered_map<std::string, Enemy> EnemyDatabase; //Enemies are initialized here and copies made
std::unordered_map<std::string, std::unique_pr<Action>> ActionDatabase;

// ========================= \\







struct InventoryEntry {
    std::string itemID;
    int quantity;

    InventoryEntry(const std::string i, int q){
    	itemID = i;
    	quantity = q;
    }
        

    void to_json(json& j, const InventoryEntry& entry) {
    j = json{
        {"itemID", entry.itemID},
        {"quantity", entry.quantity}
    };
}

};



struct Action {

	ActionType type;
	int stat_value;
	std::string name;
	int manaCost;
	int priority; // 1-10 value to influence likelihood of action // Anything over 10 is almost guaranteed override, 20+ is guranteed (if condition met)
	ConditionType condition;



};




void GameOver(Player& player){// add option to quit or load save file 

}

void Quit(Player& player){
	//Save Player, Delete Items from database, shutdown logger, delete locations, close application, 
	Save(player); 
	Logger::Shutdown();
}


void Save(Player& player){ // Use nlomann/json library // TODO : how to load into location 
		json player_build;
		player_build = player;

		

}

bool Load(){// Return false if load is unsuccessful/file is empty, force new game 

}

/* Scrapped for Database System - Keep Incase we rework
bool Move(Player& player, Direction dir){// Executed in user input loop if move "direction" is entered, parse location to the Direction enum class
	Location* loc = player->Location;
	switch(dir){

        case Direction::NORTH
            //code
        	if(loc->north != nullptr){
        		player->Location = loc->north;
        		if(player->Location->Enter()){
        			Combat(player, player->Location->enemies,true)
        		}
        	}else{
        		std::cout << "There's nowehere to go to the North." << std::endl;
        	}
            break;

        case Direction::SOUTH
            //code
            if(loc->south != nullptr){
        		player->Location = loc->south;
        		if(player->Location->Enter()){
        			Combat(player, player->Location->enemies,true)
        		}
        	}else{
        		std::cout << "There's nowehere to go to the South." << std::endl;
        	}
            break;

        case Direction::EAST
            //code
            if(loc->east != nullptr){
        		player->Location = loc->east;
        		if(player->Location->Enter()){
        			Combat(player, player->Location->enemies,true)
        		}
        	}else{
        		std::cout << "There's nowehere to go to the East." << std::endl;
        	}
            break;

        case Direction::WEST
            //code
            if(loc->west != nullptr){
        		player->Location = loc->west;
        		if(player->Location->Enter()){
        			Combat(player, player->Location->enemies,true);
        		}
        	}else{
        		std::cout << "There's nowehere to go to the West." << std::endl;
        	}
            break;

        default:
        	Logger::Log("Error: Move direction not recognized.");
        	//error handling // add debug log output
}
*/

bool Move(Player& player, const std::string locationID){// Before Calling function, verify that location ID is in list of accessible rooms to prevent 
	bool isSurprise = true;
	player->Location = LocationDatabase[locationID];
	if(player->Location.Enter()){
		Combat(player, player->Location.enemies,isSurprise)
	}

}

void addtoInventory(Player& player,const  std::string& itemID, int quantity){// TODO : remake for ID and database lookup system 

	for (auto entry : player->inventory)
		if(entry->item.name == newItem.name && entry.stackable){
			entry.quantity += quantity;

		}else{
			player->inventory.emplace_back(InventoryEntry(newItem, quantity));
		}
	std::cout << YELLOW << newItem->name << RESET << " has been added to your inventory." << std::endl;

}



void showInventoryMenu(Player& player) { // TODO : rework for ID + Database lookup

    if (player.inventory.empty()) {
        std::cout << "Your inventory is empty.\n";
        return;
    }

    std::cout << "\n== Inventory ==\n";
    for (size_t i = 0; i < player.inventory.size(); ++i) {
        std::cout << i + 1 << ". " << player.inventory[i].item->getName()
                  << " (x" << player.inventory[i].quantity << ")\n";
    }

    std::cout << "Choose item to use (0 to cancel): ";
    int choice;
    std::cin >> choice;

    if (choice == 0) return;
    if (choice < 1 || choice > player.inventory.size()) {
        std::cout << "Invalid choice.\n";
        return;
    }

    InventoryEntry& entry = player.inventory[choice - 1];
    entry->item->Use(player);

}









void typewriterPrint(const std::string& text) {
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
    }
    std::cout << std::endl;
}

void LoganIntro(Player& player){
	std::cout << "\n\n You walk up to a house, the aroma of weed and the sounds of music filling the air as you cross the street. You take one look through the
	big window and see 5 people in the kitchen, centered around the island counter in the center. Cody starts to bark as you walk through the door, and everyone turns over to you." << std::endl;

}

void CadenIntro(Player& player){
	std::cout << "\n\n You roll down the windows as you approach your house, the sound of music filling the air as you roll into the driveway. You take one look through the
	big kitchen window and see 5 people in the kitchen, centered around the island counter in the center. Cody wags his tail in the back as you park the car." << std::endl;
	std::cout << "You hear the music and feel the bass shaking the walls as you open the door and everyone turns your way." << std::endl;
	typewriterPrint("Connor: Jeez buddy, what took you so long? Late night at Family Dollar?")
	typewriterPrint("")

}

void ConnorIntro(Player& player){
	std::cout << "\n\n You walk up to a house, the aroma of weed and the sounds of music filling the air as you cross the street. You take one look through the
	big window and see 5 people in the kitchen, centered around the island counter in the center. Cody starts to bark as you walk through the door, and everyone turns over to you." << std::endl;

}

void CaydenIntro(Player& player){
	std::cout << "\n\n You walk up to a house, the aroma of weed and the sounds of music filling the air as you cross the street. You take one look through the
	big window and see 5 people in the kitchen, centered around the island counter in the center. Cody starts to bark as you walk through the door, and everyone turns over to you." << std::endl;

}

void DylanIntro(Player& player){
	std::cout << "\n\n You walk up to a house, the aroma of weed and the sounds of music filling the air as you cross the street. You take one look through the
	big window and see 5 people in the kitchen, centered around the island counter in the center. Cody starts to bark as you walk through the door, and everyone turns over to you." << std::endl;

}

void RylanIntro(Player& player){

	std::cout << "\n\nYou walk up to a house, the aroma of weed and cheap cologne mixing in the summer night air. Music thumps through the walls, bass rattling the windowpanes.\n";
	std::cout << "You pause at the door, glance through the big front window. Five silhouettes crowd around the kitchen island, laughing hard, passing something around.\n";
	std::cout << "Cody, Caden's dog, starts barking as soon as you open the door. Every head turns your way.\n";

	typewriterPrint("Connor: Jesus, Rylan — you planning to make an entrance or were you just hoping we’d forget about you?");
	typewriterPrint("Caden: Don’t let him in, he’s late. Punishment shot.");
	typewriterPrint("Logan: Nah, we already drained the mystery punch. Guy missed his chance.");
	typewriterPrint("Tim: Lucky bastard. I’m still convinced it had battery acid in it. Last time I drink something Connor brings.");
	typewriterPrint("Dylan: Dude, it changed colors while I was pouring it.");
	typewriterPrint("Cayden: Yeah, it looked like a Capri Sun from another dimension.");
	typewriterPrint("Logan: That stuff was wild, it tasted like Skittles and gasoline.");


	std::cout << "You glance at the kitchen sink. An empty glass pitcher with a plain white label rests beside it. There’s a faint shimmer in the few droplets left inside.\n";
	std::cout << "The liquid seems to shift hues while you look at it, like it’s never quite settling on one color.\n";

	typewriterPrint("Connor: Whatever it was, it was worth it. 10 dollars for a 2 Liter? That's a steal. But hey—");
	typewriterPrint("Connor grabs a can from the fridge and cracks it open with a grin.");
	typewriterPrint("Connor: —we’ve got backup.");
	typewriterPrint("He reaches into the fridge and pulls out a " + YELLOW + "Rocket Pop Twisted Tea" + RESET + ", holding it toward you with a grin.");
	std::cout << "Do you accept? (Y/N)";
	std::cin >> input;
	while(input != "Y" && input != "N"){
		std::cout << std::endl << "(Y/N)?";
		std::cin >> input;
	}
	if(input == "Y"){// Item(ItemType type_, int stat_value, std::string name_, std::string description_, bool stackable){
		addtoInventory(player, "rocketpop_twea", 1)		

	}else if(input == "N"){
		typewriterPrint("Connor: Suit yourself. I’ll leave it on the counter in case you grow a spine.");
    	typewriterPrint("Tim: Don’t worry, he’s just salty you're not fifteen drinks deep like him.");
    

	}
	typewriterPrint("Logan: C’mon, let’s play something. Bitch Cup?");
	typewriterPrint("Caden: Let's get some cup pong going");
	typewriterPrint("Logan: You're just avoiding bitch cup since you threw up in the potted plant last time");
	typewriterPrint("Caden: That's because someone decided to mix Fireball, Eggnog, and lemon juice in the bitch cup.");
	typewriterPrint("Tim: For the record, I told you guys NOT to do that");
	typewriterPrint("Connor: Well, you live and you learn");
	typewriterPrint("Dylan: More like you fuck around and find out");





	std::cout << "\n\nThe night carries on in a blur of music, laughter, and blurry phone videos.\n";
	std::cout << "Someone starts a game of Bitch Cup. Dylan dances with Cody. Logan dares Caden to drink out of the plant vase. It all blends together.\n";
	std::cout << "But you never touch the punch. You remember that clearly.\n";

	std::cout << "\n\n---\n";
	std::cout << "Your head pounds.\n";
	std::cout << "You open your eyes.\n";
	std::cout << "The music's stopped.\n";
	std::cout << "The lights are still on... but the house is silent.\n";
	std::cout << "Everyone is gone.\n";
	std::cout << "Only the white-labeled pitcher remains on the counter. And it’s no longer empty.\n";
	std::cout << "---\n\n";

}


Action* enemyAction(Enemy& e, Player& player){
			Action* pickedAction = nullptr;
			int actionScore = 0;
			int highestScore = 0;
			double random_factor;

			for(Action* action : e->actions){
				actionScore = 0;
				

				if(action->manaCost != 0 && action->manaCost > e->mana){
					continue;
				}
				switch(action->condition){//Calculate action priority score based on condition /// Should action score be in a range, maybe 1-10?? 
					// Concept: Each condition when filled has a base value, plus a random generated number to make actions more variable. 
				case ConditionType::Always:
					//code
					random_factor = randomFloat(0.5,1.0);
					actionScore = action->priority*random_factor;
					if(actionScore >= highestScore){
						highestScore = actionScore;
						pickedAction = action;
					}
					break;
				case ConditionType::PlayerLow:
					//code
					if(player->health <= (0.25*player->max_health)){
						random_factor = randomFloat(0.5,1.0);
						actionScore = action->priority*random_factor;
					}else{
						continue;
					}
					if(actionScore >= highestScore){
						highestScore = actionScore;
						pickedAction = action;
					}
					break;

				case ConditionType::SelfLow:
					//code
					if(e->health <= (0.5*e->max_health)){
						random_factor = randomFloat(0.5,1.0);
						actionScore = action->priority*random_factor;
					}else{
						continue;
					}
					if(actionScore >= highestScore){
						highestScore = actionScore;
						pickedAction = action;
					}
					break;

				case ConditionType::LastEnemy:
					//code
					if(enemies.size() == 1){
						random_factor = randomFloat(0.5,1.0);
						actionScore = action->priority*random_factor;
					}else{
						continue;
					}
					if(actionScore >= highestScore){
						highestScore = actionScore;
						pickedAction = action;
					}
					break;

				}
			}
			return pickedAction;

}



void Combat(Player& player, std::vector<Enemy> enemies, bool surprise){//Combat: Takes player, list of enemies , bool surprise // surprise is true if enemies go first
	//TODO : Implement pre combat saving, implement XP system??
	Save(player);
	Action* enemyAction;
	


	if(surprise){//
		for(Enemy e : enemies){// Combat Manager iterates through enemies action lists, calculates priority score + random chance multiplier to perform action
			enemyAction	= enemyAction(e,player);
			enemyAction->
			//TODO : Implement UseAction function on emey or action??
		}
	}
	while(player.health > 0 && !enemies.empty()){ // While Player is alive and enemies are alive
			//TODO : Implement player turn here

			//

		for(Enemy e : enemies){
			enemyAction = enemyAction(e,player);
		}
	}
	if(player.health <= 0){
		//TODO : Game Over Function // save system also 
		GameOver();
	}
}


int main(int argc, char[] argv){

	Logger::Init(true, "debug.log");
    Logger::Log("Game started")
	std::string player_name;


	//initialized items here || all IDs must be lowercase
	//std::unordered_map<std::string, Item*> ItemDatabase;
	//Item(const ItemType& type_, const int& stat_value, const std::string& name_, const std::string& description_, bool stack, const std::string& ID);
	//enum class StatusEffect {Burning, Frozen} //TODO just make status effects 
	//enum class ItemType { Drink, Weapon, Doobie, Armor, Special };
	bool canStack = true;
	bool noStack = false;

	ItemDatabase["rocketpop_twea"] = std::make_unique<Item>(ItemType::Drink, 25, "RocketPop Twisted Tea", "A refreshing and patriotic beverage, perfect for a warm summer night. Restores 25 HP.", canStack );
	ItemDatabase["cross_joint"] = std::make_unique<Item>(ItemType::Doobie, 999, YELLOW + "The Cross Joint"+RESET, "Rolled by a professional, the closest you'll get to seeing god. Restores all mana.", canStack );
	ItemDatabase["wizard_staff"] = std::make_unique<Item>(ItemType::Weapon, 10, "Wizard Staff", "An assortment of cans taped together with masking tape to form a makeshift staff. +10 DMG", noStack);
	ItemDatabase["dtd_shirt"] = std::make_unique<Item>(ItemType::Armor, 5, "Founding Father T-Shirt", "The shirt of a DTD Founding Father. Comfortable, but not very protective. +5 Armor", noStack);
	ItemDatabase["roach"] = std::make_unique<Item>(ItemType::Doobie, 10, "Roach", "What most people would think is unsmokeable, an experienced stoner could manage 3-4 more hits out of this. +10 Mana", canStack);
	ItemDatabase["busch_apple"] = std::make_unique<Item>(ItemType::Drink, 999, "Busch Light Apple", "A rare, limited-edition classic. They only come around once a year. Restores all HP", canStack);
	ItemDatabase["jeeter"] = std::make_unique<Item>(ItemType::Doobie, 50, "Jeeter Joint", "An infused, kief covered joint with a glass tip. Pure Heaven. +50 Mana", canStack);


	/////



	////initialize locations 

	LocationDatabase["kitchen"] = std::make_unique<Location>();

	////

	

	////initialize enemies 

	EnemyDatabase["goblin"] = enemy()


	////




	std::cout << "Welcome to THE GAME \n\t title pending "<< std::endl;
	std::cout << "Name(Logan, Caden, Connor, Dylan, Rylan, Cayden, Tim): ";
	//Logan, Caden, Connor, Dylan, Rylan, Cayden, Tim?
	while(std::cin >> player_name){
		if(player_name == "Connor" || player_name == "Caden"  || player_name == "Cayden" || player_name == "Dylan" || player_name == "Rylan" || player_name == "Tim" || player_name == "Logan"){
			break;
		}else{
			std::cout << "Name not recognized. Please enter a valid character." << std::endl;
		}
	}

	Player player = Player(player_name);
	if(player_name == "Connor"){
		ConnorIntro(player);
	}else if(player_name == "Caden"){
		CadenIntro(player);
	}else if(player_name == "Cayden"){
		CaydenIntro(player);
	}else if(player_name == "Dylan"){
		DylanIntro(player);
	}else if(player_name == "Rylan"){
		RylanIntro(player);
	}else if(player_name == "Tim"){
		TimIntro(player);
	}else if(player_name == "Logan"){
		LoganIntro(player);
	}


	