#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string const& name, Weapon& weapon) : name(name),
														  weapon(weapon)
{
	return;
}

void HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

