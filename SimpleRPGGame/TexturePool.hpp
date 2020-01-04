#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

using std::vector;
using sf::Texture;

class TexturePool {
private:
	vector<Texture*> weakMonsterTextures;
	vector<Texture*> strongMonsterTextures;
	vector<Texture*> healingPotionTextures;
	vector<Texture*> firePotionTextures;
	vector<Texture*> freezingPotionTextures;
	vector<Texture*> weaponTextures;
	vector<Texture*> shieldTextures;

public:
	TexturePool();
	~TexturePool();

	void loadWeakMonsterTextures();

	Texture* getWeakMonsterTexture();
	Texture* getWeakMonsterTexture(int n);

};