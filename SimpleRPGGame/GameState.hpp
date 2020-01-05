#pragma once
#include "GameAction.hpp"
#include <vector>

class GameState {
private:
	bool menu;
	bool battle;
	bool foundItem;
	bool skip; // ?
	bool quit;

	std::vector<bool>* states;

public:
	GameState();

	bool isMenu();

	bool isBattle();

	bool isFindItem();

	bool isSkip();

	bool isQuit();

	void setToMenu();

	void setToBattle();

	void setToFindItem();

	void setToSkip();

	void setToQuit();

	GameAction getCurrentState();

	void clearStates();
};