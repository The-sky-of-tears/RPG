#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "include/single_include/nlohmann/json.hpp"

int main(){
	nlohmann::json Enemy_DB;
	std::ifstream f("Data//Enemy_default_locations.json");
    f >> Enemy_DB;

    nlohmann::json current_branch = Enemy_DB["Chests"][0];

    std::cout << std::setw(4) << current_branch << std::endl;



    return 0;
}