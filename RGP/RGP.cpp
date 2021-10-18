#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Enemy.h"
#include "Manager.h"

int main()
{
	//Manager test_manager;

	//test_manager.startNewGame();

	//Player enemy_player;

	//test_manager.startFight(&enemy_player);

	npc::Enemy test_enemy;
	test_enemy.healthCheck();
	test_enemy.defence({ "water", 50 });
	test_enemy.healthCheck();
	
	return 0;
}
