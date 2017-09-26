#include "My_macros.h"

int main()
{
	Character	*charac = new Character;
	std::string	choice;

	srand(time(NULL));
	// We're printing informations about the player.
	std::cout << "Name = " << charac->getName() << std::endl;
	std::cout << "Level = " << charac->getLevel() << std::endl;
	std::cout << "Max_HP = " << charac->getMaxHP() << std::endl;
	std::cout << "Act_HP = " << charac->getActHP() << std::endl;
	std::cout << "Max_Mana = " << charac->getMaxMana() << std::endl;
	std::cout << "Act_Mana = " << charac->getActMana() << std::endl;
	std::cout << "Min_DMG = " << charac->getMinDmg() << std::endl;
	std::cout << "Max_DMG = " << charac->getMaxDmg() << std::endl;
	// While the player has more than 0 HP, he's fighting a monster.
	while (charac->getActHP() > 0)
	{
		battle(charac);
		std::cout << std::endl;
		if (charac->getActHP() > 0)
		{
			// If the character is not dead, he's leveling up !
			std::cout << "--------LEVEL UP !---------" << std::endl;
			std::cout << "You won 5 max HP" << std::endl;
			charac->setLevel(charac->getLevel() + 1);
			charac->setMaxHP(charac->getMaxHP() + 5);
			charac->setActHP(charac->getActHP() + 5);
			std::cout << "Type one of the following to increase your stats" << std::endl;
			std::cout << "HP : Increase Max HP by additionnal 5 points" << std::endl;
			std::cout << "Mana : Increase your maximum Mana by 2 points" << std::endl;
			std::cout << "Damages (Default) : Increase your damages" << std::endl;
			std::cout << "If you want to save and quit, type EXIT" << std::endl;
			std::getline(std::cin, choice);
			if (choice == "HP")
			{
				charac->setMaxHP(charac->getMaxHP() + 5);
				charac->setActHP(charac->getActHP() + 5);
			}
			else if (choice == "Mana")
			{
				charac->setMaxMana(charac->getMaxHP() + 2);
				charac->setActMana(charac->getActMana() + 2);
			}
			else if (choice == "EXIT")
			{
				// Exiting the game : The lvup is done, and we're cleaning the ressources.
				charac->setMinDmg(charac->getMinDmg() + 1);
				charac->setMaxDmg(charac->getMaxDmg() + 2);
				save(charac);
				delete(charac);
				return (MY_SUCCESS);
			}
			else
			{
				charac->setMinDmg(charac->getMinDmg() + 1);
				charac->setMaxDmg(charac->getMaxDmg() + 2);
			}
			save(charac);
			std::cout << std::endl << "Game saved !" << std::endl;
		}
	}
	// The player is dead, we're leaving the game
	std::cout << "Game Over :(" << std::endl;
	std::getline(std::cin, choice);
	remove(SAVE_PATH);
	delete(charac);
	return MY_SUCCESS;
}