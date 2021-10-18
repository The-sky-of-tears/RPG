#pragma once
#include <string>

namespace npc
{
	struct InfNPC
	{
	protected:
		std::string m_arrOfNames[5] = { "Shinji", "Wolfgang", "John", "Hector", "Nick" };
		int m_health = 100;
		std::string m_name = m_arrOfNames[rand() % 5];
	};
}