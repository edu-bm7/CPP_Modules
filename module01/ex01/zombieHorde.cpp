#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int N, std::string name)
{
    try {
        Zombie* horde = new Zombie[N];
        for (int i = 0; i < N; i++) {
            horde[i].setName(name); 
        }
        return horde;
    } catch(std::bad_alloc& e) {
        std::cerr << "Memory allocation failure" << std::endl;
        return NULL;
    }
}
