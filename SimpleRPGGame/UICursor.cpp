#include "UICursor.hpp"
#include "ChoiceItemUI.hpp"

UICursor::UICursor(ChoiceItemUI* choiceItemUI, std::string* pathToFrames, int framesInAnimation) : 
Animation(pathToFrames, framesInAnimation) {
	setPosition(choiceItemUI->getPosX(), choiceItemUI->getPosY());

	accelerationPercents = 0;
	tempShiftValue = 0;
	setTimeToSkip(0);
	shiftValue = 0;
	rightBoundary = 0;
	leftBoundary = 0;
	toTheRight = 0;
	ToTheLeft = 0;
	ToTheLeft = false;
	toTheRight = false;
}

UICursor::~UICursor() {}

void UICursor::setShiftValue(double newValue) {
	shiftValue = newValue;
	tempShiftValue = shiftValue;
}

void UICursor::setPosition(double x, double y) {
	Animation::setPosition(x, y);
}

void UICursor::setAccelerationPercent(double accelerationPercents) {
	this->accelerationPercents = accelerationPercents;
}

void UICursor::setFont(sf::Font* font) {}

void UICursor::draw(sf::RenderWindow* window) {
	if (timeToSkip != 0) {
		if (currentTimeToSkip % timeToSkip == 0) {
			currentFrame++;
			if (ToTheLeft) {
				setPosition(getPosX() - tempShiftValue, getPosY());
				tempShiftValue -= (tempShiftValue / 100) * accelerationPercents;
				if (getPosX() <= leftBoundary) {
					tempShiftValue = shiftValue;
					toTheRight = true;
					ToTheLeft = false;
				}
			}
			if (toTheRight) {
				setPosition(getPosX() + tempShiftValue, getPosY());
				tempShiftValue -= (tempShiftValue / 100) * accelerationPercents;
				if (getPosX() >= rightBoundary) {
					tempShiftValue = shiftValue;
					toTheRight = false;
					ToTheLeft = true;
				}
			}
		}
		currentTimeToSkip++;
		currentFrame %= framesInAnimation;
		currentTimeToSkip %= timeToSkip;
		window->draw(*sprites[currentFrame]);
	}
	else {
		currentFrame %= framesInAnimation;
		window->draw(*sprites[currentFrame]);
		currentFrame++;
	}
}