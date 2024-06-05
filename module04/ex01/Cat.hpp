#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
	Cat();                 // Canonical Default Constructor
	Cat(Cat const& other); // Canonical Copy Constructor
	~Cat();                // Canonical Default Destructor

	Cat& operator=(Cat const& rhs); // Canonical Assignment Operator

	virtual void makeSound() const;
	std::string getType() const;
	Brain* getBrain() const;

private:
	Brain* mBrain;
};

#endif // CAT_HPP
