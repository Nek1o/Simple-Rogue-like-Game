#include "Player.hpp"
#include <vector>

Player::Player() : CombatEntity(), exp(0) {
	potions = std::vector<ItemPotion>();
};

Player::~Player() {}

void Player::draw(sf::RenderWindow* window) {
	if (isHit()) {
		// ������� ����� ����� �� ���������
		//setHit(false);
	}
}