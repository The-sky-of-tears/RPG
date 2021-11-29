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

	//need class Item
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

	const std::pair<std::string, int>& attack();

	void defence(std::pair<std::string, int> hit);

	void showCurrentState();

};