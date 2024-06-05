#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap(); // Canonical Default Constructor
	FragTrap(std::string name);
	FragTrap(FragTrap const& other); // Canonical Copy Constructor
	~FragTrap();                     // Canonical Default Destructor

	FragTrap& operator=(FragTrap const& rhs); // Canonical Assignment Operator

	void highFivesGuys();
};

#endif // FRAGTRAP_HPP
