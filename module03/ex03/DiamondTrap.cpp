#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
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

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"),
							 ScavTrap("default_clap_name"),
							 FragTrap("default_clap_name")
{
	mClass = "DiamondTrap";
	mName = "default";
	mHitPoint = FragTrap::mkDefaultHitPoint;
	mEnergyPoint = ScavTrap::mkDefaultEnergyPoint;
	mAttackDmg = FragTrap::mkDefaultAttackDmg;

	ClapTrap::mName = "default_clap_name";

	std::cout << "Default constructor called."
			  << GREEN << " DiamondTrap " << MAGENTA << getName()
			  << GREEN << " created" << RESET << std::endl;
	return;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),
											 ScavTrap(name),
											 FragTrap(name)
{

	mClass = "DiamondTrap";
	mName = name;
	mHitPoint = FragTrap::mkDefaultHitPoint;
	mEnergyPoint = ScavTrap::mkDefaultEnergyPoint;
	mAttackDmg = FragTrap::mkDefaultAttackDmg;

	std::cout << "Parameterized constructor called."
			  << GREEN << " DiamondTrap " << MAGENTA << getName()
			  << GREEN << " created" << RESET << std::endl;
	return;
}

void DiamondTrap::showStats()
{
	std::cout << YELLOW << "Name: " << MAGENTA << getName() << std::endl;
	std::cout << RED << "Hit Points: " << MAGENTA << getHitPoint() << std::endl;
	std::cout << BLUE << "Energy Points: " << MAGENTA << getEnergyPoint() << std::endl;
	std::cout << GREEN << "Attack Damage: " << MAGENTA << getAttackDmg()
			  << RESET << std::endl;
}


DiamondTrap::DiamondTrap(DiamondTrap const& other) : ClapTrap(other),
													 ScavTrap(other),
													 FragTrap(other)
{
	mClass = other.getClass();
	mName = other.getName();
	mHitPoint = other.getHitPoint();
	mEnergyPoint = other.getHitPoint();
	mAttackDmg = other.getAttackDmg();

	std::cout << "Copy constructor called. "
			  << GREEN << "DiamondTrap " << MAGENTA << getName()
			  << GREEN << " created" << RESET << std::endl;
	return;
}

/*--------------------------------DESTRUCTOR----------------------------------*/

DiamondTrap::~DiamondTrap()
{
	std::cout << "Desctructor called. "
			  << GREEN << "DiamondTrap " << MAGENTA << getName()
			  << RED << " destroyed" << RESET << std::endl;
	return;
}

/*--------------------------------OVERLOAD------------------------------------*/

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& rhs)
{
	std::cout << "Assigment Operator called. ";
	std::cout << GREEN "DiamondTrap "
			  << MAGENTA << rhs.getName()
			  << GREEN << " has been assigned to "
			  << MAGENTA << getName() << RESET << std::endl;

	if (this == &rhs) {
		return *this;
	}

	ClapTrap::mName = rhs.getName() + "_clap_name";
	mName = rhs.getName();
	mHitPoint = rhs.getHitPoint();
	mEnergyPoint = rhs.getEnergyPoint();
	mAttackDmg = rhs.getAttackDmg();
	return *this;
}

/*----------------------------MEMBER FUNCTIONS--------------------------------*/

void DiamondTrap::whoAmI()
{
	std::cout << GREEN << "I am DiamondTrap "
			  << MAGENTA << getName()
			  << YELLOW << ". My ClapTrap Name is "
			  << MAGENTA << ClapTrap::mName
			  << RESET << std::endl;

	--mEnergyPoint;
}

std::string DiamondTrap::getName() const
{
	return mName;
}
