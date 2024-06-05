#include "PhoneBook.hpp"
#include <cctype>

PhoneBook::PhoneBook() : next_index_(0) 
{
	return;
}

static std::string getUserInput(std::string const& field)
{
	std::string line;
	while(std::getline(std::cin, line)) {
		if (line.empty()) {
			std::cout << "Contacts can not have empty field.\n";
			std::cout << field;
		} else {
			break;
		}
	}
	return line;
}

static bool isAllDigit(std::string const& str)
{
	for (size_t i = 0; i < str.length(); i++) {
		if (!isdigit(static_cast<unsigned char>(str[i]))) {
			return false;
		}
	}
	return true;
}

void PhoneBook::addContact()
{
	Contact contact;

	std::cout << "To add a New Contact, please fill the following fields:\n";
	std::cout << "First Name: ";
	contact.setFirstName(getUserInput("First Name: "));
	std::cout << "Last Name: ";
	contact.setLastName(getUserInput("Last Name: "));
	std::cout << "Nickname: ";
	contact.setNickName(getUserInput("Nickname: "));
	while (true) {
		std::cout << "Phone Number: ";
		std::string phone_number = getUserInput("Phone Number: ");
		if (isAllDigit(phone_number)) {
			contact.setPhoneNumber(phone_number);
			break;
		}
		else {
			std::cout << "This field must contain only numbers.";
			std::cout << std::endl;
		}
	}
	std::cout << "Darkest Secret: ";
	contact.setDarkestSecret(getUserInput("Darkest Secret: "));

	saveContact(contact);
}

static void printColumnsNames()
{
	std::cout << std::setw(10);
	std::cout << "Index" << "|";
	std::cout << std::setw(10);
	std::cout << "First Name" << "|";
	std::cout << std::setw(10);
	std::cout << "Last Name" << "|";
	std::cout << std::setw(10);
	std::cout << "Nickname" << "|";
	std::cout << std::endl;
}

std::string truncateIfNecessary(std::string const& value)
{
	const size_t max_width = 10;
	std::string str = value;
	
	if (str.length() > max_width)
		str = str.substr(0, max_width - 1) + ".";
	return str;
}

void PhoneBook::showAllContacts()
{
	printColumnsNames();

	for (int i = 0; i < MAX_CONTACTS; i++) {
		std::cout << std::setw(10);
		std::cout << i + 1;
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << truncateIfNecessary(contacts_[i].getFirstName());
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << truncateIfNecessary(contacts_[i].getLastName());
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << truncateIfNecessary(contacts_[i].getNickName());
		std::cout << "|";
		std::cout << std::endl;
	}

	showContact();
}

static int isValidInteger(std::string const& str)
{
	std::istringstream iss(str);
	int number;

	iss >> number;
	if (iss.eof() && !iss.fail()) {
		if (number >= 1 && number <= MAX_CONTACTS)
			return number;
	}
    return -1;
}

void PhoneBook::showContact()
{
	while (true) {
		std::cout << "Select a Index to display the contact information: ";
		std::cout << std::endl;
		std::string index;
		std::getline(std::cin, index);
		int i = isValidInteger(index);

		if (i < 0) {
			std::cout << "Invalid Index value, please try again.";
			std::cout << std::endl;
			continue;
		}

		i--;
		std::cout << "First Name: " << contacts_[i].getFirstName();
		std::cout << std::endl;
		std::cout << "Last Name: " << contacts_[i].getLastName();
		std::cout << std::endl;
		std::cout << "Nickname: " << contacts_[i].getNickName();
		std::cout << std::endl;
		std::cout << "Phone Number: " << contacts_[i].getPhoneNumber();
		std::cout << std::endl;
		std::cout << "Darkest Secret: " << contacts_[i].getDarkestSecret();
		std::cout << std::endl;
		break;
	}
}

void PhoneBook::saveContact(Contact const& contact)
{
	contacts_[next_index_] = contact;
	next_index_ = (next_index_ + 1) % MAX_CONTACTS;
}
