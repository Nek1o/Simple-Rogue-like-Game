#include "Animation.hpp"
#include <iostream>

Animation::Animation(std::string* pathToFrames, int framesInAnimation) {
	this->framesInAnimation = framesInAnimation;
	timeToSkip = 0;
	currentFrame = 0;
	currentTimeToSkip = 0;
	for (size_t i = 0; i < framesInAnimation; i++) {
		sf::Image* image = new sf::Image();
		images.push_back(image);

		sf::Texture* texture = new sf::Texture();
		textures.push_back(texture);

		sf::Sprite* sprite = new sf::Sprite();
		sprites.push_back(sprite);
	}
	for (size_t i = 0; i < framesInAnimation; i++) {
		images[i]->loadFromFile(*pathToFrames + std::to_string(i) + ".gif");
		textures[i]->loadFromImage(*images[i]);
		sprites[i]->setTexture(*textures[i]);
	}
}

Animation::~Animation() {
	std::cout << "Animation" << std::endl;
	for (auto& image : images) {
		delete image;
	}
	for (auto& texture : textures) {
		delete texture;
	}
	for (auto& sprite : sprites) {
		delete sprite;
	}
}

void Animation::setPosition(double x, double y) {
	setPosX(x);
	setPosY(y);
	for (auto& sprite : sprites) {
		sprite->setPosition(getPosX(), getPosY());
		sprite->scale(1.5, 1.5);
	}
}

void Animation::setScale(double x, double y) {
	for (auto& sprite : sprites) {
		sprite->scale(x, y);
	}
}

void Animation::draw(sf::RenderWindow* window) {
	// ����� ��� ������� ��� ������ �������, ����� ��� ������ ����������
	// � ��� ��������� ����� � 60 ������, ��� ��� ��� �����������
	if (currentTimeToSkip % timeToSkip == 0) {
		currentFrame++;
	}
	currentTimeToSkip++;
	currentFrame %= framesInAnimation - 1;
	currentTimeToSkip %= timeToSkip;
	window->draw(*sprites[currentFrame]);
}

void Animation::setPathToFrames(std::string* pathToFrames) {
	this->pathToFrames = pathToFrames;
}

void Animation::setFramesInAnimation(int n) {
	framesInAnimation = n;
}

void Animation::setTimeToSkip(int n) {
	timeToSkip = n;
}

void Animation::setFont(sf::Font* font) {}