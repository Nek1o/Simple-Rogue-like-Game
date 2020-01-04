#pragma once
#include "ItemEntity.hpp"

class ItemWeapon : public ItemEntity {
protected:
	int attackValue;
public:
	int getAttackValue();

	void draw(sf::RenderWindow*);
};
