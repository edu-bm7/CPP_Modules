#include "ScavTrap.hpp"
#include <iostream>

// Color codes
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

/*-------------------------------CONSTRUCTORS---------------------------------*/

ScavTrap::ScavTrap() : ClapTrap()
{
	mClass = "ScavTrap";
	mName = "default";
	mHitPoint = mkDefaultHitPoint;
	mEnergyPoint = mkDefaultEnergyPoint;
	mAttackDmg = mkDefaultAttackDmg;
	std::cout << "Default constructor called."
			  << CYAN << " ScavTrap " << MAGENTA << getName()
			  << CYAN << " created" << RESET << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	mClass = "ScavTrap";
	mHitPoint = mkDefaultHitPoint;
	mEnergyPoint = mkDefaultEnergyPoint;
	mAttackDmg = mkDefaultAttackDmg;
	std::cout << "Parameterized constructor called."
			  << CYAN << " ScavTrap " << MAGENTA << getName()
			  << CYAN << " created" << RESET << std::endl;
	return;
}


ScavTrap::ScavTrap(ScavTrap const& other) : ClapTrap(other)
{
	mClass = other.getClass();
	mName = other.getName();
	mHitPoint = other.getHitPoint();
	mEnergyPoint = other.getHitPoint();
	mAttackDmg = other.getAttackDmg();
	std::cout << "Copy constructor called. "
			  << CYAN << "ScavTrap " << MAGENTA << getName()
			  << CYAN << " created" << RESET << std::endl;
	return;
}

/*--------------------------------DESTRUCTOR----------------------------------*/

ScavTrap::~ScavTrap()
{
	std::cout << "Desctructor called. "
			  << CYAN << "ScavTrap " << MAGENTA << getName()
			  << RED << " destroyed" << RESET << std::endl;
	return;
}

/*--------------------------------OVERLOAD------------------------------------*/

ScavTrap& ScavTrap::operator=(ScavTrap const& rhs)
{
	std::cout << "Assigment Operator called. ";
	std::cout << CYAN "ScavTrap "
			  << MAGENTA << rhs.getName()
			  << CYAN << " has been assigned to "
			  << MAGENTA << getName() << RESET << std::endl;
	if (this == &rhs) {
		return *this;
	}
	mName = rhs.getName();
	mHitPoint = rhs.getHitPoint();
	mEnergyPoint = rhs.getEnergyPoint();
	mAttackDmg = rhs.getAttackDmg();
	return *this;
}

/*----------------------------MEMBER FUNCTIONS--------------------------------*/

void ScavTrap::attack(std::string const& target)
{
	if (!canTakeAction()) {
		return;
	}

	std::cout << CYAN << getClass() << " "
			  << MAGENTA << getName() << CYAN << " punches "
			  << MAGENTA << target << RESET
			  << ", dealing " << MAGENTA << mAttackDmg
			  << RESET << " points of damage!" << std::endl;

	--mEnergyPoint;
}

void ScavTrap::guardGate()
{
	if (!canTakeAction()) {
		return;
	}

	std::cout << CYAN << getClass() << " " << MAGENTA << getName()
			  << CYAN " is now in Gate keeper mode!" << RESET << std::endl;

	--mEnergyPoint;
}
