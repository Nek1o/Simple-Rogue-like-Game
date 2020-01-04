#pragma once
#include "CombatEntity.hpp"
#include "ItemPotion.hpp"
#include <vector>

class Player : public CombatEntity {
protected:
	std::vector<ItemPotion> potions;
	//std::vector<ItemWeapon> weapons;
	//std::vector<ItemShield> shields;
	int exp;

public:
	// констуркторы в cpp
	Player() : CombatEntity(), exp(0) {};

	void usePotion();

	void chooseWeapon();

	void chooseShield();

	void draw(sf::RenderWindow*);
};