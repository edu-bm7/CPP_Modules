#include "Zombie.hpp"

int main()
{
    Zombie* zombie = newZombie("Solomon Grundy");
    if (!zombie) {
        return 1;
    }
    zombie->announce();
    delete zombie;

    randomChump("Ken Kaneki");

    return 0;
}
