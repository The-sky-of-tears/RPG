#pragma once
#include "NPC.h"
#include "Player.h"
#include <string>

namespace npc
{
	class NotEnemy
	{
	private:
		std::string m_name;
		std::string m_type;
	public:
		NotEnemy();
		~NotEnemy();
		const std::string& getName();
		const std::string& getType();
		void heal(Player& player);
		/*bool trade();*/
		//void repair(Item& item);
	};
}


