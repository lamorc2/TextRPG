#ifndef DRINK_H
#define DRINK _H



class Drink : public Item {
protected:
    std::string name;
    std::string description;
    int healthRestored;

public:
    Drink(const std::string& name, const std::string& description, int health)
        : name(name), description(description), healthRestored(health) {}

    std::string getName() const override { return name; }
    std::string getDescription() const override { return description; }
    std::string getType() const override {return "Drink"}

    void use() override {
        std::cout << "You drink the " << name << ". You restore " << healthRestored << " HP.\n";
    }

    int getHealthRestored() const { return healthRestored; }
};