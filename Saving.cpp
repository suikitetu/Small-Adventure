#include "My_macros.h"

int	save(Character *charac)
{
	remove(SAVE_PATH);
	std::ofstream	file(SAVE_PATH);
	file << charac->getName() << std::endl;
	if (!file)
	{
		// Error while creating the file. We're aborting the save, and warning the user.
		std::cout << "Ow ! Something wrong happened while saving the game :(" << std::endl;
		return (MY_ERROR);
	}
	else
	{
		// The informations are being saved in the save file
		file << std::to_string(charac->getLevel()) << std::endl;
		file << std::to_string(charac->getMaxHP()) << std::endl;
		file << std::to_string(charac->getActHP()) << std::endl;
		file << std::to_string(charac->getMaxMana()) << std::endl;
		file << std::to_string(charac->getActMana()) << std::endl;
		file << std::to_string(charac->getMaxDmg()) << std::endl;
		file << std::to_string(charac->getMinDmg()) << std::endl;
		file.close();
	}
	return (MY_SUCCESS);
}