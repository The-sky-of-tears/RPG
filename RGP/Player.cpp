#include "Player.h"

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



