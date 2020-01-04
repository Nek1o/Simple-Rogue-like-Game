#pragma once
#include "CombatEntity.hpp"

class StrongMonster : public CombatEntity {
protected:

public:
	// конструктор в cpp
	StrongMonster() : CombatEntity() {}

	void draw(sf::RenderWindow*);

};