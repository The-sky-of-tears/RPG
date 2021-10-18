#pragma once

#include "Tile.h"
#include <utility>
#include <fstream>

class Map
{
private:
	std::pair<int, int> map_size;
	Tile** map;

	std::pair<int, int> player_pos;


	//int initSavedMap();
	void setDefaultTiles();
	void setPlayer(std::pair<int, int> player_tile);
	//void setNPCs();

public:
	Map();
	Map(std::pair<int, int> player_coords);
	~Map();

	std::pair<int, int> getPlayerPos();

	bool checkTileForNPC(std::pair<int, int> tile_to_check);
	bool checkTileForChest(std::pair<int, int> tile_to_check);

	int print_piece_of_map(std::pair<int, int> from, std::pair<int, int> to);
	int print_whole_map();
};

