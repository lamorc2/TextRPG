#ifndef DOOBIE_H
#define DOOBIE_H

#include "item.h"

class Doobie : public Item{

protected:
	std::string name;
	std::string description;
	int manaRestored;


public:


	Doobie(const std::string& name, const std::string& description, int mana)
        : name(name), description(description), manaRestored(mana) {};
	~Doobie();
	

	std::string getName() const override { return name; }
    std::string getDescription() const override { return description; }
    std::string getType() const override {return "Doobie"}
    int getMana(){return manaRestored};

    void use() override {
        std::cout << "You light up the " << name << " and you feel your mana being restored.\n";
    }

}

#endif