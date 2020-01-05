#include <iostream>
#include <SFML/Graphics.hpp>

#include "TexturePool.hpp"
#include "MenuUIController.hpp"
#include "Game.hpp"

int main() {
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "Dungeon Escape");
	window.setFramerateLimit(60); 
	Game* game = new Game();
	GameState* state = new GameState();
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		game->start(&window, state);

		window.clear();
		//window.draw(weakMonsterSprite);
		window.display();
		if (state->getCurrentState() == GameAction::Quit) {
			window.close();
			break;
		}
	}



	system("pause");
	return 0;
}