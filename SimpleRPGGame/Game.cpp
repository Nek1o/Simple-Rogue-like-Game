#include "Game.hpp"
#include "MenuUIController.hpp"


void Game::start(sf::RenderWindow* window, GameState* state) {
	state->setToMenu();
		
	MenuUIController* menuUIController = new MenuUIController();

	while (true) {
		// ������� ������� ����. � �� �� ����� �������������� ����� � ����� "�����"
		if (state->getCurrentState() == GameAction::Menu) {
			menuUIController->menu(window, state);
		}




		if (state->getCurrentState() == GameAction::Quit) {
			break;
		}
	}
}

//bool Game::menu(sf::RenderWindow* window) {}