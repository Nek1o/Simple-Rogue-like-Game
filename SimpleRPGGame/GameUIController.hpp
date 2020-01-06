#pragma once
#include "GameUI.hpp"
#include "GameState.hpp"

class GameUIController {
protected:
	GameUI* gameUI;

public :
	GameUIController();

	~GameUIController();

	void game(sf::RenderWindow* window, GameState*);
};