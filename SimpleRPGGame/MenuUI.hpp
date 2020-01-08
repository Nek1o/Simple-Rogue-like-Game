#pragma once
#include "UI.hpp"
#include "ChoiceItemUI.hpp"
#include "MenuUICursor.hpp"
#include "Animation.hpp"

enum ActiveChoiceItem {
	StartChoiceItem = 0, AboutChoiceItem = 1,  QuitChoiceItem = 2
};

class MenuUI : public UI {
protected:
	sf::Text* gameName;
	UICursor* cursor;
	std::vector<ChoiceItemUI*> choices;
	Animation* campfire;

public:
	MenuUI();

	~MenuUI();

	ActiveChoiceItem getActiveChoiceItem();

	void setActiveChoiceItem(int);

	void setFont(sf::Font*);

	void setCursorPosition();

	void draw(sf::RenderWindow*);
};