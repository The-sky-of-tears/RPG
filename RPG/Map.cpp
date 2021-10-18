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

void Map::setPlayer(std::pair<int, int> player_tile)
{

	player_pos = Helpers::normalize_pair(player_tile, map_size);
	map[player_tile.first][player_tile.second].setPlayer();
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
	return 0;

}

int Map::print_whole_map()
{
	return print_piece_of_map({ 0, 0 }, map_size);;
}

int Map::cmd_print_centered_map(int centering_rad)
{
	using Helpers::normalize_int;
	int x_coord;
	int y_coord;

	std::pair<int, int> from = { player_pos.first - centering_rad, player_pos.second - centering_rad };
	std::pair<int, int> to = { player_pos.first + centering_rad + 1, player_pos.second + centering_rad + 1 };

	for (x_coord = from.first; x_coord < to.first; x_coord++)
	{
		for (y_coord = from.second; y_coord < to.second; y_coord++)
		{
			std::cout << "______________";
		}
		std::cout << '\n';

		/*for (y_coord = from.second; y_coord < to.second; y_coord++) //Debugging Snake
		{
			std::cout << "| " << x_coord << "  " << y_coord<< "  " << Helpers::normalize_int(x_coord, map_size.first) << "  " << Helpers::normalize_int(y_coord, map_size.second);
		} 
		std::cout << "| \n"*/

		for (y_coord = from.second; y_coord < to.second; y_coord++)
		{
			switch (static_cast<int>(map[normalize_int(x_coord, map_size.first)][normalize_int(y_coord, map_size.second)].getType()))
			{
			case 0:
				std::cout << "|   Ground    ";
				break;
			case 1:
				std::cout << "|  DeadTerr   ";
				break;
			case 2:
				std::cout << "|  Mountian   ";
				break;

			case 3:
				std::cout << "|   Water     ";
				break;
			case 4:
				std::cout << "|   Sand      ";
				break;
			default:
				std::cout << "| AAAAAAAAAAA ";
				break;
			}
		}
		std::cout << "| \n";

		for (y_coord = from.second; y_coord < to.second; y_coord++)
		{
			if (map[normalize_int(x_coord, map_size.first)][normalize_int(y_coord, map_size.second)].checkForPlayer()) {
				std::cout << "|   PLAYER    ";
			}
			else
			{
				std::cout << "|             ";
			}
		}
		std::cout << "| \n";

		for (y_coord = from.second; y_coord < to.second; y_coord++)
		{
			if (map[normalize_int(x_coord, map_size.first)][normalize_int(y_coord, map_size.second)].checkForNPC()) {
				std::cout << "|    NPC      ";
			}
			else
			{
				std::cout << "|             ";
			}
		}
		std::cout << "| \n";
	}
	for (y_coord = from.second; y_coord < to.second; y_coord++)
	{
		std::cout << "______________";
	}
	std::cout << '\n';
	return 0;
}
