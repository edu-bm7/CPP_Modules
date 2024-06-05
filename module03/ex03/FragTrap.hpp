#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
	FragTrap(); // Canonical Default Constructor
	FragTrap(std::string name);
	FragTrap(FragTrap const& other); // Canonical Copy Constructor
	~FragTrap();                     // Canonical Default Destructor

	FragTrap& operator=(FragTrap const& rhs); // Canonical Assignment Operator

	void highFivesGuys();

protected:
	static const unsigned int mkDefaultHitPoint = 100;
	static const unsigned int mkDefaultEnergyPoint = 100;
	static const unsigned int mkDefaultAttackDmg = 30;
};

#endif // FRAGTRAP_HPP
