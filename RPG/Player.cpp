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
	player_speclist.specs[static_cast<int>(Spec_Types::Max_health)] = 100;
	player_speclist.specs[static_cast<int>(Spec_Types::Health)] = 100;
	player_speclist.specs[static_cast<int>(Spec_Types::Health_regen)] = 
		player_speclist.get(Spec_Types::Health) * 0.1;

	player_speclist.specs[static_cast<int>(Spec_Types::Damage)] = 30;

}

Player::~Player()
{
	
}

const std::string& Player::getName()
{
	return name;
}

const int& Player::getHealthPoints()
{
	return player_speclist.get(Spec_Types::Health);
}

double& Player::setHealth()
{
	return player_speclist.specs[static_cast<int>(Spec_Types::Health)];
}

const double& Player::getMaxHealth()
{
	return player_speclist.specs[static_cast<int>(Spec_Types::Max_health)];
}

bool Player::isAlive()
{
	return getHealthPoints() <= 0 ? 0 : 1;
}

Speclist Player::attack()
{	
	return player_speclist;
}

bool Player::defence(Speclist enemy_speclist)
{
	int health_lost = enemy_speclist.get(Spec_Types::Damage);
	health_lost += static_cast<int>((player_speclist.get(Spec_Types::Meele_resist) / 100) * enemy_speclist.get(Spec_Types::Meele_damage));
	health_lost += static_cast<int>((player_speclist.get(Spec_Types::Deafening_resist) / 100) * enemy_speclist.get(Spec_Types::Deafening_damage));
	health_lost += static_cast<int>((player_speclist.get(Spec_Types::Poision_resist) / 100) * enemy_speclist.get(Spec_Types::Poision_damage));
	health_lost /= static_cast<int>(player_speclist.get(Spec_Types::Damage_resist));
	return isAlive();
}

void Player::showFullInfo()
{
	std::cout << "Name: " << Player::getName() << std::endl;
	for (int x = 0; x < static_cast<int>(Spec_Types::END); x++) 
	{
		std::cout << player_speclist.specs[x] << std::endl;
	}
}