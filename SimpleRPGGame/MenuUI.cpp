#include "MenuUI.hpp"
#include "Animation.hpp"
#include <iostream>

MenuUI::MenuUI() {
	gameName = new sf::Text();
	gameName->setString("Dungeon Escape");
	gameName->setPosition(200, 25);
	gameName->setCharacterSize(50);

	this->font = new sf::Font();
	this->font->loadFromFile("Resources/Fonts/ARCADECLASSIC.ttf");

	MenuUI::choices = std::vector<ChoiceItemUI*>();
	for (size_t i = 0; i < 3; i++) {
		ChoiceItemUI* choiceItemUI = new ChoiceItemUI();
		choices.push_back(choiceItemUI);
	}

	setFont(this->font);

	choices[0]->setText("Start");
	choices[0]->setPosition(350, 350);

	choices[1]->setText("About");
	choices[1]->setPosition(350, choices[0]->getPosY() + 80);

	choices[2]->setText("Quit");
	choices[2]->setPosition(350, choices[1]->getPosY() + 80);

	std::string* pathToCursorFrames = new std::string();
	*pathToCursorFrames = "Resources/Textures/MenuCursor/";
	cursor = new MenuUICursor(choices[0], pathToCursorFrames, 1);
	cursor->setShiftValue(5.5);
	cursor->setAccelerationPercent(12.5);
	cursor->setTimeToSkip(1);
	setActiveChoiceItem(0);

	std::string* pathToCampfire = new std::string();

	*pathToCampfire = "Resources/Textures/campfire/";
	campfire = new Animation(pathToCampfire, 8);
	campfire->setScale(1.725, 1.725);
	campfire->setTimeToSkip(5);

	campfire->setPosition(245, 0);
}

MenuUI::~MenuUI() {
	for (auto& x : choices) {
		delete x;
	}
	delete gameName;
	delete font;
	delete cursor;
	delete campfire;
	std::cout << "MenuUI destructor" << std::endl;
}

ActiveChoiceItem MenuUI::getActiveChoiceItem() {
	for (size_t i = 0; i < choices.size(); i++) {
		if (choices[i]->isChosen()) {
			return (ActiveChoiceItem)i;
		}
	}
}

void MenuUI::setActiveChoiceItem(int n) {
	for (auto& choice : choices) {
		choice->unchoose();
	}
	choices[n]->choose();
	setCursorPosition();
}

void MenuUI::setCursorPosition() {
	for (auto& choice : choices) {
		if (choice->isChosen()) {
			cursor->setPosition(cursor->getPosX(), choice->getPosY() + 10);
		}
	}
}

void MenuUI::setFont(sf::Font* font) {
	this->font = font;
	for (auto& choice : choices) {
		choice->setFont(this->font);
	}
	gameName->setFont(*font);
}

void MenuUI::draw(sf::RenderWindow* window) {
	for (auto& choice : choices) {
		choice->draw(window);
	}
	window->draw(*gameName);
	cursor->draw(window);
	campfire->draw(window);
}