#include "Map.h"
#include <fstream>
#include "Helpers.h"

Map::Map()
{
	map_size = std::make_pair(10, 10);
	map = new Tile * [map_size.first];
	for (int i = 0; i < map_size.first; i++) map[i] = new Tile[map_size.second];

	setDefaultTiles();
	setPlayer({ map_size.first / 2, map_size.second / 2 });
}

Map::Map(std::pair<int, int> player_coords)
{
	map_size = std::make_pair(10, 10);
	map = new Tile * [map_size.first];
	for (int i = 0; i < map_size.first; i++) map[i] = new Tile[map_size.second];

	setDefaultTiles();
	setPlayer(player_coords);
}

Map::~Map()
{
	for (int i = 0; i < map_size.first; i++) delete[] map[i];
	delete[] map;
}

std::pair<int, int> Map::getSize()
{
	return map_size;
}


void Map::setNPC(npc::Enemy* NPC, std::pair<int, int> npc_coords)
{
	map[npc_coords.first][npc_coords.second].setNPC(NPC);
}

void Map::unsetNPC(std::pair<int, int> npc_coords)
{
	map[npc_coords.first][npc_coords.second].unsetNPC();
}

void Map::setDefaultTiles()
{
	for (int x_coord = 0; x_coord < map_size.first; x_coord++)
	{
		for (int y_coord = 0; y_coord < map_size.second; y_coord++)
		{
			map[x_coord][y_coord].setTileType(Tile_Types::Ground);
		}
	}
}

void Map::setPlayer(std::pair<int, int> new_player_tile)
{

	player_pos = Helpers::normalize_pair(new_player_tile, map_size);
	std::cout << new_player_tile.first << " " << new_player_tile.second << std::endl;
	std::cout << player_pos.first << " " << player_pos.second << std::endl;
	map[player_pos.first][player_pos.second].setPlayer();
}

std::pair<int, int> Map::getPlayerPos()
{
	return player_pos;
}

void Map::moovePlayer(char dir) // (f)orward, (b)ackward, (l)eft, (r)igt
{
	std::pair<int, int> new_coords = player_pos;
	switch (dir) 
	{
	case 'f':
		new_coords.first--;
		break;
	case 'b':
		new_coords.first++;
		break;
	case 'l':
		new_coords.second--;
		break;
	case 'r':
		new_coords.second++;
		break;
	default:
		break;
	}

	map[player_pos.first][player_pos.second].unsetPlayer();
	Map::setPlayer(new_coords);
}

Tile_Types Map::checkTileForType(std::pair<int, int> tile_to_check)
{
	return map[tile_to_check.first][tile_to_check.second].getType();
}

bool Map::checkTileForNPC(std::pair<int, int> tile_to_check)
{
	return map[tile_to_check.first][tile_to_check.second].checkForNPC();
}

bool Map::checkTileForChest(std::pair<int, int> tile_to_check)
{
	return map[tile_to_check.first][tile_to_check.second].checkForChest();
}

npc::Enemy* Map::getPlayerTileNPC()
{
	return map[player_pos.first][player_pos.second].returnNPC();
}

void Map::burryPlayerTileNPC()
{
	unsetNPC(player_pos);
}

