#include <iostream>
#include "Player.h"

int main()
{
    Player test_player("The_sky_of_tears");

    test_player.defence({ "fire", 30 });

    std::cout << "hp after fire 30 dmg " << test_player.getHealthPoints() << std::endl;

    test_player.defence({ "physic", 30 });

    std::cout << "hp after physic 30 dmg " << test_player.getHealthPoints() << std::endl;

    test_player.defence({ "water", 50 });

    if (test_player.isAlive())
    {
        std::cout << "alive\n";
    }
    else
    {
        std::cout << "dead\n";
    }
}
