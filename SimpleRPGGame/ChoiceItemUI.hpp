#pragma once
#include "UI.hpp"

class ChoiceItemUI : public UI {
protected:
	bool chosen;
	sf::Text* text;

public:
	ChoiceItemUI();

	~ChoiceItemUI();

	void setText(const std::string text);

	sf::Text* getText();

	bool isChosen();

	void choose();

	void unchoose();

	void setFont(sf::Font*);

	void draw(sf::RenderWindow*);

	void setPosition(double, double);

};