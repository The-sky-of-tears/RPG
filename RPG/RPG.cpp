#include <iostream>
#include <cstdlib>
#include <ctime>

#include <iomanip>


#include "Player.h"
#include "Enemy.h"
#include "Manager.h"
#include "Item.h"
#include "Chest.h"

/*int maine()
{
	srand(static_cast<unsigned int>(time(NULL)));
	/*Manager test_manager;

	test_manager.startNewGame();

	npc::Enemy enemy_player;

	test_manager.putNPC(&enemy_player);

	test_manager.GameLoop();
	*/
	int amount = 5;
	std::vector<std::shared_ptr<npc::Enemy>> enemyList(amount);
	npc::Director director;
	npc::createEnemy(director, amount, enemyList);
	for (int i = 0; i < enemyList.size(); i++)
	{
		enemyList.at(i)->showCurrentState();
	}
	return 0;
}*/



using json = nlohmann::json;

int mainnnn()
{

	Item new_item(5, "Wooden stick");
	std::cout << new_item.getWeight() << std::endl;
	return 0;

}

int main() {
	Item_Search_Plate new_plate;
	new_plate.name = "Wooden stick";
	new_plate.type = "5";
	Chest new_chest(new_plate, 30, 5);
	std::vector<Item> list = new_chest.get_item_list();

	for (auto i : list) {
		std::cout << i.getName() << std::endl;
	}

	std::cout << new_chest.is_empty() << std::endl;
	std::cout << new_chest.get_cap() << std::endl;
}

void mainn() {
	Speclist new_speclist;
	std::cout << new_speclist.get(Spec_Types::Agility) << std::endl;
	return 0;
}