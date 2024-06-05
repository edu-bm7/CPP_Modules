#include "ClapTrap.hpp"
#include <iostream>

// Color codes
#define RESET "\033[0m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define MAGENTA "\033[35m"

/*-------------------------------CONSTRUCTORS---------------------------------*/

ClapTrap::ClapTrap() : mClass("ClapTrap"),
					   mName("default"),
					   mHitPoint(10),
					   mEnergyPoint(10),
					   mAttackDmg(0)
{
	std::cout << "Default constructor called."
			  << YELLOW << " ClapTrap " << MAGENTA << getName()
			  << YELLOW << " created" << RESET << std::endl;
}


ClapTrap::ClapTrap(std::string name) : mClass("ClapTrap"),
									   mName(name),
									   mHitPoint(10),
									   mEnergyPoint(10),
									   mAttackDmg(0)
{
	std::cout << "Parameterized constructor called."
			  << YELLOW << " ClapTrap " << MAGENTA << getName()
			  << YELLOW << " created" << RESET << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& other) : mClass(other.getClass()),
											mName(other.getName()),
											mHitPoint(other.getHitPoint()),
											mEnergyPoint(other.getHitPoint()),
											mAttackDmg(other.getAttackDmg())
{
	std::cout << "Copy constructor called. "
			  << YELLOW << "ClapTrap " << MAGENTA << getName()
			  << YELLOW << " created" << RESET << std::endl;
	return;
}

/*--------------------------------DESTRUCTOR----------------------------------*/

ClapTrap::~ClapTrap()
{
	std::cout << "Desctructor called. "
			  << YELLOW << "ClapTrap " << MAGENTA << getName()
			  << RED << " destroyed" << RESET << std::endl;
	return;
}

/*--------------------------------OVERLOAD------------------------------------*/

ClapTrap& ClapTrap::operator=(ClapTrap const& rhs)
{
	std::cout << "Assigment Operator called. ";
	std::cout << YELLOW "ClapTrap "
			  << MAGENTA << rhs.getName()
			  << YELLOW << " has been assigned to "
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

/*-------------------------HELPER FUNCTIONS----------------------------*/

bool ClapTrap::canTakeAction()
{
	if (!mHitPoint) {
		std::cout << RED << getClass() << " " << MAGENTA << getName()
				  << RED << " doesn't have hit points left and LOST the fight!"
				  << RESET << std::endl;
		return false;
	}

	if (!mEnergyPoint) {
		std::cout << RED << getClass() << " " << MAGENTA << getName()
				  << RED << " is out of energy!"
				  << RESET << std::endl;
		return false;
	}

	return true;
}

/*----------------------------MEMBER FUNCTIONS--------------------------------*/

void ClapTrap::attack(std::string const& target)
{
	if (!canTakeAction()) {
		return;
	}

	std::cout << YELLOW << getClass() << " "
			  << MAGENTA << getName() << YELLOW << " kicks "
			  << MAGENTA << target << RESET
			  << ", dealing " << MAGENTA << mAttackDmg
			  << RESET << " points of damage!" << std::endl;

	--mEnergyPoint;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!canTakeAction()) {
		return;
	}

	if (mHitPoint <= amount) {
		std::cout << RED << getClass() << " " << MAGENTA << getName()
				  << RED << " took "
				  << MAGENTA << amount << RED << " of damage and LOST the fight!"
				  << RESET << std::endl;
		mHitPoint = 0;
		return;
	}

	mHitPoint -= amount;

	std::cout << YELLOW << getClass() << " "
			  << MAGENTA << getName()
			  << YELLOW << " receives "
			  << MAGENTA << amount << YELLOW << " damage!"
			  << RESET << " Having now "
			  << MAGENTA << mHitPoint
			  << RESET << " hit points left!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!canTakeAction()) {
		return;
	}

	mHitPoint += amount;
	--mEnergyPoint;

	std::cout << YELLOW << getClass() << " "
			  << MAGENTA << getName()
			  << YELLOW << " repairs itself with "
			  << MAGENTA << amount << YELLOW << " hit points!"
			  << RESET << " Having now "
			  << MAGENTA << mHitPoint
			  << RESET << " hit points" << std::endl;
}

std::string ClapTrap::getClass() const
{
	return mClass;
}

std::string ClapTrap::getName() const
{
	return mName;
}

unsigned int ClapTrap::getHitPoint() const
{
	return mHitPoint;
}

unsigned int ClapTrap::getEnergyPoint() const
{
	return mEnergyPoint;
}

unsigned int ClapTrap::getAttackDmg() const
{
	return mAttackDmg;
}
