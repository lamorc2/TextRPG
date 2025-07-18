#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"

class Weapon : public Item{

protected:
	std::string name;
	std::string description;
	int dmg;

public:

	Weapon(std::string weapon_name, int dmg, )
	~Weapon()

	std::string getName() const override { return name; }
    std::string getDescription() const override { return description; }
    std::string getType() const override {return "Weapon"}

    void use() override {
        std::cout << "You equip the " << name << ".\n";
    }


}

#endif 