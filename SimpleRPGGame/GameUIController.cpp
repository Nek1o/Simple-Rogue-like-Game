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
			// Проверяем GameState, в зависимости от него вызываем методы у gameUI
			// В GameUI сделать методы для врагов и предметов. 
			// тут вся мошня
		}

		window->clear();
		gameUI->draw(window);
		window->display();
	}

	
}