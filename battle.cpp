#include "My_macros.h"

void	attack(Character *charac, Enemy *opponent)
{
	// Here, the player can deliver an attack to the monster
	std::string	choice;
	int			damages;

	std::cout << "How do you wish to attack ?" << std::endl;
	std::cout << "Fireball : Launch a Fireball. Cost 5 mana, Tremendous damages." << std::endl;
	std::cout << "Heal : Heal yourself with the Light Magic. Cost 10 mana." << std::endl;
	std::cout << "Attack : Default choice. Cost 0 mana, deals little damages." << std::endl;
	getline(std::cin, choice);
	damages = charac->getMinDmg() + (rand() % (charac->getMaxDmg() - charac->getMinDmg()));
	if ((choice == "Fireball" || choice == "fireball" || choice == "FIREBALL") && charac->getActMana() >= 5)
	{
		// We're using a fireball
		damages = damages * 3;
		opponent->setActHP(opponent->getActHP() - damages);
		std::cout << charac->getName() << " throws a Fireball and deals " << damages << " damages !" << std::endl;
		charac->setActMana(charac->getActMana() - 5);
		if (charac->getActMana() < 0)
			charac->setActMana(0);
	}
	else if ((choice == "Heal" || choice == "heal" || choice == "HEAL") && charac->getActMana() >= 10)
	{
		// We're using some healing
		damages = damages * 2;
		charac->setActHP(charac->getActHP() + damages);
		std::cout << charac->getName() << " cures his wounds with magic, and recovers " << damages << " HP" << std::endl;
		charac->setActMana(charac->getActMana() - 10);
		if (charac->getActMana() < 0)
			charac->setActMana(0);
	}
	else
	{
		// We're using our Sword
		opponent->setActHP(opponent->getActHP() - damages);
		std::cout << charac->getName() << " swing out and deals " << damages << " damages !" << std::endl;
	}
}

void	monster_attack(Character *charac, Enemy *opponent)
{
	int	attack_type = rand() % 2;
	int	damages;

	damages = opponent->getMinDmg() + (rand() % (opponent->getMaxDmg() - opponent->getMinDmg()));

	if (attack_type == 1 && opponent->getActMana() > 2)
		damages = damages * 1.4;
	charac->setActHP(charac->getActHP() - damages);
	std::cout << "The " << opponent->getName() << " strikes and deals " << damages << " damages. Ouch !" << std::endl;
}

void	battle(Character *charac)
{
	Enemy	*opponent = new Enemy(charac->getLevel());

	// The battle can only finish when someone reach 0 HP.
	while (opponent->getActHP() > 0 && charac->getActHP() > 0)
	{
		std::cout << "The monster has " << opponent->getActHP() << "/" << opponent->getMaxHP() << " HP remaining." << std::endl;
		std::cout << charac->getName() << " has " << charac->getActHP() << "/" << charac->getMaxHP() << " HP remaining." << std::endl;
		std::cout << charac->getName() << " has " << charac->getActMana() << "/" << charac->getMaxMana() << " Mana remaining." << std::endl;
		std::cout << std::endl;
		attack(charac, opponent);
		if (opponent->getActHP() > 0)
			monster_attack(charac, opponent);
		if (charac->getActMana() < charac->getMaxMana())
			charac->setActMana(charac->getActMana() + 1);
	}
	delete(opponent);
}