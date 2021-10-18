#pragma once
#include <iostream>
#include "Manager.h"
//#include "Map.h"



int main()
{
	Manager test_manager;

	test_manager.startNewGame();

	Player enemy_player;

	test_manager.putNPC(&enemy_player);
	test_manager.GameLoop();

	return 0;

}



/*int main()
{
	std::cout << "Hello, world!\n";
	Map new_map;
	new_map.moovePlayer('r');
	DisplayMap::centerdedToCMD(3, &new_map);
	std::cout << new_map.getPlayerPos().first << new_map.getPlayerPos().second << '\n';
	return 0;
}*/
