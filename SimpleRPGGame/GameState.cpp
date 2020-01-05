#include "GameState.hpp"

GameState::GameState() {
	states = new std::vector<bool>();
	for (size_t i = 0; i < 9; i++) {
		states->push_back(false);
	}
}

bool GameState::isBattle() {
	return states->at(GameAction::Battle);
}

bool GameState::isMenu() {
	return states->at(GameAction::Menu);
}

bool GameState::isFindItem() {
	return states->at(GameAction::FindItem);
}

bool GameState::isSkip() {
	return states->at(GameAction::SkipTurn);
}

bool GameState::isQuit() {
	return states->at(GameAction::Quit);
}

void GameState::setToBattle() {
	for (size_t i = 0; i < states->size(); i++) {
		states->at(i) = false;
	}
	states->at(GameAction::Battle) = true;
}

void GameState::setToMenu() {
	for (size_t i = 0; i < states->size(); i++) {
		states->at(i) = false;
	}
	states->at(GameAction::Menu) = true;
}

void GameState::setToSkip() {
	for (size_t i = 0; i < states->size(); i++) {
		states->at(i) = false;
	}
	states->at(GameAction::SkipTurn) = true;
}

void GameState::setToFindItem() {
	for (size_t i = 0; i < states->size(); i++) {
		states->at(i) = false;
	}
	states->at(GameAction::FindItem) = true;
}

GameAction GameState::getCurrentState() {
	for (size_t i = 0; i < states->size(); i++) {
		if (states->at(i)) {
			return (GameAction)i;
		}
	}
}

void GameState::clearStates() {
	for (size_t i = 0; i < states->size(); i++) {
		states->at(i) = false;
	}
}

void GameState::setToQuit() {
	for (size_t i = 0; i < states->size(); i++) {
		states->at(i) = false;
	}
	states->at(GameAction::Quit) = true;
}