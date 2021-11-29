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

	void GameLoop();

	void continueGame();

	bool startFight(std::shared_ptr<npc::Enemy> current_enemy); //0 player loose, 1 - player win

	void startTrade();

	void startHeal();

	void openChest(Chest* player_chest);

	void movePlayer();

	void saveGame();

	void exit();

};

