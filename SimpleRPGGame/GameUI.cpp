#include "GameUI.hpp"
#include "GameUICursor.hpp"

GameUI::GameUI() {
	gameUIMenuFrame = new GameUIMenuFrame();

	// Показатели здоровья и опыта
	currentHP = new sf::Text();
	currentHP->setString("hp"); 
	currentHP->setPosition(75, 465); 
	currentHP->setCharacterSize(20);

	currentExp = new sf::Text();
	currentExp->setString("exp"); 
	currentExp->setPosition(75, 465 + 30); 
	currentExp->setCharacterSize(20); 

	exp = new sf::Text();
	exp->setString("exp");
	exp->setPosition(28, 465 + 30);
	exp->setCharacterSize(20); 

	this->font = new sf::Font();
	this->font->loadFromFile("Resources/Fonts/ARCADECLASSIC.ttf");

	// Пункты для выбора
	GameUI::choices = std::vector<ChoiceItemUI*>();
	for (size_t i = 0; i < 4; i++) {
		ChoiceItemUI* choiceItemUI = new ChoiceItemUI();
		choiceItemUI->setCharacterSize(20);
		choices.push_back(choiceItemUI);
	}

	setFont(this->font);

	choices[0]->setText("Attack");
	choices[0]->setPosition(630, 465); 

	choices[1]->setText("Defend");
	choices[1]->setPosition(630, choices[0]->getPosY() + 30);

	choices[2]->setText("Use");
	choices[2]->setPosition(630, choices[1]->getPosY() + 30);

	choices[3]->setText("Talk");
	choices[3]->setPosition(630, choices[2]->getPosY() + 30);

	// Курсор
	std::string* pathToCursorFrames = new std::string();
	*pathToCursorFrames = "Resources/Textures/GameCursor/";
	cursor = new GameUICursor(choices[0], pathToCursorFrames, 1);
	cursor->setShiftValue(2.5);
	cursor->setAccelerationPercent(12);
	cursor->setTimeToSkip(2);
	setActiveGameChoiceItem(0);

	// Анимация сердца
	std::string* pathTohpHeart = new std::string();

	*pathTohpHeart = "Resources/Textures/hpHeart/";
	hpHeart = new Animation(pathTohpHeart, 12);
	hpHeart->setTimeToSkip(6); 

	hpHeart->setPosition(32, 467); 
	hpHeart->setScale(1, 1); 

	// Игрок
	player = new Player();
}

GameUI::~GameUI() {
	delete currentHP;
	delete currentExp;
	delete exp;
	delete cursor;
	delete hpHeart;
	for (auto& choice : choices) {
		delete choice;
	}
}

ActiveGameChoiceItem GameUI::getActiveGameChoiceItem() {
	for (size_t i = 0; i < choices.size(); i++) {
		if (choices[i]->isChosen()) {
			return (ActiveGameChoiceItem)i;
		}
	}
}

void GameUI::setActiveGameChoiceItem(int n) {
	for (auto& choice : choices) {
		choice->unchoose();
	}
	choices[n]->choose();
	setCursorPosition();
}

void GameUI::setCursorPosition() {
	for (auto& choice : choices) {
		if (choice->isChosen()) {
			cursor->setPosition(cursor->getPosX(), choice->getPosY() + 5);
		}
	}
}

void GameUI::setFont(sf::Font* font) {
	this->font = font;
	for (auto& choice : choices) {
		choice->setFont(this->font);
	}
	currentHP->setFont(*font);
	currentExp->setFont(*font);
	exp->setFont(*font);
}

void GameUI::setEnemy(CombatEntity* combatEntity) {
	enemy = combatEntity;
}

void GameUI::attackEnemy() {
	player->attack(enemy);
}

void GameUI::defendFromEnemy() {
	player->defend(enemy);
}

void GameUI::draw(sf::RenderWindow* window) {
	for (auto& choice : choices) {
		choice->draw(window);
	}
	window->draw(*currentHP);
	window->draw(*currentExp);
	window->draw(*exp);
	cursor->draw(window);
	hpHeart->draw(window);
	player->draw(window);
	if (enemy != NULL)
		enemy->draw(window);
	gameUIMenuFrame->draw(window);
}