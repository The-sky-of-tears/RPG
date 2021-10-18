#pragma once
#include <iostream>
#include "Player.h"
#include "Chest.h"

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
	Player* npc;

	bool is_chest_here;
	Chest* chest;

public:
	Tile();

	void setTileType(Tile_Types type_to_set);

	void setPlayer();
	void unsetPlayer();

	void setNPC(Player* npc_to_set);
	Player* unsetNPC();

	Tile_Types getType();
	bool checkForPlayer();
	bool checkForNPC();
	bool checkForChest();

	Player* returnNPC();

	void print_type();

};