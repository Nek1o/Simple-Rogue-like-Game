#include "MenuUI.hpp"

MenuUI::MenuUI() {
	gameName = new sf::Text();
	gameName->setString("Dungeon Escape");
	gameName->setPosition(200, 25);
	gameName->setCharacterSize(50);

	this->font = new sf::Font();
	this->font->loadFromFile("C:\\Users\\Nikita\\source\\repos\\SimpleRPGGame\\Debug\\Resources\\Fonts\\ARCADECLASSIC.ttf");

	/*cursor = new sf::Sprite();
	cursor->setPosition(250, 100);
	sf::Texture* cursorTexture = new sf::Texture();
	sf::Image* cursorImage = new sf::Image();
	cursorImage->loadFromFile("C:\\Users\\Nikita\\source\\repos\\SimpleRPGGame\\Debug\\Resources\\Textures\\cursor.png");
	cursorTexture->loadFromImage(*cursorImage);
	cursor->setTexture(*cursorTexture);*/

	cursor = new MenuUICursor();


	MenuUI::choices = std::vector<ChoiceItemUI*>();
	for (size_t i = 0; i < 3; i++) {
		ChoiceItemUI* choiceItemUI = new ChoiceItemUI();
		choices.push_back(choiceItemUI);
	}

	setFont(this->font);

	choices[0]->setText("Start");
	choices[0]->setPosition(350, 290);
	//choices[0]->choose();
	setActiveChoiceItem(0);

	choices[1]->setText("About");
	choices[1]->setPosition(350, 370);

	choices[2]->setText("Quit");
	choices[2]->setPosition(350, 450);
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
	/*window->draw(*cursor);*/
}