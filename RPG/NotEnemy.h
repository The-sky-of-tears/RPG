#pragma once
#include "NPC.h"

namespace npc
{
	class NotEnemy : public InfNPC
	{
	private:
		int m_amountOfTypes = 3;
		std::pair<std::string, bool>* m_typeOfNEnemy = new std::pair<std::string, bool>[m_amountOfTypes];
	public:
		NotEnemy();
		~NotEnemy();
		const std::string& getType();
		void heal();
		/*bool trade();*/
	};
}


