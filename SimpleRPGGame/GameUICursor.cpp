#include "GameUICursor.hpp"

GameUICursor::GameUICursor() {
	sf::Image* cursorImage = new sf::Image();
	sf::Texture* cursorTexture = new sf::Texture();
	sf::Sprite* cursorSprite = new sf::Sprite();

	cursorImage->loadFromFile("Resources/Textures/GameCursor/0.gif");
	cursorTexture->loadFromImage(*cursorImage);
	cursorSprite->setTexture(*cursorTexture);

	std::string* pathToAnimation = new std::string();
	*pathToAnimation = "Resources/Textures/GameCursor/";

	animation = new Animation(pathToAnimation, 1);
	animation->setTimeToSkip(1);

	// сделать положение зависимым от vector<ChoiceItemUI>

	shiftValue = 1;
	setPosX(290); // ?
	setPosY(350); // ?

	animation->setPosition(getPosX(), getPosY());

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

	cursorImage->loadFromFile("Resources/Textures/GameCursor/0.gif");
	cursorImage->createMaskFromColor(sf::Color(0, 0, 0, 0));
	cursorTexture->loadFromImage(*cursorImage);
	cursorSprite->setTexture(*cursorTexture);

	std::string* pathToAnimation = new std::string();
	*pathToAnimation = "Resources/Textures/GameCursor/";

	animation = new Animation(pathToAnimation, 1);
	animation->setTimeToSkip(1);

	// сделать положение зависимым от vector<ChoiceItemUI>

	shiftValue = 2.5;

	setPosX(choiceItem->getPosX() + 80);
	setPosY(choiceItem->getPosY() + 30);

	animation->setPosition(getPosX(), getPosY());

	rightBoundary = getPosX() + 5;
	leftBoundary = getPosX() - 5;

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
		animation->setPosition(getPosX(), getPosY());
		shiftValue -= (shiftValue / 100) * 22;
		if (animation->getPosX() <= leftBoundary) {
			shiftValue = 2.5;
			toTheRight = true;
			ToTheLeft = false;
		}
	}
	if (toTheRight) {
		setPosition(getPosX() + shiftValue, getPosY());
		animation->setPosition(getPosX(), getPosY());
		shiftValue -= (shiftValue / 100) * 22;
		if (animation->getPosX() >= rightBoundary) {
			shiftValue = 2.5;
			toTheRight = false;
			ToTheLeft = true;
		}
	}
	animation->draw(window);
}

void GameUICursor::setFont(sf::Font* font) {}