#pragma once
#include "UICursor.hpp"
#include "ChoiceItemUI.hpp"


class MenuUICursor : public UICursor {
protected:

public:
	MenuUICursor();

	MenuUICursor(ChoiceItemUI*);
	
	~MenuUICursor();

	void draw(sf::RenderWindow*);

	void setFont(sf::Font*);
};