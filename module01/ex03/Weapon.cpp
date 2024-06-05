#include "Weapon.hpp"

Weapon::Weapon(std::string const& type) : type(type)
{
	return;
}

std::string const& Weapon::getType() const
{
	return type;
}

void Weapon::setType(std::string const& type)
{
	this->type = type;
}
