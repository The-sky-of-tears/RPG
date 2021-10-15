#include <string>

#include "Item.h"

class Player
{
private:
	std::string name;
	int health_points = 100; // > 0 ... normal state, < 0 - dead


	int capacity = 9;
	int* inventory = new int[capacity];

	float physic_resist = 1;
	float fire_resist = 1;
	float water_resist = 1;
	float earth_resist = 1;

	std::pair<int, int> position = {0, 0};

public:
	Player(std::string n = "Player1");

	~Player();

	const std::string& getName();

	const int& getHealthPoints();

	bool isAlive();

	const std::pair<int, int>& getPosition();

};