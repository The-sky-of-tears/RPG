#include "Tile.h"


Tile::Tile()
{
	is_player_here = false;
	is_NPC_here = false;
	is_chest_here = false;
	other_boolean_shit = false;

	type = Tile_Types::Sand;
}

void Tile::setTileType(Tile_Types type_to_set)
{
	type = type_to_set;
}

void Tile::setPlayerHere()
{
	is_player_here = true;
}

Tile_Types Tile::getType()
{
	return type;
}

bool Tile::checkForPlayer()
{
	return is_player_here;
}

bool Tile::checkForNPC()
{
	return is_NPC_here;
}

bool Tile::checkForChest()
{
	return is_chest_here;
}

bool Tile::checkForShit()
{
	return other_boolean_shit;
}

void Tile::print_type()
{
	std::cout << static_cast<int>(type);
}
