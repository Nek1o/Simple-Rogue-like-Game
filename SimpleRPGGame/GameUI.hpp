#pragma once
#include "UI.hpp"
#include "ChoiceItemUI.hpp"
#include "GameUICursor.hpp"
#include "Animation.hpp"

enum ActiveGameChoiceItem {
	AttackChoiceItem = 0, DefenseChoiceItem = 1, UseChoiceItem = 2, TalkChoiceItem = 3
};

class GameUI : public UI {
protected:
	sf::Text* currentHP;
	sf::Text* exp;
	sf::Text* currentExp;
	UICursor* cursor;
	std::vector<ChoiceItemUI*> choices;
	Animation* hpHeart;


public:
	GameUI();

	~GameUI();

	ActiveGameChoiceItem getActiveGameChoiceItem();

	void setActiveGameChoiceItem(int);

	void setFont(sf::Font*);

	void setCursorPosition();

	void draw(sf::RenderWindow*);
};