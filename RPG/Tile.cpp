#pragma once
#include "Tile.h"


Tile::Tile()
{
	is_player_here = false;

	is_npc_here = false;
	npc = NULL;
	
	is_chest_here = false;
	chest = NULL;

	type = Tile_Types::Sand;
}

void Tile::setTileType(Tile_Types type_to_set)
{
	type = type_to_set;
}

void Tile::setPlayer()
{
	is_player_here = true;
}

void Tile::unsetPlayer()
{
	is_player_here = false;
}

void Tile::setNPC(std::shared_ptr<npc::Enemy> npc_to_set)
{
	is_npc_here = true;
	npc = npc_to_set;
}

void Tile::setChest(Chest* chest_to_set)
{
	is_chest_here = true;
	chest = chest_to_set;
}

Chest* Tile::unsetChest()
{
	is_chest_here = false;
	return chest;
}

std::shared_ptr<npc::Enemy> Tile::unsetNPC()
{
	is_npc_here = false;
	return npc;
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
	return is_npc_here;
}

bool Tile::checkForChest()
{
	return is_chest_here;
}

std::shared_ptr<npc::Enemy> Tile::returnNPC()
{
		return npc;
}

Chest* Tile::returnChest()
{
	return chest;
}
