#include "MenuUIController.hpp"
#include "GameAction.hpp"

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


// пусть возвращает перечисление GameAction
// переделать после того, как остальной функционал будет готов
void MenuUIController::menu(sf::RenderWindow* window, GameState* state) {
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
					if (menuUI->getActiveChoiceItem() == ActiveChoiceItem::StartChoiceItem) {
						exitingFlag = false;
						state->clearStates();
						break;
					}
					if (menuUI->getActiveChoiceItem() == ActiveChoiceItem::QuitChoiceItem) {
						window->close();
						exitingFlag = false;
						state->setToQuit();
						break;
					}
					if (menuUI->getActiveChoiceItem() == ActiveChoiceItem::AboutChoiceItem) {
						// Сделать тут вывод о нас
					}
				}
			}
		}
		window->clear();
		menuUI->draw(window);
		window->display();
	}
}