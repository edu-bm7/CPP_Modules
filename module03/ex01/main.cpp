#include "ScavTrap.hpp"

int main()
{
	ScavTrap foo;
	ScavTrap panda("Panda");
	ScavTrap bar(panda);
	ScavTrap giraffe("Giraffe");
	ScavTrap baz;
	ClapTrap test("test");
	ClapTrap whale("Whale");

	foo = bar;

	// Uncomment to test Out of Energy for the ClapTrap Class
	// for (int i = 0; i < 11; i++) {
	// 	test.beRepaired(1);
	// }

	// Uncomment to test Out of Energy for the ScavTrap Class
	// for (int i = 0; i < 51; i++) {
	// 	baz.beRepaired(1);
	// }
	panda.attack("Bamboo");
	panda.takeDamage(giraffe.getAttackDmg());
	panda.guardGate();
	baz.guardGate();
	giraffe.guardGate();
	panda.takeDamage(baz.getAttackDmg());
	panda.beRepaired(baz.getAttackDmg());
	panda.takeDamage(90);
	panda.attack("Giraffe");
	whale.takeDamage(30);
	whale.attack("Panda");
	test.beRepaired(1);
	test.attack("Something");
	test.takeDamage(10);
	return 0;
}
