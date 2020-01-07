#pragma once
#include "UI.hpp"
#include "ChoiceItemUI.hpp"
#include "Animation.hpp"

//  TODO ��������������� �� Animation � ��������� �� � draw()

class UICursor : public UI {
protected:
	double shiftValue;
	double rightBoundary;
	double leftBoundary;
	bool toTheRight;
	bool ToTheLeft;
	Animation* animation;

public:
	UICursor();

	// ��� ������� ������, ����� ������ ���������� ����� �� ��
	UICursor(ChoiceItemUI*);

	virtual ~UICursor();

	void setPosition(double, double);

	void setShiftValue(double);

	virtual void draw(sf::RenderWindow*) = 0;

	virtual void setFont(sf::Font*) = 0;
};