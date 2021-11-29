#pragma once
#include "Manager.h"
#include "DisplayMap.h"

void Manager::startNewGame()
{
	std::cout << "Welcome to the Game!\n" << 
		"Enter your name: ";

	std::string new_name;

	std::cin >> new_name;

	current_player = Player::getInstance(new_name);

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

bool Manager::startFight(std::shared_ptr<npc::Enemy> current_enemy) //0 player loose, 1 - player win
{
	//test segment
	int test = current_player->getHealth();
	std::cout << "Fight: " << current_player->getName() << " (" << /*current_player->getHealth()*/test << " HP) VS "
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
				std::cout << "Enemy is dead\n"; // test, ����� ������� ������, ��������
				return 1;
			}

			player_turn = !player_turn;
		}
		else
		{
			std::cout << "Enemy turn!\n";

			current_player->defence(current_enemy->attack());

			std::cout << current_player->getHealth() << std::endl;
			std::cout << "Your health: " << current_player->getHealth() << " HP\n";

			if (!current_player->isAlive())
			{
				std::cout << "Noob, delete the game! ^_^ \n";
				return 0;
			}

			player_turn = !player_turn;

		}
	}
}

void Manager::startTrade()
{

}

void Manager::startHeal()
{

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
	std::cout << "You opened same chest again, no coins for you!  " << std::endl;
	
	int free_inv_place;
	int choice_int;
	while (1) {
		std::cout << "Choose which item put to an inventory:" << std::endl;
		std::vector<Item> chest_items = player_chest->get_item_list();
		for (int i = 0; i < chest_items.size(); i++) {
			std::cout << i << "\t" << chest_items.at(i).getName() << ";" << std::endl;
		}
		std::cout << "Or write (q) to quit back to map" << std::endl;
		std::string choice;
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