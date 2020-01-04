#pragma once
#include <SFML/Graphics.hpp>

class Entity {
private:
	int posX;
	int posY;
	sf::Image* image;
	sf::Texture* texture;
	sf::Sprite* sprite;

public:
	Entity();

	virtual ~Entity();

	void setPosX(int);

	void setPosY(int);

	virtual int getPosX();

	virtual int getPosY();

	void setImage(sf::Image*);

	void setTexture(sf::Texture*);

	void setSprite(sf::Sprite*);

	virtual void draw(sf::RenderWindow*) = 0;

	sf::Image* getImage();

	sf::Texture* getTexture();

	sf::Sprite* getSprite();
};
