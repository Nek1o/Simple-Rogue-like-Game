#pragma once
#include "Effect.hpp"

class HealingPotionEffect : public Effect {
protected:

public:
	void tick(CombatEntity*);

	void draw(sf::RenderWindow*);
};