#include <iostream>
#include <cstdlib>
#include <ctime>

#include <iomanip>


#include "Player.h"
#include "Enemy.h"
#include "NotEnemy.h"
#include "Manager.h"
#include "Item.h"
#include "Chest.h"

int main()
{
	//srand(static_cast<unsigned int>(time(NULL)));
	//npc::Director director;
	//std::vector<std::shared_ptr<npc::Enemy>> enemyList;
	//npc::createEnemy(director, enemyList, { "A", 4 });
	
	Manager test_manager;

	test_manager.startNewGame();

	test_manager.GameLoop();


/*	int amount = 5;
	std::vector<std::shared_ptr<npc::Enemy>> enemyList(amount);
	npc::Director director;
	npc::createEnemy(director, amount, enemyList);
	for (int i = 0; i < enemyList.size(); i++)
	{
		enemyList.at(i)->showCurrentState();
	}*/

	/*Player* test = Player::getInstance();
	test->showFullInfo();
	test->attack();
	test->attack();*/

/*	Manager game_test;
	game_test.startNewGame();
	
	game_test.startFight(enemyList[0]);*/

	return 0;
}

/*int main() {
	Custom_Init::for_Map();

	return 0;
}*/