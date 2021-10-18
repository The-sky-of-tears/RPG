#pragma once
//#include "Player.h"
#include "NPC.h"
#include "Map.h"

//#include "Menu.h"


class Manager
{
private:
	Player* current_player;
	Map* current_map;

public:
	~Manager();

	void startNewGame();

	void putNPC(Player* sheety_monster); //TEMPORARY SOLUTION

	void GameLoop();

	void continueGame();

	int startFight(Player* current_enemy);

	void startTrade();

	void startHeal();

	void movePlayer();

	void saveGame();

	void exit();

	
};

