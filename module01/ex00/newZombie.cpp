#include "Zombie.hpp"
#include <iostream>
#include <new>

Zombie* newZombie(std::string name)
{
    try {
        Zombie* zombie;
        zombie = new Zombie;
        zombie->setName(name);
        return zombie;
    } catch (std::bad_alloc& e) {
        std::cerr << "Failed to alloc memory" << std::endl;
        return NULL;
    }
}
