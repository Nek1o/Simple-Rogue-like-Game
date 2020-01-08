#pragma once
#include "UICursor.hpp"


class GameUICursor : public UICursor {
private:

public:

	GameUICursor(ChoiceItemUI*, std::string* pathToFrames, int framesInAnimation);

	~GameUICursor();

	void draw(sf::RenderWindow*);

	void setFont(sf::Font*);
};



