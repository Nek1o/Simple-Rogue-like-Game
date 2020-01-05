#pragma once
#include "UI.hpp"
#include "Player.hpp"

class GameMenuFrame : public UI {
protected:
	Player* player; // для отображения всех показателей в меню тут тоже будет игрок
public:
	GameMenuFrame();

	~GameMenuFrame();

	void setFont(sf::Font*);

	void draw(sf::RenderWindow*);

	void update(Player* player);
};