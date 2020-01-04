#pragma once
#include "ItemPotion.hpp"

class HealingPotion : public ItemPotion {
protected:

public:

	void use(CombatEntity*);

	void draw(sf::Window*);
};
