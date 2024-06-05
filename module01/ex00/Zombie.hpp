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

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
