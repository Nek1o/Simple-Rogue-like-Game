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
	Player();

	~Player();

	void useItem();

	void draw(sf::RenderWindow*);
};