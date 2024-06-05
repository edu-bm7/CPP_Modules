#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

#define MAX_CONTACTS 3


class PhoneBook {
public:
	PhoneBook();
	
	void addContact();
	void showAllContacts();
	void showContact();
private:
	Contact contacts_[MAX_CONTACTS];
	int next_index_;
	void saveContact(Contact const& contact);
};

#endif
