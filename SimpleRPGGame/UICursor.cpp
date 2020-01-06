#include "UICursor.hpp"
#include "ChoiceItemUI.hpp"

UICursor::UICursor() {
	shiftValue = 0;
	rightBoundary = 0;
	leftBoundary = 0;
	toTheRight = 0;
	ToTheLeft = 0;
}

UICursor::UICursor(ChoiceItemUI* choiceItemUI) {}

UICursor::~UICursor() {}

void UICursor::setShiftValue(double newValue) {
	shiftValue = newValue;
}

void UICursor::setPosition(double x, double y) {
	setPosX(x);
	setPosY(y);

	sf::Sprite* tempSprite = getSprite();

	tempSprite->setPosition(getPosX(), getPosY());

	setSprite(tempSprite);
}
