#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "include/single_include/nlohmann/json.hpp"

#include "Speclist.h"


enum class Item_Types {
	Armor,
	Hat,
	Amplifier,
	Potion,
	Spell,
	Weapon,
	Magic_Weapon,
	Quest_Item,
	END
};

struct Change_List  // z = a*x + b*y + c
{
	Item_Types changed_z;

	float const_a;
	Item_Types dep_x;

	float const_b;
	Item_Types dep_y;

	float const_c;

	float z_min;
	float z_max;
};

struct Item_Search_Plate {
	std::string type;
	std::string name;
};

class Item
{
private:
	std::string name;
	std::string description;

	Item_Types type;
	int weight;
	int level; //0 - the worst, 5 - the best
	int price;

	int durability;
	int max_durability;

	std::vector<Change_List> spec_change;

	std::vector<Change_List> durability_coef;

	Item_Search_Plate transform_to;
	int transform_when;


public:
	Item(nlohmann::json* item_db, int item_class, std::string item_name);
	std::string getName();
	std::string getDescription();

	Item_Types getType();

	int getWeight();
	int getDurability();

	Speclist useItem(Speclist Player_Specs);
};

