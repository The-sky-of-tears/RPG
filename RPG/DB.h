#pragma once
#include "include/single_include/nlohmann/json.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>

constexpr auto ITEMS_LOC = "Data//Items.json";

#pragma once

class DataBase
{
public:
    nlohmann::json Items_DB;

public:
    DataBase() {
        std::ifstream f(ITEMS_LOC);
        f >> Items_DB;
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

