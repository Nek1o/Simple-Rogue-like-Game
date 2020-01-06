#include "Entity.hpp"
#include <iostream>

Entity::Entity() : posX(0), posY(0) {};

Entity::~Entity() {
	std::cout << "Entity destructor" << std::endl;
	delete image;
	delete texture;
	delete sprite;

}

void Entity::setPosX(double x) {
	posX = x;
}

void Entity::setPosY(double y) {
	posY = y;
}

double Entity::getPosX() {
	return posX;
}

double Entity::getPosY() {
	return posY;
}

void Entity::setImage(sf::Image* image) {
	this->image = image;
}

void Entity::setTexture(sf::Texture* texture) {
	this->texture = texture;
}

void Entity::setSprite(sf::Sprite* sprite) {
	this->sprite = sprite;
}

sf::Image* Entity::getImage() {
	return image;
}

sf::Texture* Entity::getTexture() {
	return texture;
}

sf::Sprite* Entity::getSprite() {
	return sprite;
}