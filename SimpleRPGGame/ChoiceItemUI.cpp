#include "ChoiceItemUI.hpp"
#include <iostream>

ChoiceItemUI::ChoiceItemUI() {
	chosen = false;
	text = new sf::Text();
}

ChoiceItemUI::~ChoiceItemUI() {
	std::cout << "ChoiceItemUIDestructor" << std::endl;
	delete text;
}

void ChoiceItemUI::setText(const std::string text) {
	this->text->setString(text);
}

sf::Text* ChoiceItemUI::getText() {
	return text;
}

bool ChoiceItemUI::isChosen() {
	return chosen;
}

void ChoiceItemUI::choose() {
	chosen = true;
}

void ChoiceItemUI::unchoose() {
	chosen = false;
}

void ChoiceItemUI::setFont(sf::Font* font) {
	text->setFont(*font);
}

void ChoiceItemUI::draw(sf::RenderWindow* window) {
	window->draw(*text);
}

void ChoiceItemUI::setPosition(double x, double y) {
	setPosX(x);
	setPosY(y);
	text->setPosition(x, y);
}