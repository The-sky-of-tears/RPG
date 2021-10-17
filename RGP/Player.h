#include <string>

#include "Item.h"

class Player
{
private:
	std::string name;
	int health_points = 100; // > 0 ... normal state, <= 0 - dead
	int default_dmg = 30;


	int capacity = 9;
	int* inventory = new int[capacity];

	float physic_resist = 1.5;
	float fire_resist = 1;
	float water_resist = 1;
	float earth_resist = 1;

	int crit_dmg_chance = 10; //0 - 0%, 100 - 100%
	float crit_dmg_increase = 1.5; // default_dmg * crit_dmg_increase

	std::pair<int, int> position = {0, 0};

public:
	Player(std::string n = "Player1");

	~Player();

	const std::string& getName();

	const int& getHealthPoints();

	bool isAlive();

	const std::pair<int, int>& getPosition();

	std::pair<std::string, int> attack();

	void defence(std::pair<std::string, int> hit);

};