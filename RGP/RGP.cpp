#include <iostream>
#include "Manager.h"

int main()
{
	Manager test_manager;

	test_manager.startNewGame();

	Player enemy_player;

	test_manager.startFight(&enemy_player);



}
