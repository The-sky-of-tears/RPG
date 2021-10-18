#pragma once
#include "NPC.h"
#include "Item.h"

namespace npc
{
	class Enemy : private InfNPC
	{
	private:
		int m_mana = 0;
		int m_attack = 30;
		int m_crit_damage_chance = 10;

		int m_amountOfTypes = 3, m_amountBuffs = 3, m_amountResist = 4, m_amountSpells = 4;
		std::pair<std::string, int>* m_attacks = new std::pair<std::string, int>[m_amountSpells];
		std::pair<std::string, bool>* m_typeOfEnemy = new std::pair<std::string, bool>[m_amountOfTypes];
		std::pair<std::string, double>* m_resist = new std::pair<std::string, double>[m_amountResist];
	public:
		Enemy();
		~Enemy();
		const std::string& getName();
		const int& getHealth();
		void healthCheck();
		const std::pair<std::string, int>& attack();
		void defence(std::pair<std::string, int> hit);
		void showCurrentState();
		bool isAlive();
	};
}