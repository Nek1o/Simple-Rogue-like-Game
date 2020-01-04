#pragma once
#include "Entity.hpp"

class CombatEntity : public Entity {
protected:
	int hp;
	int attackValue;
	int defenseValue;
public:
	// конструкторы в cpp
	CombatEntity() : Entity(), hp(0), attackValue(0), defenseValue(0) {};
	CombatEntity(int hp, int attackValue, int defenseValue) : 
		hp(hp), attackValue(attackValue), defenseValue(defenseValue) {};

	void attack(CombatEntity*);

	void defend(CombatEntity*);

	bool isAlive();

	virtual void draw(sf::RenderWindow*) = 0;
};


