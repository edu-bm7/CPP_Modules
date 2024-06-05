#include "Harl.hpp"
#include <iostream>

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger."
			  << std::endl << "I really do!\n" << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money."
			  << std::endl << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free."
			  << std::endl << "I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(std::string level)
{
	HarlMemFn arr[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	const int numLevels = sizeof(arr) / sizeof(HarlMemFn);

	// CALL_MEMBER_FN Macro expands to ((*this).*(arr[i]))
	for (int i = 0; i < numLevels; i++) {
		if (level == levels[i]) {
			std::cout << "[ " << levels[i] << " ]" << std::endl;
			CALL_MEMBER_FN(*this, arr[i])(); 
			return;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]"
			  << std::endl;
}

