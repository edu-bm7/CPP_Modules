#include "ClapTrap.hpp"

int main()
{
	ClapTrap a;
	ClapTrap b;
	ClapTrap blanka("Blanka");
	ClapTrap ryu("Ryu");
	ClapTrap c(ryu);

	a = c;

	blanka.attack("Ryu");
	blanka.takeDamage(9);
	blanka.beRepaired(1);
	for (int i = 0; i < 11; i++) {
		ryu.attack("Ken");
		b.beRepaired(1);
	}
	blanka.attack("Ryu");
	blanka.takeDamage(2);
	blanka.takeDamage(1);
	return 0;
}
