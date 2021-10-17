#pragma once
#include "NPC.h"

namespace npc
{
	class Enemy : private InfNPC
	{
	private:
		int m_mana = 0;
		int m_attack = 25;

		int m_amountLoot = 2, m_amountOfTypes = 3, m_amountBuffs = 3, m_amountResist = 4;
		int* m_loot = new int[m_amountLoot];
		std::pair<std::string, bool>* m_typeOfEnemy = new std::pair<std::string, bool>[m_amountOfTypes]
		{
			{ "Warrior", 0 },
			{ "Archer", 0 },
			{ "Magician", 0 }
		};
		std::pair<std::string, int>* m_resist = new std::pair<std::string, int>[m_amountResist]
		{
			{ "Air", 1 },
			{ "Earth", 1 },
			{ "Fire", 1 },
			{ "Water", 1 }
		};
		std::pair<std::string, int>* m_buffs = new std::pair<std::string, int>[m_amountResist]
		{
			{ "+Health", 0 },
			{ "+Mana", 0 },
			{ "+Attack", 0 }
		};
	public:
		Enemy();
		~Enemy();
		const std::string& getName();
		const int& getHealth();
		void healthCheck();
		void attack();
		void defence();
	};
}