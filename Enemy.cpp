#include "My_macros.h"

Enemy::Enemy()
{

}

Enemy::Enemy(int difficulty)
{
	// We're creating a monster, corresponding to the player level.
	this->LEVEL = difficulty;
	this->MAX_HP = this->ACT_HP = difficulty * 5;
	this->MAX_MANA = this->ACT_MANA = difficulty * 2;
	this->MIN_DMG = difficulty * 2;
	this->MAX_DMG = difficulty * 3;
	this->name = "Slime";
}

Enemy::~Enemy()
{
}
