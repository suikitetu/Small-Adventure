#pragma once

#include "My_macros.h"

My_Graph::My_Graph()
{
	this->background = new sf::Texture();
	this->slime = new sf::Texture();
	this->knight = new sf::Texture();
	this->anim_time = 0;
	this->is_going = 0;
	// Loading textures, checking for errors.
	if (!this->background->loadFromFile("ressources/Background.png"))
		std::cerr << "Error while loading images !" << std::endl;
	if (!this->slime->loadFromFile("ressources/Slime.png", sf::IntRect(100, 0, 375, 375)))
		std::cerr << "Error while loading textures !" << std::endl;
	if (!this->knight->loadFromFile("ressources/Knight.png", sf::IntRect(0, 0, 375, 375)))
		std::cerr << "Error while loading textures !" << std::endl;
	if (!this->font.loadFromFile("ressources/contrast.ttf"))
		std::cerr << "Error while loading font !" << std::endl;
	// Loading text and defining sprites
	this->sprite.setTexture((*this->background));
	this->sprite2.setTexture((*this->slime));
	this->sprite2.setPosition(50, 265);
	this->sprite3.setTexture((*this->knight));
	this->sprite3.setPosition(350, 320);
	this->text.setFont(this->font);
	this->text.setCharacterSize(20);
}

void	My_Graph::setText(std::string str)
{
	// This function save text in the class, in order to print this text later
	this->text.setString(str);
}

My_Graph::~My_Graph()
{
}