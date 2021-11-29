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
	


	Player(std::string n);

public:

	static Player* getInstance(std::string n = "Player1");

	~Player();

	const std::string& getName();

	const int& getHealthPoints();
	const double& getMaxHealth();

	double& setHealth();

	bool isAlive();

	Speclist attack();

	bool defence(Speclist enemy_speclist); // 0 - player is dead, 1 - is alive

	void showFullInfo();

};