#include "Contact.hpp"

std::string Contact::getFirstName() const
{
	return first_name_;
}

std::string Contact::getLastName() const
{
	return last_name_;
}

std::string Contact::getNickName() const
{
	return nickname_;
}

std::string Contact::getPhoneNumber() const
{
	return phone_number_;
}

std::string Contact::getDarkestSecret() const
{
	return darkest_secret_;
}

void Contact::setFirstName(std::string const& first_name)
{
	first_name_ = first_name;
}

void Contact::setLastName(std::string const& last_name)
{
	last_name_ = last_name;
}

void Contact::setNickName(std::string const& nickname)
{
	nickname_ = nickname;
}

void Contact::setPhoneNumber(std::string const& phone_number)
{
	phone_number_ = phone_number;
}

void Contact::setDarkestSecret(std::string const& darkest_secret)
{
	darkest_secret_ = darkest_secret;
}
