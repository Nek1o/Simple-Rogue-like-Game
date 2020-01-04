#pragma once
#include "Entity.hpp"

class UI : public Entity {
protected:
	sf::Font* font;

public:
	virtual void setFont(sf::Font*) = 0;

	virtual void draw(sf::RenderWindow*) = 0;
};