#pragma once
#include "include/single_include/nlohmann/json.hpp"
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
        std::ifstream f(ITEMS_LOC);
        f >> Items_DB;
        f.close();
        std::ifstream f(ENEMY_LOC);
        f >> Enemy_DB;
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

