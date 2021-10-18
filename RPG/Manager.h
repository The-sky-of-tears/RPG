#pragma once
#include "Player.h"
#include "NPC.h"
#include "Enemy.h"
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

	void startFight(npc::Enemy* current_enemy);

	void startTrade();

	void startHeal();

	void movePlayer();

	void saveGame();

	void exit();

	
};

