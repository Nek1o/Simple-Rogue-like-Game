#include "GameUI.hpp"
#include "GameUICursor.hpp"

GameUI::GameUI() {
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

	currentHP = new sf::Text();
	currentHP->setString("HP"); // должны быть хп игрока
	currentHP->setPosition(200, 25); // ?
	currentHP->setCharacterSize(20); // ?

	currentExp = new sf::Text();
	currentExp->setString("EXP"); // должны быть exp игрока
	currentExp->setPosition(200, 25); // ?
	currentExp->setCharacterSize(20); // ?

	exp = new sf::Text();
	exp->setString("EXP");
	exp->setPosition(200, 25); // ?
	exp->setCharacterSize(20); // ?

	this->font = new sf::Font();
	this->font->loadFromFile("Resources/Fonts/ARCADECLASSIC.ttf");

	GameUI::choices = std::vector<ChoiceItemUI*>();
	for (size_t i = 0; i < 4; i++) {
		ChoiceItemUI* choiceItemUI = new ChoiceItemUI();
		choices.push_back(choiceItemUI);
	}

	setFont(this->font);

	choices[0]->setText("Attack");
	choices[0]->setPosition(350, 350); // ?

	choices[1]->setText("Defend");
	choices[1]->setPosition(350, choices[0]->getPosY() + 80); // ?

	choices[2]->setText("Use");
	choices[2]->setPosition(350, choices[1]->getPosY() + 80); // ?

	choices[3]->setText("Talk");
	choices[3]->setPosition(350, choices[2]->getPosY() + 80); // ?

	cursor = new GameUICursor(choices[0]);
	setActiveGameChoiceItem(0);

	std::string* pathTohpHeart = new std::string();

	*pathTohpHeart = "Resources/Textures/hpHeart/";
	hpHeart = new Animation(pathTohpHeart, 11);
	hpHeart->setTimeToSkip(5); // ?

	hpHeart->setPosition(245, 0); // ?
	hpHeart->setScale(1, 1); // ?
}

GameUI::~GameUI() {
	delete currentHP;
	delete currentExp;
	delete exp;
	delete cursor;
	delete hpHeart;
	for (auto& choice : choices) {
		delete choice;
	}
}

ActiveGameChoiceItem GameUI::getActiveGameChoiceItem() {
	for (size_t i = 0; i < choices.size(); i++) {
		if (choices[i]->isChosen()) {
			return (ActiveGameChoiceItem)i;
		}
	}
}

void GameUI::setActiveGameChoiceItem(int n) {
	for (auto& choice : choices) {
		choice->unchoose();
	}
	choices[n]->choose();
	setCursorPosition();
}

void GameUI::setCursorPosition() {
	for (auto& choice : choices) {
		if (choice->isChosen()) {
			cursor->setPosition(cursor->getPosX(), choice->getPosY());
		}
	}
}

void GameUI::setFont(sf::Font* font) {
	this->font = font;
	for (auto& choice : choices) {
		choice->setFont(this->font);
	}
	currentHP->setFont(*font);
	currentExp->setFont(*font);
	exp->setFont(*font);
}

void GameUI::draw(sf::RenderWindow* window) {
	for (auto& choice : choices) {
		choice->draw(window);
	}
	window->draw(*currentHP);
	window->draw(*currentExp);
	window->draw(*exp);
	cursor->draw(window);
	hpHeart->draw(window);
	window->draw(*getSprite());
}