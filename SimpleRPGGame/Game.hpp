#pragma once
#include <SFML/Graphics.hpp>
#include "GameAction.hpp"
#include "GameState.hpp"

class Game {
private:
	int turns;
	int turnsToWin;
	GameState* state;

public:
	void start(sf::RenderWindow*);

	bool menu(sf::RenderWindow*);

	void findItem();

	void battle();
};