#include "MenuUIController.hpp"
#include <iostream>

MenuUIController::MenuUIController() {
	menuUI = new MenuUI();
}

MenuUIController::MenuUIController(MenuUI* menuUI) {
	this->menuUI = menuUI;
}

MenuUIController::~MenuUIController() {
	delete menuUI;
}

bool MenuUIController::menu(sf::RenderWindow* window) {
	int choiceNumber = 0;
	bool exitingFlag = true;
	while (exitingFlag) {
		sf::Event* event = new sf::Event();
		while (window->pollEvent(*event)) {
			if (event->type == sf::Event::Closed) {
				window->close();
			}
			if (event->type == sf::Event::KeyPressed) {
				if (event->key.code == sf::Keyboard::Key::W ||
					event->key.code == sf::Keyboard::Key::Up) {
					choiceNumber -= 1;
					choiceNumber = (choiceNumber < 0) ? 2 : choiceNumber;
					menuUI->setActiveChoiceItem(choiceNumber);
				}
				if (event->key.code == sf::Keyboard::Key::S ||
					event->key.code == sf::Keyboard::Key::Down) {
					choiceNumber += 1;
					choiceNumber %= 3;
					menuUI->setActiveChoiceItem(choiceNumber);
				}
				if (event->key.code == sf::Keyboard::Key::Enter) {
					if (menuUI->getActiveChoiceItem() == ActiveChoiceItem::Start) {
						exitingFlag = false;
						break;
					}
					if (menuUI->getActiveChoiceItem() == ActiveChoiceItem::Quit) {
						window->close();
						exitingFlag = false;
						break;
					}
					if (menuUI->getActiveChoiceItem() == ActiveChoiceItem::About) {
						// —делать тут вывод о нас
					}
				}
			}
		}
		window->clear();
		menuUI->draw(window);
		window->display();
	}
	return true;
}