#pragma once
#include "UI.hpp"
#include "Player.hpp"

// вставить сюда текущий опыт и текущее здоровье

class GameUIMenuFrame : public UI {
protected:
	Player* player; // для отображения всех показателей в меню тут тоже будет игрок
public:
	GameUIMenuFrame();

	~GameUIMenuFrame();

	void setFont(sf::Font*);

	void draw(sf::RenderWindow*);

	void update(Player* player);
};