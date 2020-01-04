#include "Entity.hpp"


Entity::Entity() : posX(0), posY(0) {};

Entity::~Entity() {
	delete image;
	delete texture;
	delete sprite;

}

void Entity::setPosX(int x) {
	posX = x;
}

void Entity::setPosY(int y) {
	posY = y;
}

int Entity::getPosX() {
	return posX;
}

int Entity::getPosY() {
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