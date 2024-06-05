#include "PhoneBook.hpp"

int main()
{
	std::cout << "Wellcome to the Yellow Pages!";
	std::cout << " Here you can add, search and view your entire contact list.";
	std::cout << std::endl;
	std::cout << "You can use the following commands: ADD, SEARCH, EXIT.";
	std::cout << std::endl;
    PhoneBook yellow_pages;
	while (true) {
		std::cout << "Please type a command (ADD, SEARCH, EXIT): " << std::endl;
		std::string command;
		std::getline(std::cin, command);
		if (command == "ADD") {
			yellow_pages.addContact();
		} else if (command == "SEARCH") {
			yellow_pages.showAllContacts();
		} else if (command == "EXIT") {
			break;
		}
	}
	return 0;
}
