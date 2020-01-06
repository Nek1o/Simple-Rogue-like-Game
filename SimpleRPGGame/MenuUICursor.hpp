#pragma once
#include "UICursor.hpp"
#include "ChoiceItemUI.hpp"


class MenuUICursor : public UICursor {
protected:
	double shiftValue;
	double rightBoundary;
	double leftBoundary;
	bool toTheRight;
	bool ToTheLeft;

public:
	MenuUICursor();

	MenuUICursor(ChoiceItemUI*);
	
	~MenuUICursor();

	void draw(sf::RenderWindow*);

	void setFont(sf::Font*);
};