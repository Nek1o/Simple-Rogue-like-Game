#include <iostream>
#include <SFML/Graphics.hpp>

#include "TexturePool.hpp"
#include "MenuUIController.hpp"
#include "Game.hpp"

int main() {
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "Dungeon Escape");
	window.setFramerateLimit(60);

	Game* game = new Game();
	
	game->start(&window);

	delete game;
	system("pause");
	return 0;
}