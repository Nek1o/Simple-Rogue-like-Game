#include "GameUICursor.hpp"

GameUICursor::GameUICursor() {
	sf::Image* cursorImage = new sf::Image();
	sf::Texture* cursorTexture = new sf::Texture();
	sf::Sprite* cursorSprite = new sf::Sprite();

	cursorImage->loadFromFile("Resources/Textures/GameCursor.png");
	cursorTexture->loadFromImage(*cursorImage);
	cursorSprite->setTexture(*cursorTexture);

	// сделать положение зависимым от vector<ChoiceItemUI>

	shiftValue = 1;
	setPosX(290); // ?
	setPosY(350); // ?

	rightBoundary = getPosX() + 10;
	leftBoundary = getPosX() - 10;

	ToTheLeft = true;
	toTheRight = false;

	cursorSprite->setPosition(getPosX(), getPosY());

	setImage(cursorImage);
	setTexture(cursorTexture);
	setSprite(cursorSprite);
}

GameUICursor::GameUICursor(ChoiceItemUI* choiceItem) {
	sf::Image* cursorImage = new sf::Image();
	sf::Texture* cursorTexture = new sf::Texture();
	sf::Sprite* cursorSprite = new sf::Sprite();

	cursorImage->loadFromFile("Resources/Textures/GameCursor.png");
	cursorImage->createMaskFromColor(sf::Color(0, 0, 0, 0));
	cursorTexture->loadFromImage(*cursorImage);
	cursorSprite->setTexture(*cursorTexture);

	// сделать положение зависимым от vector<ChoiceItemUI>

	shiftValue = 1;
	setPosX(choiceItem->getPosX() - 20);
	setPosY(choiceItem->getPosY());

	rightBoundary = getPosX() + 10;
	leftBoundary = getPosX() - 10;

	ToTheLeft = true;
	toTheRight = false;

	cursorSprite->setPosition(getPosX(), getPosY());

	setImage(cursorImage);
	setTexture(cursorTexture);
	setSprite(cursorSprite);
}

GameUICursor::~GameUICursor() {}

void GameUICursor::draw(sf::RenderWindow* window) {
	if (ToTheLeft) {
		setPosition(getPosX() - shiftValue, getPosY());
		shiftValue -= (shiftValue / 100) * 12.5;
		if (getPosX() <= leftBoundary) {
			shiftValue = 2.5;
			toTheRight = true;
			ToTheLeft = false;
		}
	}
	if (toTheRight) {
		setPosition(getPosX() + shiftValue, getPosY());
		shiftValue -= (shiftValue / 100) * 12.5;
		if (getPosX() >= rightBoundary) {
			shiftValue = 2.5;
			toTheRight = false;
			ToTheLeft = true;
		}
	}
	window->draw(*getSprite());
}

void GameUICursor::setFont(sf::Font* font) {}