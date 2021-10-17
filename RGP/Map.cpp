#include "Map.h"

Map::Map()
{
	map_size = std::make_pair(10, 10);
	map = new Tile * [map_size.first];
	for (int i = 0; i < map_size.first; i++) map[i] = new Tile[map_size.second];

	setDefaultTiles();
	setPlayer({ 0, 0 });
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

void Map::setPlayer(std::pair<int, int> player_tile)
{
	map[player_tile.first][player_tile.second].setPlayerHere();
}

std::pair<int, int> Map::getPlayerPos()
{
	return player_pos;
}

bool Map::checkTileForNPC(std::pair<int, int> tile_to_check)
{
	return map[tile_to_check.first][tile_to_check.second].checkForNPC();
}

bool Map::checkTileForChest(std::pair<int, int> tile_to_check)
{
	return map[tile_to_check.first][tile_to_check.second].checkForChest();
}

int Map::print_piece_of_map(std::pair<int, int> from, std::pair<int, int> to)
{

	std::ofstream fout("map.txt");

	if (!fout)
	{
		std::cout << "Cant open file\n\n";
		return -1;
	}
	else
	{
		std::cout << "File succsesfully opened\n\n";
	}

	int x_coord;
	int y_coord;



	for (x_coord = from.first; x_coord < to.first; x_coord++)
	{
		for (y_coord = from.second; y_coord < to.second; y_coord++)
		{
			fout << "______________";
		}
		fout << '\n';

		for (y_coord = from.second; y_coord < to.second; y_coord++)
		{
			switch (static_cast<int>(map[x_coord][y_coord].getType()))
			{
			case 0:
				fout << "|   Ground    ";
				break;
			case 1:
				fout << "|  DeadTerr   ";
				break;
			case 2:
				fout << "|  Mountian   ";
				break;

			case 3:
				fout << "|   Water     ";
				break;
			case 4:
				fout << "|   Sand      ";
				break;
			default:
				fout << "| AAAAAAAAAAA ";
				break;
			}
		}
		fout << "| \n";

		for (y_coord = from.second; y_coord < to.second; y_coord++)
		{
			if (map[x_coord][y_coord].checkForPlayer()) {
				fout << "|   PLAYER    ";
			}
			else
			{
				fout << "|             ";
			}
		}
		fout << "| \n";

		for (y_coord = from.second; y_coord < to.second; y_coord++)
		{
			if (map[x_coord][y_coord].checkForNPC()) {
				fout << "|    NPC      ";
			}
			else
			{
				fout << "|             ";
			}
		}
		fout << "| \n";
	}
	for (y_coord = from.second; y_coord < to.second; y_coord++)
	{
		fout << "______________";
	}
	fout << '\n';
	return 1;

}

int Map::print_whole_map()
{
	return print_piece_of_map({ 0, 0 }, map_size);;
}