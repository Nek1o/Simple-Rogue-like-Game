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
	while (exitingFlag) {
		sf::Event* event = new sf::Event();

		while (window->pollEvent(*event)) {
			if (event->type == sf::Event::Closed) {
				window->close();
			}

			// тут вся мошня
		}

		window->clear();
		gameUI->draw(window);
		window->display();
	}

	
}