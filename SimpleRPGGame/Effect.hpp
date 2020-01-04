#pragma once
#include "Entity.hpp"
#include "CombatEntity.hpp"
class Effect : public Entity {
protected:
	int durationTurns;
	int value;
public:
	Effect() : durationTurns(0), value(0) {}

	virtual void tick(CombatEntity*);

	virtual void draw(sf::RenderWindow*) = 0;
};