#pragma once

#include "Player.h"
#include "Map.h"
#include "Enemy.h"
#include "NPC.h"

//#include "Menu.h"


class Manager
{
private:
	Player* current_player;
	Map* current_map;

public:
	~Manager();

	void startNewGame();

	void putNPC(npc::Enemy* sheety_monster); //TEMPORARY SOLUTION

	void GameLoop();

	void continueGame();

	int startFight(npc::Enemy* current_enemy); //0 player win, 1 - player loose

	void startTrade();

	void startHeal();

	void movePlayer();

	void saveGame();

	void exit();

	
};

