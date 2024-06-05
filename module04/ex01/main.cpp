#include "Cat.hpp"
#include "Dog.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

#define MAX_ANIMALS 10

int main()
{
	std::srand(std::time(NULL));
	{
		std::cout << "\n========================="
					 " SUBJECT "
					 "========================="
				  << std::endl;
		Animal* animals[MAX_ANIMALS];

		for (size_t i = 0; i < MAX_ANIMALS; i++) {
			if (i % 2 == 0) {
				animals[i] = new Dog;
			} else {
				animals[i] = new Cat;
			}
		}
		std::cout << std::endl;

		for (size_t i = 0; i < MAX_ANIMALS; i++) {
			animals[i]->makeSound();
		}
		std::cout << std::endl;

		for (size_t i = 0; i < MAX_ANIMALS; i++) {
			delete animals[i];
		}
		std::cout << std::endl;
	}
	{
		std::cout << "\n========================"
					 " COPY CONSTRUCTOR "
					 "========================"
				  << std::endl;
		Dog* dog = new Dog;
		std::cout << std::endl;

		Dog* copy_dog = new Dog(*dog);
		std::cout << std::endl;

		copy_dog->getBrain()->setIdea(0, "This idea only happens on the copy_dog.");
		std::cout << "dog's type:\t\t\t" << dog->getType() << std::endl;
		std::cout << "dog's brain addres:\t\t" << dog->getBrain() << std::endl;
		std::cout << "dog's first idea:\t\t" << dog->getBrain()->getIdea(0) << std::endl;
		std::cout << "dog's random idea:\t\t" << *dog->getBrain() << std::endl;
		std::cout << "copy_dog's type:\t\t" << copy_dog->getType() << std::endl;
		std::cout << "copy_dog's brain addres:\t" << copy_dog->getBrain() << std::endl;
		std::cout << "copy_dog's first idea:\t\t" << copy_dog->getBrain()->getIdea(0) << std::endl;
		std::cout << "copy_dog's random idea:\t\t" << *copy_dog->getBrain() << std::endl;
		std::cout << std::endl;

		Cat* cat = new Cat;
		std::cout << std::endl;

		Cat* copy_cat = new Cat(*cat);
		std::cout << std::endl;

		copy_cat->getBrain()->setIdea(0, "This idea only happens on the copy_cat.");
		std::cout << "cat's type:\t\t\t" << cat->getType() << std::endl;
		std::cout << "cat's brain addres:\t\t" << cat->getBrain() << std::endl;
		std::cout << "cat's first idea:\t\t" << cat->getBrain()->getIdea(0) << std::endl;
		std::cout << "cat's random idea:\t\t" << *cat->getBrain() << std::endl;
		std::cout << "copy_cat's type:\t\t" << copy_cat->getType() << std::endl;
		std::cout << "copy_cat's brain addres:\t" << copy_cat->getBrain() << std::endl;
		std::cout << "copy_cat's first idea:\t\t" << copy_cat->getBrain()->getIdea(0) << std::endl;
		std::cout << "copy_cat's random idea:\t\t" << *copy_cat->getBrain() << std::endl;
		std::cout << std::endl;
		delete dog;
		delete copy_dog;
		delete cat;
		delete copy_cat;
	}
	{
		std::cout << "\n====================="
					 " ASSIGNMENT OPERATOR "
					 "====================="
				  << std::endl;

		Dog* dog = new Dog;
		Dog assignment_dog = *dog;
		std::cout << std::endl;

		assignment_dog.getBrain()->setIdea(0, "This idea only happens on the assignment_dog.");
		std::cout << "dog's type:\t\t\t" << dog->getType() << std::endl;
		std::cout << "dog's brain addres:\t\t" << dog->getBrain() << std::endl;
		std::cout << "dog's first idea:\t\t" << dog->getBrain()->getIdea(0) << std::endl;
		std::cout << "dog's random idea:\t\t" << *dog->getBrain() << std::endl;
		std::cout << "assignment_dog's type:\t\t" << assignment_dog.getType() << std::endl;
		std::cout << "assignment_dog's brain addres:\t" << assignment_dog.getBrain() << std::endl;
		std::cout << "assignment_dog's first idea:\t" << assignment_dog.getBrain()->getIdea(0) << std::endl;
		std::cout << "assignment_dog's random idea:\t" << *assignment_dog.getBrain() << std::endl;
		std::cout << std::endl;


		Cat* cat = new Cat;
		Cat assignment_cat = *cat;
		std::cout << std::endl;

		assignment_cat.getBrain()->setIdea(0, "This idea only happens on the assignment_cat.");
		std::cout << "cat's type:\t\t\t" << cat->getType() << std::endl;
		std::cout << "cat's brain addres:\t\t" << cat->getBrain() << std::endl;
		std::cout << "cat's first idea:\t\t" << cat->getBrain()->getIdea(0) << std::endl;
		std::cout << "cat's random idea:\t\t" << *cat->getBrain() << std::endl;
		std::cout << "assignment_cat's type:\t\t" << assignment_cat.getType() << std::endl;
		std::cout << "assignment_cat's brain addres:\t" << assignment_cat.getBrain() << std::endl;
		std::cout << "assignment_cat's first idea:\t" << assignment_cat.getBrain()->getIdea(0) << std::endl;
		std::cout << "assignment_cat's random idea:\t" << *assignment_cat.getBrain() << std::endl;
		std::cout << std::endl;
	}
	{
		Dog assign;
		{
			Dog ymp = assign;
		}
		std::cout << std::endl;
		if (assign.getBrain() != NULL) {
			std::cout << "Dog still have Brains! Deep Copy. Brain's Address: "
					  << assign.getBrain() << std::endl;
		} else {
			std::cout << "Dog Brains vanished! Shallow Copy. Brain's Address: "
					  << assign.getBrain();
		}
		std::cout << std::endl;
		Dog cpy;
		{
			Dog tmp(cpy);
		}
		std::cout << std::endl;
		if (cpy.getBrain() != NULL) {
			std::cout << "Dog still have Brains! Deep Copy. Brain's Address: "
					  << cpy.getBrain() << std::endl;
		} else {
			std::cout << "Dog Brains vanished! Shallow Copy. Brain's Address: "
					  << cpy.getBrain();
		}
		std::cout << std::endl;
		Cat assign_cat;
		{
			Cat ymp = assign_cat;
		}
		std::cout << std::endl;
		if (assign_cat.getBrain() != NULL) {
			std::cout << "Cat still have Brains! Deep Copy. Brain's Address: "
					  << assign_cat.getBrain() << std::endl;
		} else {
			std::cout << "Cat Brains vanished! Shallow Copy. Brain's Address: "
					  << assign_cat.getBrain();
		}
		std::cout << std::endl;
		Cat cpy_cat;
		{
			Cat tmp(cpy_cat);
		}
		std::cout << std::endl;
		if (cpy_cat.getBrain() != NULL) {
			std::cout << "Cat still have Brains! Deep Copy. Brain's Address: "
					  << cpy_cat.getBrain() << std::endl;
		} else {
			std::cout << "Cat Brains vanished! Shallow Copy. Brain's Address: "
					  << cpy_cat.getBrain();
		}
		std::cout << std::endl;
	}

	return 0;
}
