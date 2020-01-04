#include "TexturePool.hpp"
#include <string>

const int WEAK_MONSTER_AMOUNT = 3;
const int STRONG_MONSTER_AMOUNT = 1;

TexturePool::TexturePool() {
	weakMonsterTextures = vector<Texture*>();
	strongMonsterTextures = vector<Texture*>();
	healingPotionTextures = vector<Texture*>();
	firePotionTextures = vector<Texture*>();
	freezingPotionTextures = vector<Texture*>();
	weaponTextures = vector<Texture*>();
	shieldTextures = vector<Texture*>();
}

TexturePool::~TexturePool() {
	for (auto& i : weakMonsterTextures) {
		delete i;
	}
	for (auto& i : strongMonsterTextures) {
		delete i;
	}
	for (auto& i : healingPotionTextures) {
		delete i;
	}
	for (auto& i : firePotionTextures) {
		delete i;
	}
	for (auto& i : freezingPotionTextures) {
		delete i;
	}
	for (auto& i : weaponTextures) {
		delete i;
	}
	for (auto& i : shieldTextures) {
		delete i;
	}

	/*for (auto i = weakMonsterTextures.begin(); i != weakMonsterTextures.end(); i++) {
		delete *i;
	}
	for (auto i = strongMonsterTextures.begin(); i != strongMonsterTextures.end(); i++) {
		delete *i;
	}
	for (auto i = healingPotionTextures.begin(); i != healingPotionTextures.end(); i++) {
		delete *i;
	}
	for (auto i = firePotionTextures.begin(); i != firePotionTextures.end(); i++) {
		delete *i;
	}
	for (auto i = freezingPotionTextures.begin(); i != freezingPotionTextures.end(); i++) {
		delete *i;
	}
	for (auto i = weaponTextures.begin(); i != weaponTextures.end(); i++) {
		delete *i;
	}
	for (auto i = shieldTextures.begin(); i != shieldTextures.end(); i++) {
		delete *i;
	}*/
}

// Метод поместить в конструктор
void TexturePool::loadWeakMonsterTextures() {
	std::string pathString = "\\Resources\\Textures\\w";
	std::string pngString = ".png";

	for (size_t i = 1; i <= WEAK_MONSTER_AMOUNT; i++) {
		Texture *texture = new Texture();
		texture->loadFromFile(pathString + std::to_string(i) + pngString);
		weakMonsterTextures.push_back(texture);
	}

	/*Texture *texture = new Texture();
	texture->loadFromFile("C:\\Users\\Nikita\\Desktop\\Textures\\w3.png");
	weakMonsterTextures.push_back(texture);*/
}

Texture* TexturePool::getWeakMonsterTexture() {
	int n = rand() % weakMonsterTextures.size();
	return weakMonsterTextures[n];
}

Texture* TexturePool::getWeakMonsterTexture(int n) {
	return weakMonsterTextures[n];
}

