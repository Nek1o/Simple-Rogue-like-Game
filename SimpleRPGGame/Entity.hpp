#pragma once
#include <SFML/Graphics.hpp>

class Entity {
private:
	double posX;
	double posY;
	sf::Image* image;
	sf::Texture* texture;
	sf::Sprite* sprite;

public:
	Entity();

	virtual ~Entity();

	virtual void setPosX(double);

	virtual void setPosY(double);

	virtual double getPosX();

	virtual double getPosY();

	void setImage(sf::Image*);

	void setTexture(sf::Texture*);

	void setSprite(sf::Sprite*);

	virtual void draw(sf::RenderWindow*) = 0;

	sf::Image* getImage();

	sf::Texture* getTexture();

	sf::Sprite* getSprite();
};
