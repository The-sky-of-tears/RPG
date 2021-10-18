#include "Manager.h"

void Manager::startNewGame()
{
	std::cout << "Welcome to the Hell!\n" << 
		"Enter your name: ";

	std::string new_name;

	std::cin >> new_name;

	current_player = new Player(new_name);

	current_map = new Map;
}

void Manager::continueGame()
{

}

void Manager::startFight(npc::Enemy* current_enemy)
{
	
	//test segment
	current_player->showCurrentState();
	std::cout << " VS ";
	current_enemy->showCurrentState();
	std::cout << std::endl;

	bool player_turn = 1;

	while (1)
	{
		if (player_turn)
		{
			current_enemy->defence(current_player->attack());
			current_enemy->showCurrentState();
			std::cout << std::endl;

			player_turn = 0;

			if (!current_enemy->isAlive())
			{
				std::cout << "Easy win! GG WP! \n";
				break;
			}
		}
		else
		{
			current_player->defence(current_enemy->attack());
			current_player->showCurrentState();
			std::cout << std::endl;

			player_turn = 1;

			if (!current_player->isAlive())
			{
				std::cout << "Noob, delete the game! ^_^ \n";
				break;
			}
		}
	}
}

void Manager::startTrade()
{

}

void Manager::startHeal()
{

}

void Manager::movePlayer()
{

}

void Manager::saveGame()
{
	
}

void Manager::exit()
{

}

Manager::~Manager()
{
	delete current_map;
	delete current_player;
}