#pragma once
#include "UICursor.hpp"
#include "ChoiceItemUI.hpp"


class MenuUICursor : public UICursor {
protected:

public:
	MenuUICursor(ChoiceItemUI*, std::string*, int);
	
	~MenuUICursor();

	void draw(sf::RenderWindow*);

	void setFont(sf::Font*);
};