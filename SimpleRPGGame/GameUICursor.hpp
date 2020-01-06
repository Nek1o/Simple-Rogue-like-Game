#pragma once
#include "UICursor.hpp"

class GameUICursor : public UICursor {
private:

public:
	GameUICursor();

	GameUICursor(ChoiceItemUI*);

	~GameUICursor();

	void draw(sf::RenderWindow*);

	void setFont(sf::Font*);
};



