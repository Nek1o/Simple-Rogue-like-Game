#pragma once
#include "GameUIController.hpp"

GameUIController::GameUIController() {
	gameUI = new GameUI();
}

GameUIController::~GameUIController() {
	delete gameUI;
}

void GameUIController::game(sf::RenderWindow* window, GameState* state) {
	bool exitingFlag = true;
	int choiceNumber = 0;
	while (exitingFlag) {
		sf::Event* event = new sf::Event();
		while (window->pollEvent(*event)) {
			if (event->type == sf::Event::Closed) {
				window->close();
			}
			if (state->getCurrentState() == GameAction::Battle) {
				if (event->type == sf::Event::KeyPressed) {
					if (event->key.code == sf::Keyboard::W ||
						event->key.code == sf::Keyboard::Up) {
						choiceNumber--;
						choiceNumber = (choiceNumber < 0) ? 3 : choiceNumber;
						gameUI->setActiveGameChoiceItem(choiceNumber);
					}
					if (event->key.code == sf::Keyboard::S ||
						event->key.code == sf::Keyboard::Down) {
						choiceNumber++;
						choiceNumber %= 4;
						gameUI->setActiveGameChoiceItem(choiceNumber);
					}
					if (event->key.code == sf::Keyboard::Enter) {
						if (gameUI->getActiveGameChoiceItem() == 0) {
							gameUI->attackEnemy();
						}
						if (gameUI->getActiveGameChoiceItem() == 1) {
							gameUI->defendFromEnemy();
						}
						if (gameUI->getActiveGameChoiceItem() == 2) {
							// use item
						}
						if (gameUI->getActiveGameChoiceItem() == 3) {
							// talk
						}

					}
				}
			}
			// Проверяем GameState, в зависимости от него вызываем методы у gameUI
			// В GameUI сделать методы для врагов и предметов. 
			// тут вся мошня
		}

		window->clear();
		gameUI->draw(window);
		window->display();
	}

	
}