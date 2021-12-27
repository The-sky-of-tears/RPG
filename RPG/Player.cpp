#include "Player.h"
#include <iostream>
#include <ctime>

Player* Player::instance = 0;

Player* Player::getInstance(std::string n)
{
	if (instance == 0)
	{
		instance = new Player(n);
	}

	return instance;
}

Player::Player(std::string n) :
	name(n)
{
	player_speclist.specs[static_cast<int>(Spec_Types::Strength)] = 4;
	player_speclist.specs[static_cast<int>(Spec_Types::Perception)] = 4;
	player_speclist.specs[static_cast<int>(Spec_Types::Endurance)] = 4;
	player_speclist.specs[static_cast<int>(Spec_Types::Charisma)] = 4;
	player_speclist.specs[static_cast<int>(Spec_Types::Intelligence)] = 4;
	player_speclist.specs[static_cast<int>(Spec_Types::Agility)] = 4;
	player_speclist.specs[static_cast<int>(Spec_Types::Luck)] = 4;

	player_speclist.calculate_secondary_stats();
}

Player::~Player()
{
	
}

const std::string& Player::getName()
{
	return name;
}

const double Player::getHealth()
{
	return player_speclist.get(Spec_Types::Health);
}

const double Player::getHealthRegen()
{
	return player_speclist.get(Spec_Types::Health_regen);
}

void Player::setHealth(double incoming_regen) //regen??
{
	if (player_speclist.get(Spec_Types::Health) + incoming_regen <
		player_speclist.get(Spec_Types::Max_health))
	{
		player_speclist.specs[static_cast<int>(Spec_Types::Health)] += incoming_regen;
	}
	else
	{
		player_speclist.specs[static_cast<int>(Spec_Types::Health)] =
			player_speclist.get(Spec_Types::Max_health);
	}
}

const double& Player::getMaxHealth()
{
	return player_speclist.specs[static_cast<int>(Spec_Types::Max_health)];
}

bool Player::isAlive()
{
	return getHealth() <= 0 ? 0 : 1;
}

Speclist Player::attack()
{	
	char choice;
	Speclist list_to_attack = player_speclist;

	if (player_speclist.get(Spec_Types::Max_action_points) - 
		player_speclist.get(Spec_Types::Action_points) < 
		player_speclist.get(Spec_Types::Action_points_regen))
	{
		player_speclist.specs[static_cast<int>(Spec_Types::Action_points)] =
			player_speclist.get(Spec_Types::Max_action_points);
	}
	else
	{
		player_speclist.specs[static_cast<int>(Spec_Types::Action_points)] +=
			player_speclist.get(Spec_Types::Action_points_regen);
	}

	while (player_speclist.specs[static_cast<int>(Spec_Types::Action_points)] > 0)
	{
		std::cout << "You have : " << player_speclist.get(Spec_Types::Action_points) 
			<< " action points!\n";

		std::cin >> choice;
	
		if (choice == 'a')
		{	
			std::cout << "Chose type of attack: \n";

			if (equipment.find("Weapon") != equipment.end())
			{
				std::cout << "Weapon: " << equipment["Weapon"].getName() << ", DMG: " <<
					equipment["Weapon"].getDescription() << std::endl;
			}
			else if (equipment.find("Magic Weapon") != equipment.end())
			{
				std::cout << "Magic Weapon: " << equipment["Magic Weapon"].getName() << ", DMG: " <<
					equipment["Magic Weapon"].getDescription() << std::endl;
			} 
			else 
			{
				std::cout << "Seems to be u don't have any weapon. Use your fists (skip).\n";
				continue;
			}

			std::cout << "Your choice Weapon(1), Magic Weapon(2):\n";
			char choice_weapon;
			
			while(1)
			{	
				std::cin >> choice_weapon;
					
				if (choice_weapon == '1')
				{
					list_to_attack = equipment["Weapon"].useItem(player_speclist);
					break;
				}
				else if (choice_weapon == '2')
				{
					list_to_attack = equipment["Magic Weapon"].useItem(player_speclist);
					break;
				}
				else
				{
					std::cout << "Incorret input, try again. \n";
					continue;
				}
			}
		}
		else if (choice == 'p')
		{
			
		}
		else if (choice == 's')
		{
			return list_to_attack;
		}
		else
		{
			std::cout << "Incorret input, try again. \n";
			continue;
		}

		player_speclist.specs[static_cast<int>(Spec_Types::Action_points)]--;
		
	}
	
	std::cout << "You don't have any action points.\n";
	return list_to_attack;
}

void Player::defence(Speclist enemy_speclist)
{

	int health_lost = enemy_speclist.get(Spec_Types::Damage);
	health_lost += static_cast<int>((player_speclist.get(Spec_Types::Meele_resist) / 100) * enemy_speclist.get(Spec_Types::Meele_damage));
	health_lost += static_cast<int>((player_speclist.get(Spec_Types::Deafening_resist) / 100) * enemy_speclist.get(Spec_Types::Deafening_damage));
	health_lost += static_cast<int>((player_speclist.get(Spec_Types::Poision_resist) / 100) * enemy_speclist.get(Spec_Types::Poision_damage));
	health_lost /= static_cast<int>(player_speclist.get(Spec_Types::Damage_resist));

	player_speclist.specs[static_cast<int>(Spec_Types::Health)] -= health_lost;
}

void Player::showCharacteristics()
{
	std::cout << "===///===///=== Characteristics ===///===///===\n";

	std::cout << "Name: " << Player::getName() << std::endl;
	for (int x = 0; x < static_cast<int>(Spec_Types::END); x++) 
	{
		std::cout << player_speclist.specs[x] << std::endl;
	}
}

void Player::showInventory()
{
	std::cout << "===///===///=== Inventory ===///===///===\n";
	int count = 1;

	if (inventory.empty())
	{
		std::cout << "Your inventory is empty, poor man.\n";
	}

	for (auto it = inventory.begin(); it != inventory.end(); it++, count++)
	{
		std::cout << "Slot [" << count << "]: " << it->getName() << std::endl;
	}
}

void Player::showEquipment()
{
	std::cout << "===///===///=== Equipment ===///===///===\n";
	
	if (equipment.empty())
	{
		std::cout << "You haven't equiped anything yet.\n";
	}

	for (auto it = equipment.begin(); it != equipment.end(); it++)
	{
		std::cout << it->first << ": " << it->second.getName() << std::endl;
	}
}

bool Player::equipItem(Item equip_item)
{
	std::string item_type;

	switch (static_cast<int>(equip_item.getType()))
	{
	case 0:
		item_type = "Armor";
		break;
	case 1:
		item_type = "Hat";
		break;
	case 5:
		item_type = "Weapon";
		break;
	case 6:
		item_type = "Magic Weapon";
		break;
	default:
		return 0;
	}
	
	if (equipment.find(item_type) != equipment.end())
	{
		inventory.push_back(equipment.find(item_type)->second);

		equipment.erase(item_type);

		//need to sub parameters from player_spec
		
	}

	if (item_type != "Weapon" && item_type != "Magic Weapon")
	{
		equip_item.useItem(player_speclist);
	}

	equipment.insert({ item_type, equip_item });

	/*std::cout << static_cast<int>(equip_item.getType());*/
	return 1;
}

void Player::openInventory()
{	
	showInventory();
	//showEquipment();

	std::cout << "Choose item (number) you want to equip;show (i)nventory; show (e)quipment; show (c)haracteristics; (q) continue.\n";

	char choice_inventory; 

	while (1)
	{
		std::cin >> choice_inventory;

		switch (choice_inventory)
		{
		case 'i':
			showInventory();
			break;
		case 'e':
			showEquipment();
			break;
		case 'c':
			showCharacteristics();
			break;
		case 'q':
			return;
		default:
			int ch_inv = choice_inventory - '0' - 1;

			//std::cout << choice_inventory << " <- choice inventory\n" << ch_inv << " <- ch_inv\n";

			if (ch_inv >= 0 && ch_inv < 10 && ch_inv < inventory.size())
			{
				if (equipItem(inventory[ch_inv]))
				{
					auto it = inventory.begin() + ch_inv;
					inventory.erase(it);
					std::cout << "Equiped correctly, now you can check your characteristics.\n";
					break;
				}
				else
				{
					std::cout << "Somethint went wront (O_o). Try again.\n";
					break;
				}
			}
			else
			{
				std::cout << "Incorret input, try again. \n";
				continue;
			}
		}	
	}



}

