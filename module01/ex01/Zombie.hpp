#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
public:
    Zombie();
    ~Zombie();

    void setName(std::string const& name);
    void announce();
private:
    std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
