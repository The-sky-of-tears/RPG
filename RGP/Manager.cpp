#pragma once
#include "Manager.h"
#include "DisplayMap.h"

void Manager::startNewGame()
{
	std::cout << "Welcome to the Hell!\n" << 
		"Enter your name: ";

	std::string new_name;

	std::cin >> new_name;

	current_player = new Player(new_name);

	current_map = new Map;
}

void Manager::putNPC(Player* sheety_monster)
{
	current_map->setNPC(sheety_monster, { 4,4 });
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
		current_map->moovePlayer(choice);
		if (current_map->checkTileForNPC(current_map->getPlayerPos()))
		{
			fight_result = startFight(current_map->getPlayerTileNPC());
			if (fight_result == 0) {
				current_map->burryPlayerTileNPC();
			}
			else
			{
				break;
			}
		}

	}
}

void Manager::continueGame()
{

}

int Manager::startFight(Player* current_enemy)
{
	/*
	test segment
	*/
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
				return 0;
			}
		}
		else
		{
			current_player->defence(current_player->attack());
			current_player->showCurrentState();
			std::cout << std::endl;

			player_turn = 1;

			if (!current_player->isAlive())
			{
				std::cout << "Noob, delete the game! ^_^ \n";
				return 1;
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