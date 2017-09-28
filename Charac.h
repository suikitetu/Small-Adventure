#pragma once

#ifndef _MY_CHARACTER_
# define _MY_CHARACTER_

#include <iostream>
#include <string>
#include <fstream>

class Character
{
public:
	Character();
	~Character();

	// Getters
	const std::string	getName() const		{ return(this->name); };
	const int			getLevel() const	{ return(this->caracs[0]); }
	const int			getMaxHP() const	{ return(this->caracs[1]); }
	const int			getActHP() const	{ return(this->caracs[2]); }
	const int			getMaxMana() const	{ return(this->caracs[3]); }
	const int			getActMana() const	{ return(this->caracs[4]); }
	const int			getMaxDmg() const	{ return(this->caracs[5]); }
	const int			getMinDmg() const	{ return(this->caracs[6]); }

	// Setters
	void				setName(const std::string s) { this->name = s; };
	void				setLevel(const int v) { this->caracs[0] = v; };
	void				setMaxHP(const int v) { this->caracs[1] = v; };
	void				setActHP(const int v) { this->caracs[2] = v; };
	void				setMaxMana(const int v) { this->caracs[3] = v; };
	void				setActMana(const int v) { this->caracs[4] = v; };
	void				setMaxDmg(const int v) { this->caracs[5] = v; };
	void				setMinDmg(const int v) { this->caracs[6] = v; };
private:
	std::string	name;
	int			caracs[7];

	/*	0 = level
		1 = Max_HP
		2 = Act_HP
		3 = Max_Mana
		4 = Act_Mana
		5 = Max_DMG
		6 = Min_DMG
	*/

	int		put_value(std::string val, int pos);
};

#endif /*_MY_CHARACTER_*/
