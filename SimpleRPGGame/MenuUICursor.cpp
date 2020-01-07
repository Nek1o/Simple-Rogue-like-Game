#include "MenuUICursor.hpp"
#include "ChoiceItemUI.hpp"
#include <iostream>


MenuUICursor::MenuUICursor() {
	sf::Image* cursorImage = new sf::Image();
	sf::Texture* cursorTexture = new sf::Texture();
	sf::Sprite* cursorSprite = new sf::Sprite();

	cursorImage->loadFromFile("Resources/Textures/MenuCursor/0.gif");
	cursorTexture->loadFromImage(*cursorImage);
	cursorSprite->setTexture(*cursorTexture);
	
	std::string* pathToAnimation = new std::string();
	*pathToAnimation = "Resources/Textures/MenuCursor/";

	animation = new Animation(pathToAnimation, 1);
	animation->setTimeToSkip(0);
	// сделать положение зависимым от vector<ChoiceItemUI>

	shiftValue = 5.5;
	setPosX(290);
	setPosY(350);

	animation->setPosition(getPosX(), getPosY());

	rightBoundary = getPosX() + 20;
	leftBoundary = getPosX() - 20;

	ToTheLeft = true;
	toTheRight = false;

	//cursorSprite->setPosition(getPosX(), getPosY());

	//animation->setPosition(getPosX(), getPosY());

	setImage(cursorImage);
	setTexture(cursorTexture);
	setSprite(cursorSprite);
}

MenuUICursor::MenuUICursor(ChoiceItemUI* choiceItem) {
	sf::Image* cursorImage = new sf::Image();
	sf::Texture* cursorTexture = new sf::Texture();
	sf::Sprite* cursorSprite = new sf::Sprite();

	cursorImage->loadFromFile("Resources/Textures/MenuCursor/0.gif");
	cursorTexture->loadFromImage(*cursorImage);
	cursorSprite->setTexture(*cursorTexture);

	std::string* pathToAnimation = new std::string();
	*pathToAnimation = "Resources/Textures/MenuCursor/";

	animation = new Animation(pathToAnimation, 1);
	animation->setTimeToSkip(0);
	// сделать положение зависимым от vector<ChoiceItemUI>

	shiftValue = 5.5;
	setPosX(choiceItem->getPosX() - 60);
	setPosY(choiceItem->getPosY());

	animation->setPosition(getPosX(), getPosY());

	rightBoundary = getPosX() + 20;
	leftBoundary = getPosX() - 20;

	ToTheLeft = true;
	toTheRight = false;


	setImage(cursorImage);
	setTexture(cursorTexture);
	setSprite(cursorSprite);
}

MenuUICursor::~MenuUICursor() {
	std::cout << "cursor Destructor" << std::endl;
}

void MenuUICursor::draw(sf::RenderWindow* window) {
	if (ToTheLeft) {
		setPosition(getPosX() - shiftValue, getPosY());
		animation->setPosition(getPosX(), getPosY());
		shiftValue -= (shiftValue / 100) * 12.5;
		if (animation->getPosX() <= leftBoundary) {
			shiftValue = 5.5;
			toTheRight = true;
			ToTheLeft = false;
		}
	}
	if (toTheRight) {
		setPosition(getPosX() + shiftValue, getPosY());
		animation->setPosition(getPosX(), getPosY());
		shiftValue -= (shiftValue / 100) * 12.5;
		if (animation->getPosX() >= rightBoundary) {
			shiftValue = 5.5;
			toTheRight = false;
			ToTheLeft = true;
		}
	}
	animation->draw(window);
}

void MenuUICursor::setFont(sf::Font* font) {}