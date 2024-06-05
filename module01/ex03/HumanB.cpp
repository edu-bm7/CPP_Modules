#include "HumanB.hpp"
#include <iostream>


HumanB::HumanB(std::string const& name) : name(name), weapon(NULL)
{
	return;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon; 
}

void HumanB::attack()
{
	if (weapon){
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	} else {
		std::cout << name << " is not holding any weapon." << std::endl;
	}
}
