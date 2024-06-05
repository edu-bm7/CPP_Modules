#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	{
		std::cout << "\n========================="
					 " POLYMORPHISM USING POINTERS "
					 "========================="
				  << std::endl;
		const Animal* a = new Animal();
		const Animal* b = new Dog();
		const Animal* c = new Cat();
		std::cout << std::endl;

		std::cout << a->getType() << std::endl;
		std::cout << b->getType() << std::endl;
		std::cout << c->getType() << std::endl;
		std::cout << std::endl;

		a->makeSound();
		b->makeSound();
		c->makeSound();
		std::cout << std::endl;

		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
	{
		std::cout << "\n========================"
					 " POLYMORPHISM USING REFERENCES "
					 "========================"
				  << std::endl;
		const Animal& x = Animal();
		const Animal& y = Dog();
		const Animal& z = Cat();
		std::cout << std::endl;

		std::cout << x.getType() << std::endl;
		std::cout << y.getType() << std::endl;
		std::cout << z.getType() << std::endl;
		std::cout << std::endl;

		x.makeSound();
		y.makeSound();
		z.makeSound();
		std::cout << std::endl;
	}
	{
		std::cout << "\n====================="
					 " OBJECT SLICING WHEN TRYING POLYMORPHISM USING OBJECTS BY VALUE "
					 "====================="
				  << std::endl;

		const Animal x = Animal();
		const Animal y = Dog();
		const Animal z = Cat();
		std::cout << std::endl;

		std::cout << x.getType() << std::endl;
		std::cout << y.getType() << std::endl;
		std::cout << z.getType() << std::endl;
		std::cout << std::endl;

		x.makeSound();
		y.makeSound();
		z.makeSound();
		std::cout << std::endl;
	}
	{
		std::cout << "\n======================"
					 " POLYMORPHISM WRONG USING POINTERS "
					 "======================"
				  << std::endl;
		const WrongAnimal* a = new WrongAnimal();
		const WrongAnimal* c = new WrongCat();
		const WrongCat* d = new WrongCat();
		std::cout << std::endl;

		std::cout << a->getType() << std::endl;
		std::cout << c->getType() << std::endl;
		std::cout << d->getType() << std::endl;
		std::cout << std::endl;

		a->makeSound();
		c->makeSound();
		d->makeSound();
		std::cout << std::endl;

		delete a;
		delete c;
		delete d;
		std::cout << std::endl;
	}
	{
		std::cout << "\n====================="
					 " POLYMORPHISM WRONG USING REFERENCES "
					 "====================="
				  << std::endl;
		const WrongAnimal& x = WrongAnimal();
		const WrongAnimal& z = WrongCat();
		const WrongCat& y = WrongCat();
		std::cout << std::endl;

		std::cout << x.getType() << std::endl;
		std::cout << z.getType() << std::endl;
		std::cout << y.getType() << std::endl;
		std::cout << std::endl;

		x.makeSound();
		z.makeSound();
		y.makeSound();
		std::cout << std::endl;
	}
	{
		std::cout << "\n====================="
					 " OBJECT SLICING WRONG WHEN TRYING POLYMORPHISM USING OBJECTS BY VALUE "
					 "====================="
				  << std::endl;

		const WrongAnimal x = WrongAnimal();
		const WrongAnimal z = WrongCat();
		const WrongCat y = WrongCat();
		std::cout << std::endl;

		std::cout << x.getType() << std::endl;
		std::cout << z.getType() << std::endl;
		std::cout << y.getType() << std::endl;
		std::cout << std::endl;

		x.makeSound();
		z.makeSound();
		y.makeSound();
		std::cout << std::endl;
	}
	return 0;
}
