#include "CombatEntity.hpp"

CombatEntity::CombatEntity() : Entity(), hp(0), attackValue(0), defenseValue(0) {};

CombatEntity::CombatEntity(int hp, int attackValue, int defenseValue) :
	hp(hp), attackValue(attackValue), defenseValue(defenseValue) {};

int CombatEntity::getHP() {
	return hp;
}

void CombatEntity::setHP(int hp) {
	this->hp = hp;
}

int CombatEntity::getAttackValue() {
	return attackValue;
}

void CombatEntity::setAttackValue(int attackValue) {
	this->attackValue = attackValue;
}

int CombatEntity::getDefenseValue() {
	return defenseValue;
}

void CombatEntity::setDefenseValue(int defenseValue) {
	this->defenseValue = defenseValue;
}

void CombatEntity::attack(CombatEntity* combatEntity) {

}

void CombatEntity::defend(CombatEntity* combatEntity) {

}

bool CombatEntity::isAlive() {
	return hp > 0 ? true : false;
}