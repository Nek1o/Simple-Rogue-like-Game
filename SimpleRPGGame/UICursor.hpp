#pragma once
#include "UI.hpp"
#include "ChoiceItemUI.hpp"
#include "Animation.hpp"

// убрать все другие классы курсоров и оставить этот ?

class UICursor : public Animation {
protected:
	double shiftValue;
	double tempShiftValue;
	double accelerationPercents;
	double rightBoundary;
	double leftBoundary;
	bool toTheRight;
	bool ToTheLeft;

public:
	// ChoiceItemUI ?
	UICursor(ChoiceItemUI*, std::string*, int);

	virtual ~UICursor();

	void setPosition(double, double);

	void setShiftValue(double);

	void setAccelerationPercent(double);

	void draw(sf::RenderWindow*);

	virtual void setFont(sf::Font*);
};