#include <iostream>
#include <cstdlib>
#include <ctime>

#include <iomanip>
#include <sstream>


#include "Player.h"
#include "Enemy.h"
#include "Manager.h"
#include "Item.h"

int mainn()
{
	srand(static_cast<unsigned int>(time(NULL)));
	Manager test_manager;

	test_manager.startNewGame();

	npc::Enemy enemy_player;

	test_manager.putNPC(&enemy_player);

	test_manager.GameLoop();
	
	return 0;
}



using json = nlohmann::json;

int main()
{
    std::string items_json = "Data//Items.json";
    // parse and serialize JSON
    std::string data = Helpers::read_file_to_string(items_json);

    json opened = json::parse(data);
    std::cout << std::setw(4) << opened << "\n\n";

	Item new_item(&opened, 5, "Wooden stick");

	std::cout << new_item.getWeight() << std::endl;


}