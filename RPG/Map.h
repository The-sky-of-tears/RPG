#pragma once
#include "Tile.h"
#include <utility>


class Map
{
private:
	std::pair<int, int> map_size;
	Tile** map;

	std::pair<int, int> player_pos;


	void setDefaultTiles();
	void setPlayer(std::pair<int, int> player_tile);

public:
	Map();
	Map(std::pair<int, int> player_coords);
	~Map();

	std::pair<int, int> getSize();

	void setNPC(npc::Enemy* NPC, std::pair<int, int> npc_coords);
	void unsetNPC(std::pair<int, int> npc_coords);

	std::pair<int, int> getPlayerPos();

	void moovePlayer(char dir);

	Tile_Types checkTileForType(std::pair<int, int> tile_to_check);
	bool checkTileForNPC(std::pair<int, int> tile_to_check);
	bool checkTileForChest(std::pair<int, int> tile_to_check);

	npc::Enemy* getPlayerTileNPC();
	void burryPlayerTileNPC();


	int print_piece_of_map(std::pair<int, int> from, std::pair<int, int> to);
	int print_whole_map();

	int cmd_print_centered_map(int centering_rad);
};

