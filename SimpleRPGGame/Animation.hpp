#pragma once
#include "UI.hpp"

class Animation : public UI {
protected:
	int currentFrame;
	int framesInAnimation;
	int timeToSkip;
	int currentTimeToSkip;
	std::vector<sf::Image*> images;
	std::vector<sf::Texture*> textures;
	std::vector<sf::Sprite*> sprites;
	std::string* pathToFrames;

public:
	Animation(std::string*, int);

	~Animation();

	void setPosition(double, double);

	void draw(sf::RenderWindow*);

	void setFont(sf::Font*);

	void setScale(double, double);

	void setFramesInAnimation(int);

	void setTimeToSkip(int);

	void setPathToFrames(std::string*);
};