#ifndef ACTION_H
#define ACTION_H

#include "StatusEffect.h"
#include "ConditionType.h"
#include "ActionType.h"

struct Action {

	ActionType type;
	int stat_value;
	std::string name;
	int manaCost;
	int priority; // 1-10 value to influence likelihood of action // Anything over 10 is almost guaranteed override, 20+ is guranteed (if condition met)
	StatusEffect statusEffect;
	ConditionType condition;

	Action(const std::string& name_, const ActionType type_, int stat_value_, int priority_ , const ConditionType condition_, int mana=0, const StatusEffect Effect=StatusEffect::None){
		name = name_;
		type = type_;
		stat_value = stat_value_;
		priority = priority_;
		condition = condition_;
		manaCost = mana;
		statusEffect = Effect;

	}

};



#endif