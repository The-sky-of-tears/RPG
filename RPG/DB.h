#pragma once
#include "Include/json.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <filesystem>
#include <vector>
#include <string>


constexpr auto SAVES_FOLD = "Saves//";
constexpr auto ITEMS_LOC = "Data//Items.json";
constexpr auto DEF_SAVE = "Data//Zero_save.json";

#pragma once

class DataBase
{
public:
    nlohmann::json Items_DB;

    std::vector<std::string> Saves;

    nlohmann::json Current_save;

public:
    static DataBase& Instance()
    {
        static DataBase db;
        return db;
    }

    DataBase() {
        std::cout << "HERE" << std::endl;
        std::ifstream item_file(ITEMS_LOC);
        item_file >> Items_DB;
        item_file.close();

        set_default_current_save();
        update_savelist();
    }

    void update_savelist() {
        for (const auto& entry : std::filesystem::directory_iterator(SAVES_FOLD)) {
            std::cout << entry.path() << std::endl;
            Saves.push_back(entry.path().string());
            std::cout << entry.path().string() << std::endl;
        }
    }

    void set_current_save(int iter) {
        std::filesystem::path save_path = SAVES_FOLD;
        save_path /= Saves.at(iter);
        std::ifstream save_file(save_path);
        save_file >> Current_save;
        save_file.close();
    }

    void set_default_current_save() {
        std::ifstream save_file(DEF_SAVE);
        save_file >> Current_save;
        save_file.close();
    }
};

namespace {
    DataBase& DB = DataBase::Instance();
}
