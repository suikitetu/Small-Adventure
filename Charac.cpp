#include "My_macros.h"

int	Character::put_value(std::string val, int pos)
{
	// This function check if val is valid, and then save the value to the corresponding slot in this->caracs
	if (pos < 0 || !val.size())
		return (0);
	if (my_check_nb(val) == MY_SUCCESS)
	{
		this->caracs[6 - pos] = std::stoi(val);
		return (-1);
	}
	return (0);
}

Character::Character()
{
	std::string		tmp = "";
	std::ifstream	file(SAVE_PATH, std::ios::in);
	int				no_err = 6;

	if (file)
	{
		// A save file has been found. We're checking the informations, and saving them.
		std::getline(file, tmp);
		if (!tmp.size())
			no_err = no_err - 8;
		this->name = tmp;
		std::getline(file, tmp);
		no_err = no_err + this->put_value(tmp, no_err);
		std::getline(file, tmp);
		no_err = no_err + this->put_value(tmp, no_err);
		std::getline(file, tmp);
		no_err = no_err + this->put_value(tmp, no_err);
		std::getline(file, tmp);
		no_err = no_err + this->put_value(tmp, no_err);
		std::getline(file, tmp);
		no_err = no_err + this->put_value(tmp, no_err);
		std::getline(file, tmp);
		no_err = no_err + this->put_value(tmp, no_err);
	}
	std::getline(file, tmp);
	no_err = no_err + this->put_value(tmp, no_err);
	if (no_err != -1)
	{
		// Save file couldn't be opened, or the informations were incorrect. We're creating a new character.
		std::cout << "No valid save file found. Creating a new character..." << std::endl;
		// First, we're asking the player to enter the name of his character.
		std::cout << "Please enter your name, Hero." << std::endl;
		while (!tmp.size())
			std::getline(std::cin, tmp);
		// Then, we're creating the character with the given stats.
		this->name = tmp;
		this->LEVEL = 1;
		this->MAX_HP = 30;
		this->ACT_HP = 30;
		this->MAX_MANA = 10;
		this->ACT_MANA = 10;
		this->MIN_DMG = 2;
		this->MAX_DMG = 6;
	}
}

Character::~Character()
{
}
