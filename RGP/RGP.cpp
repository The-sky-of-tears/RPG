#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Enemy.h"
#include "Manager.h"

int main()
{
	Manager test_manager;

	test_manager.startNewGame();

	Player enemy_player;

	test_manager.startFight(&enemy_player);
	
	return 0;
}
