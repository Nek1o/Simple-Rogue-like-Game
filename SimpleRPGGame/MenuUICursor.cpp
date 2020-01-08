#include "MenuUICursor.hpp"
#include "ChoiceItemUI.hpp"
#include <iostream>

MenuUICursor::MenuUICursor(ChoiceItemUI* choiceItem, std::string* pathToFrames, int framesInAnimation) : 
	UICursor (choiceItem, pathToFrames, framesInAnimation){

	//shiftValue = 5.5;
	//setPosX(choiceItem->getPosX() - 60);
	//setPosY(choiceItem->getPosY());

	setPosition(getPosX() - 60, getPosY());

	rightBoundary = getPosX() + 20;
	leftBoundary = getPosX() - 20;

	ToTheLeft = true;
	toTheRight = false;
}

MenuUICursor::~MenuUICursor() {
	std::cout << "cursor Destructor" << std::endl;
}

void MenuUICursor::draw(sf::RenderWindow* window) {
	UICursor::draw(window);
}

void MenuUICursor::setFont(sf::Font* font) {}