#pragma once
#include <string>
#include <vector>

#include "Item.h"
#include "Speclist.h"

class Player
{
private:
	static Player* instance;

	Speclist player_speclist;

	std::string name;

	int inv_max_capacity = 20;
	int inv_curr_capacity  = 0;
	std::vector<Item> inventory;
	
	//add correct input check
	std::unordered_map<std::string, Item> equipment;
	/*std::unordered_map<std::string, Potion>*/

	Player(std::string n);

	friend class Chest;

public:

	static Player* getInstance(std::string n = "Player1");

	~Player();

	const std::string& getName();

	const int& getHealth();
	const double& getMaxHealth();

	double& setHealth();

	bool isAlive();

	Speclist attack();

	void defence(Speclist enemy_speclist); // 0 - player is dead, 1 - is alive

	void showFullInfo();

	void showInventory();

};