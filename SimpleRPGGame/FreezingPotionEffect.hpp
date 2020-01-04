#pragma once
#include "Effect.hpp"

class FreezingPotionEffect : Effect {
protected:

public:
	void tick(CombatEntity*);

	void draw(sf::RenderWindow*);
};