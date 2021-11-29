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

	int inv_capacity = 9;
	std::vector<int> inventory;
	
	//need class Spell ??
	int spel_capacity = 4;
	std::vector<std::string> availible_spels;

	Player(std::string n);

public:

	static Player* getInstance(std::string n = "Player1");

	~Player();

	const std::string& getName();

	const int& getHealthPoints();

	double& setHealth();

	bool isAlive();

	Speclist attack();

	bool defence(Speclist enemy_speclist); // 0 - player is dead, 1 - is alive

	void showFullInfo();

};