#pragma once
#include "MenuUI.hpp"
#include "GameState.hpp"

class MenuUIController {
protected:
	MenuUI* menuUI;
public:
	MenuUIController();

	MenuUIController(MenuUI*);

	~MenuUIController();

	void menu(sf::RenderWindow*, GameState*);
};