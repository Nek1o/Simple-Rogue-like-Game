#pragma once
#include <SFML/Graphics.hpp>
#include "GameAction.hpp"
#include "GameState.hpp"

class Game {
private:
	int turns;
	int turnsToWin;

public:
	void start(sf::RenderWindow*, GameState*);

	bool menu(sf::RenderWindow*);

	void findItem();

	void battle();
};