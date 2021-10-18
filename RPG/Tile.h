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
	npc::Enemy* npc;

	bool is_chest_here;
	Chest* chest;

public:
	Tile();

	void setTileType(Tile_Types type_to_set);

	void setPlayer();
	void unsetPlayer();

	void setNPC(npc::Enemy* npc_to_set);
	npc::Enemy* unsetNPC();

	Tile_Types getType();
	bool checkForPlayer();
	bool checkForNPC();
	bool checkForChest();

	npc::Enemy* returnNPC();

	void print_type();

};