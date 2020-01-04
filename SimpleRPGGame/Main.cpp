#include <iostream>
//#include <Windows.h>
#include <SFML/Graphics.hpp>

#include "TexturePool.hpp"
#include "MenuUIController.hpp"

int main() {
	/*HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);*/
	//FreeConsole();
	sf::RenderWindow window(sf::VideoMode(800, 600), "Dungeon Escape");
	MenuUIController* menuUIController = new MenuUIController();
	bool isMenuDone = false;
	window.setFramerateLimit(60);
	/*TexturePool texturePool = TexturePool(); 
	texturePool.loadWeakMonsterTextures();
	sf::Sprite weakMonsterSprite(*texturePool.getWeakMonsterTexture(2));*/

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		if (!isMenuDone) {
			isMenuDone = menuUIController->menu(&window);
		}

		window.clear();
		//window.draw(weakMonsterSprite);
		window.display();
	}



	system("pause");
	return 0;
}