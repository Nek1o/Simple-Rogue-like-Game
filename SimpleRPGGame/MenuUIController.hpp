#pragma once
#include "MenuUI.hpp"

class MenuUIController {
protected:
	MenuUI* menuUI;
public:
	MenuUIController();

	MenuUIController(MenuUI*);

	~MenuUIController();

	bool menu(sf::RenderWindow*);
};