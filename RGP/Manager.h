#pragma once
#include "Player.h"
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

	void continueGame();

	void startFight(Player* current_enemy);

	void startTrade();

	void startHeal();

	void movePlayer();

	void saveGame();

	void exit();

	
};

