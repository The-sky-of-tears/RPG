#include <iostream>
#include <cstdlib>
#include <ctime>

#include <iomanip>


#include "Player.h"
#include "Enemy.h"
#include "Manager.h"
#include "Item.h"
#include "Chest.h"

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	/*Manager test_manager;

	test_manager.startNewGame();

	npc::Enemy enemy_player;

	test_manager.putNPC(&enemy_player);

	test_manager.GameLoop();
	*/
	int amount = 5;
	std::vector<std::shared_ptr<npc::Enemy>> enemyList(amount);
	npc::Director director;
	npc::createEnemy(director, amount, enemyList);
	for (int i = 0; i < enemyList.size(); i++)
	{
		enemyList.at(i)->showCurrentState();
	}

	/*Player* test = Player::getInstance();
	test->showFullInfo();
	test->attack();
	test->attack();*/

	Manager game_test;
	game_test.startNewGame();
	
	game_test.startFight(enemyList[0]);

	return 0;
}