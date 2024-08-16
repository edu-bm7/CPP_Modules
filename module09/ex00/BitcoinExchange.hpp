#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <cerrno>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <sstream>
#include <string>

class BitcoinExchange {
public:
	BitcoinExchange(const BitcoinExchange& other); // Canonical Copy Constructor
	~BitcoinExchange();                            // Canonical Default Destructor

	BitcoinExchange(const std::string db);
	BitcoinExchange& operator=(const BitcoinExchange& rhs); // Canonical Assignment Operator

	//Member Functions
	template< typename T, typename P >
	T remove_if(T beg, T end, P pred);

	void printValues(const std::string& inputFile);

	// Nested Exception Classes
	class InputFileInvalid : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class DataBaseFileInvalid : public std::exception {
	public:
		virtual const char* what() const throw();
	};


private:
	BitcoinExchange(); // Canonical Default Constructor
	std::map< std::string, float > mDBFile;

	std::map< std::string, float >& stringDBToMap(
			std::map< std::string, float >& result,
			std::string& s,
			char delimiter);
	bool stringIsDigit(std::string& field);
	bool isValidDate(std::string& date);
	float getBitcoinRate(const std::string& date);
};

template< typename T, typename P >
T BitcoinExchange::remove_if(T beg, T end, P pred)
{
	T dest = beg;
	for (T itr = beg; itr != end; ++itr)
		if (!pred(*itr))
			*(dest++) = *itr;
	return dest;
}

#endif // BITCOINEXCHANGE_HPP
