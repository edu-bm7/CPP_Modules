#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
	ScavTrap();                      // Canonical Default Constructor
	ScavTrap(ScavTrap const& other); // Canonical Copy Constructor
	~ScavTrap();                     // Canonical Default Destructor
	ScavTrap(std::string name);

	ScavTrap& operator=(ScavTrap const& rhs); // Canonical Assignment Operator

	void attack(std::string const& target);
	void guardGate();

protected:
	static const unsigned int mkDefaultHitPoint = 100;
	static const unsigned int mkDefaultEnergyPoint = 50;
	static const unsigned int mkDefaultAttackDmg = 20;
};

#endif // SCAVTRAP_HPP
