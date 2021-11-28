#include <iostream>
#include "Enemy.h"

npc::Enemy::Enemy() : lvl(0) {}
npc::Enemy::~Enemy() {}

const std::string& npc::Enemy::getName() { return m_name; }
const std::string& npc::Enemy::getType() { return m_type; }

const double npc::Enemy::getHealth()
{ 
	return specsEnemy.get(Spec_Types::Health);
}

void npc::Enemy::setName(const std::string& n)
{
	m_name = n;
}

void npc::Enemy::setType(const std::string& t)
{
	m_type = t;
}

void npc::Enemy::setLvl(int l)
{
	lvl = l;
}

void npc::Enemy::healthCheck()
{
	std::cout << "Health: " << getHealth() << std::endl;
}

Speclist npc::Enemy::attack()
{
	return specsEnemy;
}

void npc::Enemy::defence(Speclist& specsPlayer)
{
	int health_lost = static_cast<int>((specsEnemy.get(Spec_Types::Damage_resist) / 100) * specsPlayer.get(Spec_Types::Damage));
	health_lost += static_cast<int>((specsEnemy.get(Spec_Types::Meele_resist) / 100) * specsPlayer.get(Spec_Types::Meele_damage));
	health_lost += static_cast<int>((specsEnemy.get(Spec_Types::Deafening_resist) / 100) * specsPlayer.get(Spec_Types::Deafening_damage));
	health_lost += static_cast<int>((specsEnemy.get(Spec_Types::Poision_resist) / 100) * specsPlayer.get(Spec_Types::Poision_damage));
	health_lost /= static_cast<int>(specsEnemy.get(Spec_Types::Damage_resist));
}

void npc::Enemy::showCurrentState()
{
	std::cout << getType() << " " << getName() << ", " << getHealth() << std::endl;
}

bool npc::Enemy::isAlive()
{
	return getHealth() <= 0 ? 0 : 1;
}

npc::EnemyBuilder::EnemyBuilder() {}

npc::EnemyBuilder::~EnemyBuilder() {}

std::shared_ptr<npc::Enemy> npc::EnemyBuilder::getEnemy()
{
	return enemy;
}

void npc::EnemyBuilder::createNewEnemy()
{
	enemy.reset(new Enemy);
}

npc::BuildWarrior::BuildWarrior() : EnemyBuilder() {}

npc::BuildWarrior::~BuildWarrior() {}

void npc::BuildWarrior::nameTypeLevel()
{
	InfNPC obj;
	enemy->setName(obj.m_arrOfNames[rand() % 5]);
	enemy->setType(obj.m_arrOfTypesEnemy[0]);
	enemy->setLvl(0);
}
void npc::BuildWarrior::specsOfEnemy(/*nlohmann::json* item_db*/)
{
	enemy->specsEnemy.specs[static_cast<int>(Spec_Types::Agility)] = static_cast<int>(3 + enemy->lvl / static_cast<double>(3));
	enemy->specsEnemy.specs[static_cast<int>(Spec_Types::Strength)] = static_cast<int>(2 + enemy->lvl / static_cast<double>(3));

	enemy->specsEnemy.specs[static_cast<int>(Spec_Types::Health)] = 50;
	enemy->specsEnemy.specs[static_cast<int>(Spec_Types::Max_health)] = 50;
	enemy->specsEnemy.specs[static_cast<int>(Spec_Types::Health_regen)] = 0;
	enemy->specsEnemy.specs[static_cast<int>(Spec_Types::Damage)] = 2;
	enemy->specsEnemy.specs[static_cast<int>(Spec_Types::Crit_chance)] = 25;

	//Item weapon(item_db, 5, "Rusted Sword");
	//enemy->specsEnemy = weapon.useItem(enemy->specsEnemy);
	//Item armor(item_db, 0, "Formless piece of cloth");
	//enemy->specsEnemy = armor.useItem(enemy->specsEnemy);
}

npc::BuildArcher::BuildArcher() : EnemyBuilder() {}

npc::BuildArcher::~BuildArcher() {}

void npc::BuildArcher::nameTypeLevel()
{
	InfNPC obj;
	enemy->setName(obj.m_arrOfNames[rand() % 5]);
	enemy->setType(obj.m_arrOfTypesEnemy[1]);
	enemy->setLvl(0);
}
void npc::BuildArcher::specsOfEnemy(/*nlohmann::json* item_db*/)
{
	enemy->specsEnemy.specs[static_cast<int>(Spec_Types::Perception)] = static_cast<int>(3 + enemy->lvl / static_cast<double>(3));
	enemy->specsEnemy.specs[static_cast<int>(Spec_Types::Strength)] = static_cast<int>(2 + enemy->lvl / static_cast<double>(3));

	enemy->specsEnemy.specs[static_cast<int>(Spec_Types::Health)] = 30;
	enemy->specsEnemy.specs[static_cast<int>(Spec_Types::Max_health)] = 30;
	enemy->specsEnemy.specs[static_cast<int>(Spec_Types::Health_regen)] = 0;
	enemy->specsEnemy.specs[static_cast<int>(Spec_Types::Damage)] = 0;
	enemy->specsEnemy.specs[static_cast<int>(Spec_Types::Crit_chance)] = 25;

	/*Item weapon(item_db, 5, "Bow");
	enemy->specsEnemy = weapon.useItem(enemy->specsEnemy);
	Item armor(item_db, 0, "Formless piece of cloth");
	enemy->specsEnemy = armor.useItem(enemy->specsEnemy);*/
}

npc::BuildMagician::BuildMagician() : EnemyBuilder() {}

npc::BuildMagician::~BuildMagician() {}

void npc::BuildMagician::nameTypeLevel()
{
	InfNPC obj;
	enemy->setName(obj.m_arrOfNames[rand() % 5]);
	enemy->setType(obj.m_arrOfTypesEnemy[2]);
	enemy->setLvl(0);
}
void npc::BuildMagician::specsOfEnemy(/*nlohmann::json* item_db*/)
{
	enemy->specsEnemy.specs[static_cast<int>(Spec_Types::Intelligence)] = static_cast<int>(3 + enemy->lvl / static_cast<double>(3));
	enemy->specsEnemy.specs[static_cast<int>(Spec_Types::Agility)] = static_cast<int>(1 + enemy->lvl / static_cast<double>(3));

	enemy->specsEnemy.specs[static_cast<int>(Spec_Types::Health)] = 20;
	enemy->specsEnemy.specs[static_cast<int>(Spec_Types::Max_health)] = 20;
	enemy->specsEnemy.specs[static_cast<int>(Spec_Types::Health_regen)] = 0;
	enemy->specsEnemy.specs[static_cast<int>(Spec_Types::Damage)] = 0;
	enemy->specsEnemy.specs[static_cast<int>(Spec_Types::Crit_chance)] = 25;

	//Item weapon(item_db, 5, "Magic Wand");
	//enemy->specsEnemy = weapon.useItem(enemy->specsEnemy);
	//Item armor(item_db, 0, "Formless piece of cloth");
	//enemy->specsEnemy = armor.useItem(enemy->specsEnemy);
}

npc::Director::Director() : builder(nullptr) {}
npc::Director::~Director() {}

void npc::Director::setBuilder(EnemyBuilder* b)
{
	builder = b;
}

void npc::Director::build(/*nlohmann::json* item_db*/)
{
	builder->createNewEnemy();
	builder->nameTypeLevel();
	builder->specsOfEnemy(/*item_db*/);
}

std::shared_ptr<npc::Enemy> npc::Director::getEnemy()
{
	return builder->getEnemy();
}

void/*std::shared_ptr<npc::Enemy>*/ npc::createEnemy(Director& director, int amount, std::vector<std::shared_ptr<Enemy>>& enemyList)
{
	//std::shared_ptr<Enemy> enemy;
	for (int i = 0; i < amount; i++)
	{
		int typeOfEnemy = rand() % 3;
		if (typeOfEnemy == 0)
		{
			BuildWarrior warriorBuilder;
			director.setBuilder(&warriorBuilder);
			director.build(/*item_db*/);
			enemyList.at(i) = director.getEnemy();
		}
		else if (typeOfEnemy == 1)
		{
			BuildArcher archerBuilder;
			director.setBuilder(&archerBuilder);
			director.build(/*item_db*/);
			enemyList.at(i) = director.getEnemy();
		}
		else if (typeOfEnemy)
		{
			BuildMagician magicianBuilder;
			director.setBuilder(&magicianBuilder);
			director.build(/*item_db*/);
			enemyList.at(i) = director.getEnemy();
		}
	}
}