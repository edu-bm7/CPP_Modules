#include "FragTrap.hpp"
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

FragTrap::FragTrap() : ClapTrap()
{
	mClass = "FragTrap";
	mName = "default";
	mHitPoint = mkDefaultHitPoint;
	mEnergyPoint = mkDefaultEnergyPoint;
	mAttackDmg = mkDefaultAttackDmg;
	std::cout << "Default constructor called."
			  << BLUE << " FragTrap " << MAGENTA << getName()
			  << BLUE << " created" << RESET << std::endl;
	return;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	mClass = "FragTrap";
	mHitPoint = mkDefaultHitPoint;
	mEnergyPoint = mkDefaultEnergyPoint;
	mAttackDmg = mkDefaultAttackDmg;
	std::cout << "Parameterized constructor called."
			  << BLUE << " FragTrap " << MAGENTA << getName()
			  << BLUE << " created" << RESET << std::endl;
	return;
}


FragTrap::FragTrap(FragTrap const& other) : ClapTrap(other)
{
	mClass = other.getClass();
	mName = other.getName();
	mHitPoint = other.getHitPoint();
	mEnergyPoint = other.getHitPoint();
	mAttackDmg = other.getAttackDmg();
	std::cout << "Copy constructor called. "
			  << BLUE << "FragTrap " << MAGENTA << getName()
			  << BLUE << " created" << RESET << std::endl;
	return;
}

/*--------------------------------DESTRUCTOR----------------------------------*/

FragTrap::~FragTrap()
{
	std::cout << "Desctructor called. "
			  << BLUE << "FragTrap " << MAGENTA << getName()
			  << RED << " destroyed" << RESET << std::endl;
	return;
}

/*--------------------------------OVERLOAD------------------------------------*/

FragTrap& FragTrap::operator=(FragTrap const& rhs)
{
	std::cout << "Assigment Operator called. ";
	std::cout << BLUE "FragTrap "
			  << MAGENTA << rhs.getName()
			  << BLUE << " has been assigned to "
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

void FragTrap::highFivesGuys()
{
	if (!canTakeAction()) {
		return;
	}

	std::cout << BLUE << getClass() << " "
			  << MAGENTA << getName()
			  << BLUE << " requests a high five!"
			  << RESET << std::endl;

	--mEnergyPoint;
}
