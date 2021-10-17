#pragma once
#include "NPC.h"

namespace npc
{
	class NotEnemy : public InfNPC
	{
	private:
		int m_amountOfTypes = 3, m_amountItemsShop = (rand() % 6) + 5;
		std::pair<std::string, bool>* m_typeOfNEnemy = new std::pair<std::string, bool>[m_amountOfTypes]
		{
			{ "Merchant", 0 },
			{ "Arms dealer", 0 },
			{ "Nurse", 0 }
		};
		std::pair<std::string, int>* m_shop = new std::pair<std::string, int>[m_amountItemsShop];
	public:
		NotEnemy();
		~NotEnemy();
		bool trade();
		int heal();
	};
}


