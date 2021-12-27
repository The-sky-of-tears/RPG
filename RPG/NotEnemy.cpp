#include "NotEnemy.h"
#include <cstdlib>

npc::NotEnemy::NotEnemy()
{
	InfNPC data;
	m_name = data.m_arrOfNames[rand() % 5];
	m_type = data.m_arrOfTypesNEnemy[rand() % 3];
}

npc::NotEnemy::~NotEnemy() {}

const std::string& npc::NotEnemy::getName()
{
	return m_name;
}

const std::string& npc::NotEnemy::getType()
{
	return m_type;
}

void npc::NotEnemy::heal(Player& player)
{
	player.setHealth() = player.getMaxHealth();
}

//bool npc::NotEnemy::trade()
//{
//
//}

//void npc::NotEnemy::repair(Item& item)
//{
//
//}