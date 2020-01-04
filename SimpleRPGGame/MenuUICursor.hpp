#pragma once
#include "UI.hpp"
#include "ChoiceItemUI.hpp"

class MenuUICursor : public UI {
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

	void setPosition(double, double);

	void setShiftValue(double);

	void draw(sf::RenderWindow*);

	void setFont(sf::Font*);
};