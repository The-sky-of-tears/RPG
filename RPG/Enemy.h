#pragma once
#include "NPC.h"
#include "Item.h"
#include "Speclist.h"
#include "include/single_include/nlohmann/json.hpp"
#include <string>
#include <memory>

namespace npc
{
	class Enemy
	{
	private:
		std::string m_name;
		std::string m_type;
		Speclist specsEnemy;
		int lvl;
	public:
		Enemy();
		~Enemy();
		const std::string& getName();
		const std::string& getType();
		const double getHealth();
		void setName(const std::string& n);
		void setType(const std::string& t);
		void setLvl(int l);
		void healthCheck();
		Speclist attack();
		void defence(Speclist& specsPlayer);
		void showCurrentState();
		bool isAlive();

		friend class BuildWarrior;
		friend class BuildArcher;
		friend class BuildMagician;
	};

	class EnemyBuilder
	{
	protected:
		std::shared_ptr<Enemy> enemy;
	public:
		EnemyBuilder();
		virtual ~EnemyBuilder();

		std::shared_ptr<Enemy> getEnemy();
		void createNewEnemy();

		virtual void nameTypeLevel() = 0;
		virtual void specsOfEnemy(/*nlohmann::json* item_db*/) = 0;
	};

	class BuildWarrior : public EnemyBuilder
	{
	public:
		BuildWarrior();
		~BuildWarrior();
		void nameTypeLevel();
		void specsOfEnemy(/*nlohmann::json* item_db*/);
	};

	class BuildArcher : public EnemyBuilder
	{
	public:
		BuildArcher();
		~BuildArcher();
		void nameTypeLevel();
		void specsOfEnemy(/*nlohmann::json* item_db*/);
	};

	class BuildMagician : public EnemyBuilder
	{
	public:
		BuildMagician();
		~BuildMagician();
		void nameTypeLevel();
		void specsOfEnemy(/*nlohmann::json* item_db*/);
	};

	class Director
	{
	private:
		EnemyBuilder* builder;
	public:
		Director();
		~Director();

		void setBuilder(EnemyBuilder* b);
		std::shared_ptr<Enemy> getEnemy();
		void build();
	};

	void/*std::shared_ptr<npc::Enemy>*/ createEnemy(Director& director, int amount, std::vector<std::shared_ptr<Enemy>>& enemyList);
}