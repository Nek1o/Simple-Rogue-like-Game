#pragma once
#include "UI.hpp"
#include "ChoiceItemUI.hpp"

enum ActiveChoiceItem {
	Start = 0, About = 1,  Quit = 2
};

class MenuUI : public UI {
protected:
	sf::Text* gameName;
	sf::Sprite* cursor;
	std::vector<ChoiceItemUI*> choices;


public:
	MenuUI();

	~MenuUI();

	ActiveChoiceItem getActiveChoiceItem();

	void setActiveChoiceItem(int);

	void setFont(sf::Font*);

	void setCursorPosition();

	void draw(sf::RenderWindow*);
};