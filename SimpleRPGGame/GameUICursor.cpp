#include "GameUICursor.hpp"

GameUICursor::GameUICursor(ChoiceItemUI* choiceItem, std::string* pathToFrames, int framesInAnimation) :
	UICursor(choiceItem, pathToFrames, framesInAnimation)
{
	//shiftValue = 2.5;

	//setPosX(choiceItem->getPosX() + 80);
	//setPosY(choiceItem->getPosY() + 30);

	setPosition(getPosX() + 80, getPosY() + 40);

	rightBoundary = getPosX() + 5;
	leftBoundary = getPosX() - 5;

	ToTheLeft = true;
	toTheRight = false;
}

GameUICursor::~GameUICursor() {}

void GameUICursor::draw(sf::RenderWindow* window) {
	UICursor::draw(window);
}

void GameUICursor::setFont(sf::Font* font) {}