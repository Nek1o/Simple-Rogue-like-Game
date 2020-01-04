#include "MenuUICursor.hpp"
#include "ChoiceItemUI.hpp"
#include <iostream>


MenuUICursor::MenuUICursor() {
	sf::Image* cursorImage = new sf::Image();
	sf::Texture* cursorTexture = new sf::Texture();
	sf::Sprite* cursorSprite = new sf::Sprite();

	cursorImage->loadFromFile("C:\\Users\\Nikita\\source\\repos\\SimpleRPGGame\\Debug\\Resources\\Textures\\cursor.png");
	cursorTexture->loadFromImage(*cursorImage);
	cursorSprite->setTexture(*cursorTexture);
	
	// сделать положение зависимым от vector<ChoiceItemUI>

	shiftValue = 5.5;
	setPosX(290);
	setPosY(350);

	rightBoundary = getPosX() + 20;
	leftBoundary = getPosX() - 20;

	ToTheLeft = true;
	toTheRight = false;

	cursorSprite->setPosition(getPosX(), getPosY());

	setImage(cursorImage);
	setTexture(cursorTexture);
	setSprite(cursorSprite);
}

MenuUICursor::MenuUICursor(ChoiceItemUI* choiceItem) {
	sf::Image* cursorImage = new sf::Image();
	sf::Texture* cursorTexture = new sf::Texture();
	sf::Sprite* cursorSprite = new sf::Sprite();

	cursorImage->loadFromFile("Resources/Textures/cursor.png");
	cursorTexture->loadFromImage(*cursorImage);
	cursorSprite->setTexture(*cursorTexture);

	// сделать положение зависимым от vector<ChoiceItemUI>

	shiftValue = 5.5;
	setPosX(choiceItem->getPosX() - 60);
	setPosY(choiceItem->getPosY());

	rightBoundary = getPosX() + 20;
	leftBoundary = getPosX() - 20;

	ToTheLeft = true;
	toTheRight = false;

	cursorSprite->setPosition(getPosX(), getPosY());

	setImage(cursorImage);
	setTexture(cursorTexture);
	setSprite(cursorSprite);
}

MenuUICursor::~MenuUICursor() {}

void MenuUICursor::setShiftValue(double newValue) {
	shiftValue = newValue;
}

void MenuUICursor::setPosition(double x, double y) {
	setPosX(x);
	setPosY(y);

	sf::Sprite* tempSprite = getSprite();

	tempSprite->setPosition(getPosX(), getPosY());

	setSprite(tempSprite);
}

void MenuUICursor::draw(sf::RenderWindow* window) {
	if (ToTheLeft) {
		setPosition(getPosX() - shiftValue, getPosY());
		shiftValue -= (shiftValue / 100) * 12.5;
		if (getPosX() <= leftBoundary) {
			shiftValue = 5.5;
			toTheRight = true;
			ToTheLeft = false;
		}
	}
	if (toTheRight) {
		setPosition(getPosX() + shiftValue, getPosY());
		shiftValue -= (shiftValue / 100) * 12.5;
		if (getPosX() >= rightBoundary) {
			shiftValue = 5.5;
			toTheRight = false;
			ToTheLeft = true;
		}
	}
	//std::cout << getPosX() << " " << shiftValue << std::endl;

	window->draw(*getSprite());
}

void MenuUICursor::setFont(sf::Font* font) {}