#pragma once
#include "Entity.hpp"

class CombatEntity : public Entity {
protected:
	int hp;
	int attackValue;
	int defenseValue;
public:
	CombatEntity();

	CombatEntity(int, int, int);

	int getHP();

	void setHP(int);

	int getAttackValue();

	void setAttackValue(int);

	int getDefenseValue();

	void setDefenseValue(int);

	void attack(CombatEntity*);

	void defend(CombatEntity*);

	bool isAlive();

	virtual void draw(sf::RenderWindow*) = 0;
};


