#pragma once
#include <iostream>

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
	bool is_NPC_here;
	bool is_chest_here;
	bool other_boolean_shit;

public:
	Tile();

	void setTileType(Tile_Types type_to_set);
	void setPlayerHere();

	Tile_Types getType();
	bool checkForPlayer();
	bool checkForNPC();
	bool checkForChest();
	bool checkForShit();

	void print_type();

};