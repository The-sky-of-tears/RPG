#include "Player.h"
#include <iostream>
#include <ctime>

Player::Player(std::string n) :
	name(n)
{}

Player::~Player()
{
	delete[] availible_spels;
	delete[] inventory;
}

const std::string& Player::getName()
{
	return name;
}

const int& Player::getHealthPoints()
{
	return health_points;
}

bool Player::isAlive()
{
	return health_points <= 0 ? 0 : 1;
}

const std::pair<int, int>& Player::getPosition()
{
	return position;
}

const std::pair<std::string, int>& Player::attack()
{
	srand(time(NULL));

	std::cout << "Now it's your turn!\n Time to attack!\n"; //should be transfered to managerClass
	for (int i = 0; i < spel_capacity; i++)
	{
		std::cout << i + 1 << ". Type of hit: " << availible_spels[i].first <<
			"; Damage: " << availible_spels[i].second << std::endl; // should transfered to managerClass
	}
	
	int input;

	std::cin >> input;

	if (input > spel_capacity || input < 1)
	{
		return availible_spels[rand() % spel_capacity];
	}

	if (rand() % 101 < crit_dmg_chance)
	{
		return { availible_spels[input - 1].first,
			availible_spels[input - 1].second * crit_dmg_increase };
	}
	else
	{
		return availible_spels[input - 1];
	}
}

void Player::defence(std::pair<std::string, int> hit)
{
	//probably replace with cycle
	switch (hit.first[0])
	{
	case 'w': //water
		{
			hit.second /= water_resist;
			break;
		}
	case 'e' : //earth
		{
			hit.second /= earth_resist;
			break;
		}
	case 'f': //fire
		{
			hit.second /= fire_resist;
			break;
		}
	case 'a': //air
		{
			hit.second /= air_resist;
			break;
		}
	default:
	{}
	}

	health_points -= hit.second;
}

void Player::showCurrentState()
{
	std::cout << Player::getName() << ", " <<
		Player::getHealthPoints();
}