#include <iostream>
#include "Enemy.h"

npc::Enemy::Enemy()
{

}

npc::Enemy::~Enemy()
{
	delete[] m_loot;
	delete[] m_typeOfEnemy;
	delete[] m_resist;
	delete[] m_buffs;
}

const std::string& npc::Enemy::getName() { return m_name; }

const int& npc::Enemy::getHealth() { return m_health; }

void npc::Enemy::healthCheck()
{
	std::cout << "Health: " << getHealth() << std::endl;
}

void npc::Enemy::attack()
{

}

void npc::Enemy::defence()
{

}