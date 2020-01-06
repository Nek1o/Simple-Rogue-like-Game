#include "Game.hpp"
#include "MenuUIController.hpp"
#include "GameUIController.hpp"
#include <stdlib.h>

void Game::start(sf::RenderWindow* window) {
	state = new GameState();
	state->setToMenu();
		
	
	while (window->isOpen()) {
		sf::Event event;
		while (window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window->close();
			}
		}

		// Сначала выводим меню. В нём же будет обрабатываться выход и пункт "Ебаут"
		if (state->getCurrentState() == GameAction::Menu) {
			MenuUIController* menuUIController = new MenuUIController();
			menuUIController->menu(window, state);
			delete menuUIController;
		}

		/*for (size_t i = 0; i < 10; i++) {
			int randomScenario = rand() % 5;
			if (randomScenario == 0) {

			}
		}*/
		if (state->getCurrentState() == GameAction::StartGame) {
			GameUIController* gameUIController = new GameUIController();
			gameUIController->game(window, state);
		}


		// Выходим из цикла и закрываем окно
		if (state->getCurrentState() == GameAction::Quit) {
			window->close();
			break;
		}

		window->clear();
		window->display();
	}
	delete state;
}

//bool Game::menu(sf::RenderWindow* window) {}