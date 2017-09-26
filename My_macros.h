#pragma once

#include "Charac.h"

#ifndef _MY_MACROS_H_
# define _MY_MACROS_H_

# define MY_ERROR 1
# define MY_SUCCESS 0

# define SAVE_PATH "../assets/save.data"

/* Le format du fichier de sauvegarde est defini comme suit :
	
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


#endif /*_MY_MACROS_H_*/