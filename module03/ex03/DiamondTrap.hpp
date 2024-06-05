#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
public:
	DiamondTrap();                         // Canonical Default Constructor
	DiamondTrap(DiamondTrap const& other); // Canonical Copy Constructor
	~DiamondTrap();                        // Canonical Default Destructor
	DiamondTrap(std::string name);

	DiamondTrap& operator=(DiamondTrap const& rhs); // Canonical Assignment Operator

	std::string getName() const;

	// using ScavTrap::attack;

	void showStats();
	void whoAmI();

private:
	std::string mName;
};

#endif // DIAMONDTRAP_HPP
