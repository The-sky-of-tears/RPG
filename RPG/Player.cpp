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
			if (equipment.find("Weapon1") == equipment.end() &&
				equipment.find("Weapon2") == equipment.end())
			{
				std::cout << "Seems to be u don't have any weapon. Use your fists.\n";
				continue;
			}
			else
			{
				std::cout << "Chose type of attack: \n";
				std::cout << "Weapon1: " << equipment["Weapon1"].getName() << ", DMG: " <<
					equipment["Weapon1"].getDescription() << std::endl;

				std::cout << "Weapon2: " << equipment["Weapon2"].getName() << ", DMG: " <<
					equipment["Weapon2"].getDescription() << std::endl;

				std::cout << "Your choice Weapon(1), Weapon(2):\n";
				char choice_weapon;
				std::cin >> choice_weapon;

				while(1)
				{
					if (choice_weapon == '1')
					{
						list_to_attack = equipment["Weapon1"].useItem(player_speclist);
						break;
					}
					else if (choice_weapon == '2')
					{
						list_to_attack = equipment["Weapon2"].useItem(player_speclist);
						break;
					}
					else
					{
						std::cout << "Incorret input, try again. \n";
						continue;
					}
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

void Player::showFullInfo()
{
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
		std::cout << "Slot [" << count << "] :" << it->getName() << std::endl;
	}
}

void Player::showEquipment()
{
	std::cout << "===***===***=== Equipment ===***===***===\n";
	
	if (equipment.empty())
	{
		std::cout << "You haven't equiped anything yet.\n";
	}

	for (auto it = equipment.begin(); it != equipment.end(); it++)
	{
		std::cout << it->first << ": " << it->second.getName() << std::endl;
	}
}

void Player::openInventory()
{
	showInventory();
	showEquipment();

}

