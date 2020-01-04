#pragma once
#include "UI.hpp"

class MenuUICursor : public UI {
protected:
	double shiftValue;
	double rightBoundary;
	double leftBoundary;
	bool toTheRight;
	bool ToTheLeft;

public:
	MenuUICursor();
	
	~MenuUICursor();

	void setPosition(double, double);

	void setShiftValue(double);

	void draw(sf::RenderWindow*);

	void setFont(sf::Font*);
};