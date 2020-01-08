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

	bool isStartGame();

	void setToMenu();

	void setToBattle();

	void setToFindItem();

	void setToSkip();

	void setToQuit();

	void setToStartGame();

	void setToNextTurn();

	GameAction getCurrentState();

	void clearStates();

	/*template <class T>
	bool is(T t);

	template <class T>
	void set(T t);*/
};