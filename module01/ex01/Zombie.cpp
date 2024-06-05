#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
    return;
}

Zombie::~Zombie()
{
    std::cout << name << ": Destroyed" << std::endl;
}

void Zombie::setName(std::string const& zombieName)
{
    name = zombieName;
}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
