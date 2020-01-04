#pragma once
#include "Effect.hpp"

class FirePotionEffect : public Effect {
protected:

public:

	void tick(CombatEntity*);

	void draw(sf::RenderWindow*);
};