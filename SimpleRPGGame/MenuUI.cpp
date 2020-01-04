#include "MenuUI.hpp"
#include "Animation.hpp"

MenuUI::MenuUI() {
	gameName = new sf::Text();
	gameName->setString("Dungeon Escape");
	gameName->setPosition(200, 25);
	gameName->setCharacterSize(50);

	this->font = new sf::Font();
	//this->font->loadFromFile("C:\\Users\\Nikita\\source\\repos\\SimpleRPGGame\\Debug\\Resources\\Fonts\\ARCADECLASSIC.ttf");
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

	cursor = new MenuUICursor(choices[0]);
	setActiveChoiceItem(0);

	std::string* pathToCampfire = new std::string();

	//*pathToCampfire = "C:\\Users\\Nikita\\source\\repos\\SimpleRPGGame\\Debug\\Resources\\Textures\\campfire\\";
	*pathToCampfire = "Resources/Textures/campfire/";
	campfire = new Animation(pathToCampfire);
	campfire->setFramesInAnimation(8);
	campfire->setTimeToSkip(5);

	campfire->setPosition(245, 0);
	campfire->setScale(1.15, 1.15);
}

MenuUI::~MenuUI() {
	for (auto& x : choices) {
		delete x;
	}
	delete gameName;
	delete font;
	delete cursor;
}

ActiveChoiceItem MenuUI::getActiveChoiceItem() {
	for (size_t i = 0; i < 3; i++) {
		if (choices[i]->isChosen() && i == 0) {
			return ActiveChoiceItem::Start;
		}
		if (choices[i]->isChosen() && i == 1) {
			return ActiveChoiceItem::About;
		}
		if (choices[i]->isChosen() && i == 2) {
			return ActiveChoiceItem::Quit;
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