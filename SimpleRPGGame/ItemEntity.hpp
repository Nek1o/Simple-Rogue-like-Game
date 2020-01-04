#pragma once
#include "Entity.hpp"

class ItemEntity : public Entity {
protected:

public:
	virtual void draw(sf::RenderWindow*) = 0;
};