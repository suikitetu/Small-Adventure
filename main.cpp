#include "My_macros.h"

int main()
{
	sf::RenderWindow	*window = new sf::RenderWindow(sf::VideoMode(800, 600), "Small Adventure");
	Character	*charac = new Character;
	My_Graph	graph_interface;
	std::string	choice;
	int			inter;

	// We're making sure random is respected.
	srand((unsigned int)time(NULL));
	// We're preventing the keys from being blocked
	window->setKeyRepeatEnabled(false);
	// While the player has more than 0 HP, he's fighting a monster.
	while (charac->getActHP() > 0 && window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
			if (event.type == sf::Event::Closed)
				window->close();
		// A battle turn is done.
		battle(charac, graph_interface, *window);
		if (charac->getActHP() > 0)
		{
			// If the character is not dead, he's leveling up !
			inter = 0;
			graph_interface.setText("---LEVEL UP !!!\nPress one of the followings to choose your uppgrade :\nQ : More HP - S : More Mana - D : More Damages\nIf you want to exit, press F");
			window->clear();
			window->draw(graph_interface.sprite);
			window->draw(graph_interface.sprite3);
			window->draw(graph_interface.text);
			window->display();
			charac->setLevel(charac->getLevel() + 1);
			charac->setMaxHP(charac->getMaxHP() + 5);
			charac->setActHP(charac->getActHP() + 5);
			// The player can choose here wich uppgrade he prefers.
			while (inter == 0)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
				{
					inter = 1;
					charac->setMaxHP(charac->getMaxHP() + 15);
					charac->setActHP(charac->getActHP() + 15);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					inter = 1;
					charac->setMaxMana(charac->getMaxMana() + 10);
					charac->setActMana(charac->getActMana() + 10);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
				{
					inter = 1;
					// Exiting the game : The lvup is done, and we're cleaning the ressources.
					charac->setMinDmg(charac->getMinDmg() + 1);
					charac->setMaxDmg(charac->getMaxDmg() + 2);
					save(charac);
					delete(charac);
					return (MY_SUCCESS);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					inter = 1;
					charac->setMinDmg(charac->getMinDmg() + 1);
					charac->setMaxDmg(charac->getMaxDmg() + 2);
				}
			}
			// We're saving the game, in case of crash, or if the player needs to leave.
			save(charac);
		}

	}
	// The player is either dead, or wants to leave the game
	if (charac->getActHP() <= 0)
	{
		// The player is dead : We're informing him, and deleting the save file.
		graph_interface.setText("Oh, you died....Better luck next time !\nPress R to leave the game :)");
		window->clear();
		window->draw(graph_interface.sprite);
		window->draw(graph_interface.sprite2);
		window->draw(graph_interface.text);
		window->display();
		remove(SAVE_PATH);
		while (!sf::Keyboard::isKeyPressed(sf::Keyboard::R));
	}
	// We're cleaning the ressources
	delete(charac);
	return MY_SUCCESS;
}