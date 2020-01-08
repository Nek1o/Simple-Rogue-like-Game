#include "GameUIMenuFrame.hpp"

GameUIMenuFrame::GameUIMenuFrame() {
	player = new Player();

	sf::Image* tempImage = new sf::Image();
	sf::Texture* tempTexture = new sf::Texture();
	sf::Sprite* tempSprite = new sf::Sprite();

	tempImage->loadFromFile("Resources/Textures/GameMenuFrame.png");
	tempImage->createMaskFromColor(sf::Color(0, 0, 0, 255));
	tempTexture->loadFromImage(*tempImage);
	tempSprite->setTexture(*tempTexture);

	setImage(tempImage);
	setTexture(tempTexture);
	setSprite(tempSprite);
}

GameUIMenuFrame::~GameUIMenuFrame() {
	delete player;
}

void GameUIMenuFrame::setFont(sf::Font* font) {}

void GameUIMenuFrame::update(Player* player) {

}


void GameUIMenuFrame::draw(sf::RenderWindow* window) {
	window->draw(*getSprite());
}