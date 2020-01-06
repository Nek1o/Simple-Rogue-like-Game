#pragma once
#include "UI.hpp"
#include "ChoiceItemUI.hpp"

class UICursor : public UI {
protected:
	double shiftValue;
	double rightBoundary;
	double leftBoundary;
	bool toTheRight;
	bool ToTheLeft;

public:
	UICursor();

	// для первого пункта, чтобы курсор изначально стоял на нём
	UICursor(ChoiceItemUI*);

	virtual ~UICursor();

	void setPosition(double, double);

	void setShiftValue(double);

	virtual void draw(sf::RenderWindow*) = 0;

	virtual void setFont(sf::Font*) = 0;
};