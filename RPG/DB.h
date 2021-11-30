#pragma once
#include "Include/json.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>

constexpr auto ITEMS_LOC = "Data//Items.json";
constexpr auto ENEMY_LOC = "Data//Enemy_default_locations.json";

#pragma once

class DataBase
{
public:
    nlohmann::json Items_DB;
    nlohmann::json Enemy_DB;

public:
    DataBase() {
        std::ifstream item_file(ITEMS_LOC);
        item_file >> Items_DB;
        item_file.close();
        std::ifstream enemy_file(ENEMY_LOC);
        enemy_file >> Enemy_DB;
    }

    static DataBase& Instance()
    {
        static DataBase db;
        return db;
    }
};

namespace {
    DataBase& DB = DataBase::Instance();
}

