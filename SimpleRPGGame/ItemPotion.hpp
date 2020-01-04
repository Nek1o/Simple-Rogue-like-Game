#pragma once
#include "ItemEntity.hpp"
#include "CombatEntity.hpp"

class ItemPotion : public ItemEntity {
protected:
	int value;

public:
	// конструкторы в cpp
	ItemPotion() : value(0) {};

	ItemPotion(int value) : value(value) {}

	virtual void use(CombatEntity*);

	void draw(sf::RenderWindow*);
};
