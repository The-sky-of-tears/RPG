#pragma once

//#include "Menu.h"
#include "Map.h"
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

	void startHeal(npc::NotEnemy nurse);

	void openChest(Chest* player_chest);

	void movePlayer();

	void saveGame();

	void exit();

};

