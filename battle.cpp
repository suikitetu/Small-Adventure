#include "My_macros.h"

std::string	attack(Character *charac, Enemy *opponent)
{
	// Here, the player can deliver an attack to the monster
	std::string	choice;
	std::string	text = "";
	int			damages;
	int			inter = 0;

	damages = charac->getMinDmg() + (rand() % (charac->getMaxDmg() - charac->getMinDmg()));
	while (inter == 0)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && charac->getActMana() >= 5)
		{
			// We're using a fireball
			inter = 1;
			damages = damages * 3;
			opponent->setActHP(opponent->getActHP() - damages);
			text.append(charac->getName());
			text.append(" throws a Fireball and deals ");
			text.append(std::to_string(damages));
			text.append(" damages !\n");
			charac->setActMana(charac->getActMana() - 5);
			if (charac->getActMana() < 0)
				charac->setActMana(0);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && charac->getActMana() >= 10)
		{
			inter = 1;
			// We're using some healing
			damages = damages * 2;
			charac->setActHP(charac->getActHP() + damages);
			text.append(charac->getName());
			text.append(" cures his wounds with magic, and recovers ");
			text.append(std::to_string(damages));
			text.append(" HP\n");
			charac->setActMana(charac->getActMana() - 10);
			if (charac->getActMana() < 0)
				charac->setActMana(0);
		}
		else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) && charac->getActMana() < 5) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && charac->getActMana() < 10))
		{
			// We're warning the player that he didn't had enough mana
			text.append("Not enough Mana ! Using default attack instead...\n");
			inter = -1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) || inter == -1)
		{
			// We're using our Sword
			inter = 1;
			opponent->setActHP(opponent->getActHP() - damages);
			text.append(charac->getName());
			text.append(" swing out and deals ");
			text.append(std::to_string(damages));
			text.append(" damages !\n");
		}
	}
	return (text);
}

std::string	monster_attack(Character *charac, Enemy *opponent, std::string str)
{
	// Here, the monster is attacking us.
	int	attack_type = rand() % 2;
	int	damages;

	damages = opponent->getMinDmg() + (rand() % (opponent->getMaxDmg() - opponent->getMinDmg()));
	// He has a probablility to launch a special attack (Not printed for the player)
	if (attack_type == 1 && opponent->getActMana() > 2)
		damages = damages * 1.4;
	charac->setActHP(charac->getActHP() - damages);
	str.append("The ");
	str.append(opponent->getName());
	str.append(" strikes and deals ");
	str.append(std::to_string(damages));
	str.append(" damages. Ouch !\n");
	return (str);
}

std::string	fill_text(Character *charac, Enemy *opponent)
{
	std::string	text;

	// We're setting up what we'll need to print
	text = "";
	text.append("The monster has ");
	text.append(std::to_string(opponent->getActHP()));
	text.append("/");
	text.append(std::to_string(opponent->getMaxHP()));
	text.append(" HP remaining.\n");
	text.append(charac->getName());
	text.append(" has ");
	text.append(std::to_string(charac->getActHP()));
	text.append("/");
	text.append(std::to_string(charac->getMaxHP()));
	text.append(" HP remaining.\n");
	text.append(charac->getName());
	text.append(" has ");
	text.append(std::to_string(charac->getActMana()));
	text.append("/");
	text.append(std::to_string(charac->getMaxMana()));
	text.append(" Mana remaining.\n");
	text.append("Press A to launch a Fireball, Z to cast some heal, E to strike with your weapon.");
	return (text);
}

void	battle(Character *charac, My_Graph graph_interface, sf::RenderWindow& window)
{
	Enemy		*opponent = new Enemy(charac->getLevel());
	std::string	text;

	// The battle can only finish when someone reach 0 HP.
	while (opponent->getActHP() > 0 && charac->getActHP() > 0)
	{
		// We're creating the text, and drawing everything
		text = fill_text(charac, opponent);
		graph_interface.setText(text);
		window.clear();
		window.draw(graph_interface.sprite);
		window.draw(graph_interface.sprite2);
		window.draw(graph_interface.sprite3);
		window.draw(graph_interface.text);
		window.display();
		text = attack(charac, opponent);
		if (opponent->getActHP() > 0)
			text = monster_attack(charac, opponent, text);
		// Here, we're making sure the animations are played correctly
		graph_interface.setText(text);
		graph_interface.is_going = 1;
		while (graph_interface.is_going != 0)
		{
			if (graph_interface.is_going == 1 && graph_interface.anim_time < 2000)
				graph_interface.anim_time = graph_interface.anim_time + 1;
			else if (graph_interface.is_going == -1 && graph_interface.anim_time > 0)
				graph_interface.anim_time = graph_interface.anim_time - 1;
			if (graph_interface.anim_time == 2000)
				graph_interface.is_going = -1;	
			else if (graph_interface.anim_time == 0)
				graph_interface.is_going = 0;
			window.clear();
			window.draw(graph_interface.sprite);
			graph_interface.sprite2.setTextureRect(sf::IntRect(0 - (graph_interface.anim_time / 20), 0, 500, 500));
			graph_interface.sprite3.setTextureRect(sf::IntRect((graph_interface.anim_time / 20), 0, 500, 500));
			window.draw(graph_interface.sprite2);
			window.draw(graph_interface.sprite3);
			window.draw(graph_interface.text);
			window.display();
		}
		// We're making some Mana Regeneration
		if (charac->getActMana() < charac->getMaxMana())
			charac->setActMana(charac->getActMana() + 1);
	}
	delete(opponent);
}