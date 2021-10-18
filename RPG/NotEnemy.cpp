#include "NotEnemy.h"

npc::NotEnemy::NotEnemy()
{
	m_typeOfNEnemy[0] = { "Merchant", 0 };
	m_typeOfNEnemy[1] = { "Arms dealer", 0 };
	m_typeOfNEnemy[2] = { "Nurse", 0 };
	m_typeOfNEnemy[rand() % m_amountOfTypes].second = 1;
}

npc::NotEnemy::~NotEnemy()
{
	delete[] m_typeOfNEnemy;
}

const std::string& npc::NotEnemy::getType()
{
	for (int i = 0; i < m_amountOfTypes; i++)
	{
		if (m_typeOfNEnemy[i].second == 1)
		{
			return m_typeOfNEnemy[i].first;
		}
	}
}

void npc::NotEnemy::heal()
{
	if (m_typeOfNEnemy[3].second == 1)
	{
		m_health += m_health * 0.25;
	}
}

//bool npc::NotEnemy::trade()
//{
//
//}