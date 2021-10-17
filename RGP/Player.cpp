#include "Player.h"
#include <iostream>

Player::Player(std::string n) :
	name(n)
{}

Player::~Player()
{
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

std::pair<std::string, int> Player::attack()
{
	std::cout << "Choose availible type of attack:\n";
	std::cout << "'1' - physic attack with basic damage\n" <<
		"'2' - fire attack with basic damage\n" <<
		"'3' - water attack with basic damage\n" <<
		"'4' - earth attack with basic damage\n";
	
}

void Player::defence(std::pair<std::string, int> hit)
{
	switch (hit.first[0])
	{
	case 'p': //physic
		{
			hit.second /= physic_resist;
			break;
		}
	case 'f' : //fire
		{
			hit.second /= fire_resist;
			break;
		}
	case 'w': //water
		{
			hit.second /= water_resist;
			break;
		}
	case 'e': //earth
		{
			hit.second /= earth_resist;
			break;
		}
	}

	health_points -= hit.second;
}


