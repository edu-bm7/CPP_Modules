#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const& other);
	~ClapTrap();

	ClapTrap& operator=(ClapTrap const& rhs);

	std::string getName() const;
	unsigned int getHitPoint() const;
	unsigned int getEnergyPoint() const;
	unsigned int getAttackDmg() const;

	void attack(std::string const& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

private:
	std::string mName;
	unsigned int mHitPoint;
	unsigned int mEnergyPoint;
	unsigned int mAttackDmg;

	bool canTakeAction();
};


#endif // CLAPTRAP_HPP
