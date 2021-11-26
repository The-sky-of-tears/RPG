#include "Item.h"

Item::Item(nlohmann::json* item_db, int item_type, std::string item_name)
{
	nlohmann::json found_item = (*item_db)[std::to_string(item_type)][item_name];
	std::cout << found_item << "\n\n";
	name = item_name;
	description = found_item["description"];
	type = static_cast<Item_Types>(item_type);
	weight = found_item["weight"];
	level = found_item["level"];
	price = found_item["price"];
	durability = found_item["durability"];
	max_durability = found_item["max_durability"];

	transform_to.type = found_item["transforms_to"]["type"];
	transform_to.name = found_item["transforms_to"]["name"];


}

std::string Item::getName()
{
	return name;
}

std::string Item::getDescription()
{
	return description;
}

Item_Types Item::getType()
{
	return type;
}

int Item::getWeight()
{
	return weight;
}

int Item::getDurability()
{
	return durability;
}

Speclist Item::useItem(Speclist Player_Specs)
{
	return Player_Specs;
}
