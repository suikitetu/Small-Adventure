#pragma once

#include <ctime>
#include "Charac.h"
#include "Enemy.h"
#include "Graphs.h"

#ifndef _MY_MACROS_H_
# define _MY_MACROS_H_

# define MY_ERROR 1
# define MY_SUCCESS 0

# define SAVE_PATH ".save.data"

/* Save file is defined as follow :
	
	Name\n
	Level\n
	Max_HP\n
	Act_HP\n
	Max_Mana\n
	Act_Mana\n
	Max_DMG\n
	Min_DMG\n
*/

# define LEVEL caracs[0]
# define MAX_HP caracs[1]
# define ACT_HP caracs[2]
# define MAX_MANA caracs[3]
# define ACT_MANA caracs[4]
# define MAX_DMG caracs[5]
# define MIN_DMG caracs[6]

// checking.cpp
int	my_check_nb(std::string str);

// battle.cpp
void		battle(Character *charac, My_Graph graph_interface, sf::RenderWindow& window);
std::string	attack(Character *charac, Enemy *opponent);
std::string	monster_attack(Character *charac, Enemy *opponent, std::string str);
std::string	fill_text(Character *charac, Enemy *opponent);

// Saving.cpp
int save(Character *charac);

#endif /*_MY_MACROS_H_*/