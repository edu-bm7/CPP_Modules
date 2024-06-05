#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;

	void setFirstName(std::string const& first_name);
	void setLastName(std::string const& last_name);
	void setNickName(std::string const& nickname);
	void setPhoneNumber(std::string const& phone_number);
	void setDarkestSecret(std::string const& darkest_secret);
private:
	std::string first_name_;
	std::string last_name_;
	std::string nickname_;
	std::string phone_number_;
	std::string darkest_secret_;
};

#endif

