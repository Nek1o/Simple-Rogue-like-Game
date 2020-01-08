#pragma once
#include "UI.hpp"
#include "Player.hpp"

// �������� ���� ������� ���� � ������� ��������

class GameUIMenuFrame : public UI {
protected:
	Player* player; // ��� ����������� ���� ����������� � ���� ��� ���� ����� �����
public:
	GameUIMenuFrame();

	~GameUIMenuFrame();

	void setFont(sf::Font*);

	void draw(sf::RenderWindow*);

	void update(Player* player);
};