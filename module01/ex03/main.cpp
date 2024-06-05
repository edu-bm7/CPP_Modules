#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("Gladius");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("Damascus");
		bob.attack();
	}
	{
		Weapon club = Weapon("Gladius");

		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("Damascus");
		jim.attack();
	}

	return 0;
}
