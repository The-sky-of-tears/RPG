
#include "Map.h"
#include "DB.h"

namespace Custom_Init {
	Map* for_Map() {
        nlohmann::json current_branch = DB.Enemy_DB["Chests"];
        /*      Chests      */    
        std::vector<Chest> chests_to_set;
        std::vector< std::pair<int, int> > chests_coords;
        std::vector <Item_Search_Plate> chest_insides;
        Item_Search_Plate new_plate;
        for (auto& element : current_branch) {
            chests_coords.insert(chests_coords.end(), std::make_pair(element["pos"][0], element["pos"][1]));
            for (auto& item : element["items"]) {
                chest_insides.insert(chest_insides.end(), Item_Search_Plate(item["type"], item["name"]));
            }
            chests_to_set.insert(chests_to_set.end(), Chest(chest_insides, element["exp"], element["coin"]));
        }
        /*     Enemies      */

        current_branch = DB.Enemy_DB["Enemies"];
        std::vector<std::pair<int, int>> enemy_coords;
        for (auto& element : current_branch) {
            enemy_coords.insert(enemy_coords.end(), std::make_pair(element[0], element[1]));
        }
        std::vector<std::shared_ptr<npc::Enemy>> enemyList(enemy_coords.size());
        npc::Director director;
        npc::createEnemy(director, enemy_coords.size(), enemyList);

        /*      Player      */
        current_branch = DB.Enemy_DB["Player"];
        std::pair<int, int> player_coords = std::make_pair(current_branch["pos"][0], current_branch["pos"][1]);
        /*      MAP INIT    */

        Map* new_map = new Map(player_coords, enemyList, enemy_coords, chests_to_set, chests_coords);
        return new_map;
	}
}