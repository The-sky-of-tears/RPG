#pragma once
#include <string>
#include <cstdlib>
#include <ctime>

namespace npc
{
	struct InfNPC
	{
	protected:
		int m_amountOfNames = 5;
		std::string m_name;
		std::string* m_arrOfNames = new std::string[m_amountOfNames]{ "Shinji", "Wolfgang", "John", "Hector", "Nick" };
		int m_health = 100;
	public:
		InfNPC() : m_name(m_arrOfNames[rand() % 5]) {}
		~InfNPC() { delete[] m_arrOfNames; }
	};
}