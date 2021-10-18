#include <iostream>
#include "Enemy.h"

npc::Enemy::Enemy()
{
	srand(static_cast<unsigned int>(time(NULL)));
	m_typeOfEnemy[0] = { "Warrior", 0 };
	m_typeOfEnemy[1] = { "Archer", 0 };
	m_typeOfEnemy[2] = { "Magician", 0 };
	m_typeOfEnemy[rand() % m_amountOfTypes].second = 1;

	if (static_cast<int>(m_typeOfEnemy[0].second) == 1)
	{
		m_resist[0] = { "Air", 0.7 };
		m_resist[1] = { "Earth", 1.5 };
		m_resist[2] = { "Fire", 1.3 };
		m_resist[3] = { "Water", 1.0 };
		m_health = 150;
		m_attack = 50;
		m_attacks[0] = { "water", m_attack };
		m_attacks[1] = { "earth", m_attack };
		m_attacks[2] = { "fire", m_attack };
		m_attacks[3] = { "air", m_attack };
	}
	else if (static_cast<int>(m_typeOfEnemy[1].second) == 1)
	{
		m_resist[0] = { "Air", 2.0 };
		m_resist[1] = { "Earth", 0.7 };
		m_resist[2] = { "Fire", 1.2 };
		m_resist[3] = { "Water", 1.0 };
		m_health = 90;
		m_attack = 35;
		m_mana = 60;
		m_attacks[0] = { "water", m_attack };
		m_attacks[1] = { "earth", m_attack };
		m_attacks[2] = { "fire", m_attack };
		m_attacks[3] = { "air", m_attack };
	}
	else if (static_cast<int>(m_typeOfEnemy[2].second) == 1)
	{
		m_resist[0] = { "Air", 1.5 };
		m_resist[1] = { "Earth", 0.4 };
		m_resist[2] = { "Fire", 2.0 };
		m_resist[3] = { "Water", 1.3 };
		m_health = 60;
		m_attack = 30;
		m_mana = 100;
		m_attacks[0] = { "water", m_attack };
		m_attacks[1] = { "earth", m_attack };
		m_attacks[2] = { "fire", m_attack };
		m_attacks[3] = { "air", m_attack };
	}
}

npc::Enemy::~Enemy()
{
	delete[] m_typeOfEnemy;
	delete[] m_resist;
}

const std::string& npc::Enemy::getName() { return m_name; }

const int& npc::Enemy::getHealth() { return m_health; }

void npc::Enemy::healthCheck()
{
	std::cout << "Health: " << getHealth() << std::endl;
}

const std::pair<std::string, int>& npc::Enemy::attack()
{
	srand(static_cast<unsigned int>(time(NULL)));
	int typeOfAttack = rand() % 5;

	if (rand() % 101 < m_crit_damage_chance)
	{
		return { m_attacks[typeOfAttack].first, m_attacks[typeOfAttack].second * m_crit_damage_chance };
	}
	else
	{
		return m_attacks[typeOfAttack];
	}
}

void npc::Enemy::defence(std::pair<std::string, int> hit)
{
	switch (hit.first[0])
	{
	case 'w': //water
	{
		hit.second /= m_resist[3].second;
		break;
	}
	case 'e': //earth
	{
		hit.second /= m_resist[1].second;
		break;
	}
	case 'f': //fire
	{
		hit.second /= m_resist[2].second;
		break;
	}
	case 'a': //air
	{
		hit.second /= m_resist[0].second;
		break;
	}
	default:
	{}
	}

	m_health -= hit.second;
}