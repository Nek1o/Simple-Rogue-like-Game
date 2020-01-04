#pragma once
#include "ItemPotion.hpp"

class FreezingPotion : public ItemPotion {
protected:

public:

	void use(CombatEntity*);

	void draw(sf::RenderWindow*);
};
