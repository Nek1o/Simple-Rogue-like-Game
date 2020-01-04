#pragma once


class Game {
private:
	int turnsAmount;
	int turnsToWin;

public:
	void findItem();

	void battle();

	void start();
};