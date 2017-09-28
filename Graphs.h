#pragma once

#include <SFML/Graphics.hpp>

#ifndef _MY_GRAPHS_H_
# define _MY_GRAPHS_H_

class My_Graph
{
public:
	My_Graph();
	~My_Graph();

	// Setters
	void	My_Graph::setText(std::string str);

	sf::Texture	*background;
	sf::Texture	*slime;
	sf::Texture	*knight;
	sf::Sprite	sprite;
	sf::Sprite	sprite2;
	sf::Sprite	sprite3;
	sf::Text	 text;
	sf::Font	 font;

	// This number will help us to make the characters attack correctly.
	float			anim_time;
	int			is_going;
private:

};



#endif /*_MY_GRAPHS_H_*/