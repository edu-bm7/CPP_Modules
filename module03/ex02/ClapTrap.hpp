#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
public:
	ClapTrap();                      // Canonical Default Constructor
	ClapTrap(ClapTrap const& other); // Canonical Copy Constructor
	~ClapTrap();                     // Canonical Default Destructor
	ClapTrap(std::string name);

	ClapTrap& operator=(ClapTrap const& rhs); // Canonical Assignment Operator

	std::string getClass() const;
	std::string getName() const;
	unsigned int getHitPoint() const;
	unsigned int getEnergyPoint() const;
	unsigned int getAttackDmg() const;

	void attack(std::string const& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:
	std::string mClass;
	std::string mName;
	unsigned int mHitPoint;
	unsigned int mEnergyPoint;
	unsigned int mAttackDmg;

	bool canTakeAction();
};


#endif // CLAPTRAP_HPP
