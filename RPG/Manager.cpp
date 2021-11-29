#pragma once
#include "Manager.h"
#include "DisplayMap.h"

void Manager::startNewGame()
{
	std::cout << "Welcome to the Game!\n" << 
		"Enter your name: ";

	std::string new_name;

	std::cin >> new_name;

	Player* current_player = Player::getInstance();

	current_map = new Map();
}

void Manager::GameLoop()
{
	char choice;
	int fight_result;
	while (1)
	{
		DisplayMap::centerdedToCMD(3, current_map);
		std::cout << "Where you want to go: (f)orward, (b)ackward, (l)eft, (r)igt? ";
		std::cin >> choice;
		std::cout << std::endl;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Oops, that input is invalid.  Please try again.\n";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			current_map->moovePlayer(choice);
			if (current_map->checkTileForNPC(current_map->getPlayerPos()))
			{
				fight_result = startFight(current_map->getPlayerTileNPC());
				if (fight_result == 0) {
					Chest enemy_loot(current_map->getPlayerTileNPC()->inherit_item(), current_map->getPlayerTileNPC()->get_level()*5, current_map->getPlayerTileNPC()->get_level() * 10);
					current_map->burryPlayerTileNPC(enemy_loot);
				}
				else
				{
					break;
				}
			}
		}
	}
}

void Manager::continueGame()
{

}

int Manager::startFight(std::shared_ptr<npc::Enemy> current_enemy) //0 player win, 1 - player loose
{
	//test segment

	bool player_turn = 1;

	while (1)
	{
		if (player_turn)
		{
			current_player->defence(current_enemy->attack());
		}
		else
		{
			if (!current_player->isAlive())
			{
				std::cout << "Noob, delete the game! ^_^ \n";
				return 1;
			}
			current_enemy->defence(current_player->attack());
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