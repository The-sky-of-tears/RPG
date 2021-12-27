#pragma once
#include "Manager.h"
#include "DisplayMap.h"
#include "Custom_Init.h"

void Manager::startNewGame()
{
	std::cout << "Welcome to the Game!\n" << 
		"Enter your name: ";

	std::string new_name;

	std::cin >> new_name;

	current_player = Player::getInstance(new_name);
	current_map = Custom_Init::for_Map();
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
				if (fight_result == 1) {
					Chest enemy_loot(current_map->getPlayerTileNPC()->inherit_item(), current_map->getPlayerTileNPC()->get_level()*5, current_map->getPlayerTileNPC()->get_level() * 10);
					current_map->burryPlayerTileNPC(enemy_loot);
				}
				else
				{
					break;
				}
			}
			if (current_map->checkTileForChest(current_map->getPlayerPos()))
			{
				std::cout << "Your tile has chest, do you want to open it? (y)es/ (n)o" << std::endl;
				std::cin >> choice;
				std::cout << std::endl;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::cout << "Oops, that input is invalid.  Please try again later.\n";
				}
				else
				{
					std::cin.ignore(32767, '\n');

					switch (choice) {
					case 'y':
						openChest(current_map->getPlayerTileChest());
						break;
					default:
						break;
					}
				}
			}
		}
	}
}

void Manager::continueGame()
{

}

bool Manager::startFight(std::shared_ptr<npc::Enemy> current_enemy) //0 player loose, 1 - player win
{
	//test segment
	std::cout << "Fight: " << current_player->getName() << " (" << current_player->getHealth() << " HP) VS "
		<< current_enemy->getName() << " (" << current_enemy->getHealth() << " HP)\n";

	bool player_turn = 1;

	while (1)
	{
		if (player_turn)  
		{
			std::cout << "Your turn!\n";

			std::cout << "Choose action: (a)ttack, (p)otion, (s)kip. \n";
			
			current_enemy->defence(current_player->attack());

			std::cout << "Enemy health: " << current_enemy->getHealth() << " HP\n";

			if (!current_enemy->isAlive())
			{
				std::cout << "Enemy is dead\n"; // test, нужно открыть сундук, наверное
				current_player->setHealth(current_player->getHealthRegen());
				
				return 1;
			}
		}
		else
		{
			std::cout << "Enemy turn!\n";

			current_player->defence(current_enemy->attack());

			std::cout << "Your health: " << current_player->getHealth() << " HP\n";

			if (!current_player->isAlive())
			{
				std::cout << "Noob, delete the game! ^_^ \n";
				return 0;
			}
		}
		player_turn = !player_turn;
	}
}

void Manager::startTrade()
{

}

void Manager::startHeal(npc::NotEnemy nurse)
{
	std::cout << "Hello. As you can see, I am a nurse. What are the nurses doing? Correct answer: heal." std::endl;
	std::cout << "Let's count now the number of coins that you need to give me." << std::endl;
}

void Manager::openChest(Chest* player_chest)
{
	int got_coins = player_chest->get_coins(current_player);
	int got_exp = player_chest->get_experience(current_player);
	if (got_coins != 0 || got_exp != 0) {
		std::cout << "You found and opened a new chest and got:  " << std::endl;
		std::cout << "\t" << got_coins << "-- coins;" << std::endl;
		std::cout << "\t" << got_exp << "-- experience;" << std::endl;
	}
	else {
		std::cout << "You opened same chest again, no coins for you!  " << std::endl;

	}
	
	
	int free_inv_place;

	std::string choice;
	int choice_int;
	std::vector<Item> chest_items;

	while (1) {
		if (player_chest->is_empty()) {
			std::cout << "There is no items inside!" << std::endl;
			std::cout << "Just write something to quit back to map" << std::endl;
			std::cin >> choice;
			std::cout << std::endl;
			current_map->burryPlayerTileChest();
			break;
		}
		else {
			std::cout << "Choose which item put to an inventory:" << std::endl;
			chest_items = player_chest->get_item_list();
			for (int i = 0; i < chest_items.size(); i++) {
				std::cout << i << "\t" << chest_items.at(i).getName() << ";" << std::endl;
			}
		}
		std::cout << "Or write (q) to quit back to map" << std::endl;
		choice_int = -1;
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
			if (choice == "q") {
				if (player_chest->is_empty()) {
					current_map->burryPlayerTileChest();
				}
				break;
			}
			choice_int = stoi(choice);
			if (choice_int >= chest_items.size()) {
				std::cout << "There is no item with that num" << std::endl;
				continue;
			}
			free_inv_place = player_chest->pick_item(choice_int, current_player);
			if (free_inv_place < 0) {
				std::cout << "There is not enough space in inventory to put this item, you lack  " << free_inv_place << "to do this" << std::endl;;
			}
			else {
				std::cout << "Succsessful, free space:  " << free_inv_place << std::endl;
			}
		}
	}
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