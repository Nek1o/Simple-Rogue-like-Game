#pragma once
#include "CombatEntity.hpp"

class StrongMonster : public CombatEntity {
protected:

public:
	// ����������� � cpp
	StrongMonster() : CombatEntity() {}

	void draw(sf::RenderWindow*);

};