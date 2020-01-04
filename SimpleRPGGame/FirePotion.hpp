#pragma once
#include "ItemPotion.hpp"

class FirePotion : public ItemPotion {
protected:

public:

	void use(CombatEntity*);

	void draw(sf::RenderWindow*);
};