#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Enemy.h"
#include "Manager.h"

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	Manager test_manager;

	test_manager.startNewGame();

	npc::Enemy enemy_player;

	test_manager.startFight(&enemy_player);
	
	return 0;
}
