#include "My_macros.h"

int main()
{
	Character	*charac = new Character;

	std::cout << "Name = " << charac->getName() << std::endl;
	std::cout << "Level = " << charac->getLevel() << std::endl;
	std::cout << "Max_HP = " << charac->getMaxHP() << std::endl;
	std::cout << "Act_HP = " << charac->getActHP() << std::endl;
	std::cout << "Max_Mana = " << charac->getMaxMana() << std::endl;
	std::cout << "Act_Mana = " << charac->getActMana() << std::endl;
	std::cout << "Min_DMG = " << charac->getMinDmg() << std::endl;
	std::cout << "Max_DMG = " << charac->getMaxDmg() << std::endl;
	return 0;
}