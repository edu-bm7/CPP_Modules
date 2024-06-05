#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap c("Carl"), l("Louis"), p("Paul");
	ScavTrap s("Sam"), ca("Charlie"), v("Vincent");
	FragTrap f("Francis"), r("Ron"), g("George");
	DiamondTrap d("Dan"), i("Ian"), m("Mason");

	m.whoAmI();
	d.whoAmI();
	i.whoAmI();
	{
		DiamondTrap n(m);
		n.whoAmI();
	}

	{
		DiamondTrap r;
		r.whoAmI();
		r = i;
		r.whoAmI();
	}

	{
		DiamondTrap test("TESTANDO");
		test.showStats();
	}

	// Uncomment to test Out of Energy for the ScavTrap Class
	//
	// for (int i = 0; i < 51; i++) {
	// 	s.beRepaired(1);
	// }

	// Uncomment to test Out of Energy for the DiamondTrap Class
	//
	// for (int i = 0; i < 51; i++) {
	// 	d.beRepaired(1);
	// }

	// Uncomment to test Out of Energy for the ClapTrap Class
	//
	// for (int i = 0; i < 11; i++) {
	// 	c.beRepaired(1);
	// }

	// Uncomment to test Out of Energy for the FragTrap Class
	//
	// for (int i = 0; i < 101; i++) {
	// 	f.beRepaired(1);
	// }

	c.attack("Sam");
	d.attack("Sam");
	i.attack("Sam");
	m.attack("Sam");
	d.takeDamage(ca.getAttackDmg());
	ca.guardGate();
	m.guardGate();
	i.guardGate();
	f.takeDamage(d.getAttackDmg());
	s.beRepaired(l.getAttackDmg());
	d.takeDamage(90);
	s.attack("Ron");
	g.highFivesGuys();

	return 0;
}
