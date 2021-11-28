#include "Chest.h"

Chest::Chest()
{
	chest_cap = 0;
	chest_coins = 0;
	chest_exp = 0;
}

Chest::Chest(Item_Search_Plate dropped_item, int exp, int coin)
{
	chest_inv.insert(chest_inv.end(), Item(dropped_item));
	chest_cap = chest_inv.front().getWeight();
	chest_coins = coin;
	chest_exp = exp;
}

Chest::Chest(std::vector<Item_Search_Plate> found_items, int exp, int coin)
{
	for (auto i : found_items) {
		chest_inv.insert(chest_inv.end(), Item(i));
		chest_cap = chest_inv.back().getWeight();
	}
	chest_coins = coin;
	chest_exp = exp;
}

int Chest::get_coins()
{
	return chest_coins;
}

int Chest::get_experience()
{
	return chest_exp;
}

int Chest::get_cap()
{
	return chest_cap;
}

std::vector<Item> Chest::get_item_list()
{
	return chest_inv;
}

bool Chest::is_empty()
{
	return chest_cap == 0 ? 1 : 0;
}
