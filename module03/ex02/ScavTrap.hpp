#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	ScavTrap();                      // Canonical Default Constructor
	ScavTrap(ScavTrap const& other); // Canonical Copy Constructor
	~ScavTrap();                     // Canonical Default Destructor
	ScavTrap(std::string name);

	ScavTrap& operator=(ScavTrap const& rhs); // Canonical Assignment Operator

	void attack(std::string const& target);
	void guardGate();
};

#endif // SCAVTRAP_HPP
