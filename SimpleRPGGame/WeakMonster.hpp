#pragma once
#include "CombatEntity.hpp"

class WeakMonster : public CombatEntity {
protected:

public:
	// конструктор в cpp
	WeakMonster() : CombatEntity() {};

	void draw(sf::RenderWindow*);
};