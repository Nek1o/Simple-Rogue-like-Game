#pragma once
#include "CombatEntity.hpp"

class WeakMonster : public CombatEntity {
protected:

public:
	// ����������� � cpp
	WeakMonster() : CombatEntity() {};

	void draw(sf::RenderWindow*);
};