#pragma once
#include <iostream>
#include "Player.h"
#include "Chest.h"
#include "Enemy.h"
#include "NPC.h"

enum class Tile_Types {
	Ground,
	DeadTerritory,
	Mountian,
	Water,
	Sand
};
class Tile
{
private:
	Tile_Types type;

	bool is_player_here;
	
	bool is_npc_here;
	std::shared_ptr<npc::Enemy> npc;

	bool is_chest_here;
	Chest* chest;

public:
	Tile();

	void setTileType(Tile_Types type_to_set);

	void setPlayer();
	void unsetPlayer();

	void setNPC(std::shared_ptr<npc::Enemy> npc_to_set);
	std::shared_ptr<npc::Enemy> unsetNPC();

	void setChest(Chest* chest_to_set);
	Chest* unsetChest();

	Tile_Types getType();
	bool checkForPlayer();
	bool checkForNPC();
	bool checkForChest();

	std::shared_ptr<npc::Enemy> returnNPC();
	Chest* returnChest();

};