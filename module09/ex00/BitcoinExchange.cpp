#include "BitcoinExchange.hpp"
#include "IsSpace.hpp"
#include <limits>

/*-------------------------------CONSTRUCTORS---------------------------------*/

BitcoinExchange::BitcoinExchange()
{
	return;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
	return;
}

BitcoinExchange::BitcoinExchange(const std::string db)
{
	std::string dbLine;
	std::ifstream dbFileToRead(db.c_str());
	bool db_first_line = true;
	if (dbFileToRead.is_open()) {
		while (std::getline(dbFileToRead, dbLine)) {
			if (db_first_line) {
				if (dbLine == "date,exchange_rate") {
					db_first_line = false;
					continue;
				}
				throw DataBaseFileInvalid();
			}
			std::string::iterator dbEnd = remove_if(dbLine.begin(), dbLine.end(), IsSpace());
			dbLine.erase(dbEnd, dbLine.end());
			mDBFile = stringDBToMap(mDBFile, dbLine, ',');
		}
	}
	return;
}

/*--------------------------------DESTRUCTOR----------------------------------*/
BitcoinExchange::~BitcoinExchange()
{
	return;
}
/*--------------------------------OVERLOADS-----------------------------------*/

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	// Guard Self-Assignment
	if (this == &rhs) {
		return *this;
	}

	return *this;
}

/*-------------------------------EXCEPTIONS-----------------------------------*/

const char* BitcoinExchange::InputFileInvalid::what() const throw()
{
	return "Error: file is invalid.";
}

const char* BitcoinExchange::DataBaseFileInvalid::what() const throw()
{
	return "Error: Database File is invalid.";
}


/*----------------------------MEMBER FUNCTIONS--------------------------------*/

std::map< std::string, float >& BitcoinExchange::stringDBToMap(
		std::map< std::string, float >& result,
		std::string& s,
		char delimiter = ',')
{
	std::istringstream ss(s);
	std::string field, key;

	if (std::getline(ss, key, delimiter) && std::getline(ss, field, delimiter)) {
		char* endptr;
		errno = 0;
		float value = std::strtof(field.c_str(), &endptr);
		if (endptr == field.c_str() || errno == ERANGE) {
			throw DataBaseFileInvalid();
		} else if (value < 0) {
			throw DataBaseFileInvalid();
		} else {
			result[key] = value;
		}
	}
	return result;
}

bool BitcoinExchange::stringIsDigit(std::string& field)
{
	if (field.empty()) {
		return false;
	}
	for (size_t i = 0; i < field.size(); ++i) {
		if (!std::isdigit(field[i])) {
			return false;
		}
	}

	return true;
}

bool BitcoinExchange::isValidDate(std::string& date)
{
	std::istringstream ss(date);
	std::string field;
	char delimiter = '-';

	int year, month, day;

	if (std::getline(ss, field, delimiter)) {
		if (!stringIsDigit(field)) {
			return false;
		}
		year = std::atoi(field.c_str());
		if (year < 2008) {
			return false;
		}
	} else {
		return false;
	}

	if (std::getline(ss, field, delimiter)) {
		if (!stringIsDigit(field)) {
			return false;
		}
		month = std::atoi(field.c_str());
		if (month < 1 || month > 12) {
			return false;
		}
	} else {
		return false;
	}

	if (std::getline(ss, field, delimiter)) {
		if (!stringIsDigit(field)) {
			return false;
		}
		day = std::atoi(field.c_str());
	} else {
		return false;
	}

	// Check the number of days in the given month
	static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// Check for leap year in February
	if (month == 2) {
		bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (isLeapYear) {
			if (day < 1 || day > 29) {
				return false;
			}
		} else if (day < 1 || day > 28) {
			return false;
		}
	} else if (day < 1 || day > daysInMonth[month - 1]) {
		return false;
	}

	return true;
}

float BitcoinExchange::getBitcoinRate(const std::string& date)
{
	std::map< std::string, float >::const_iterator it = mDBFile.lower_bound(date);
	if (it != mDBFile.begin() && (it == mDBFile.end() || it->first != date)) {
		--it;
	}
	return it->second;
}

void BitcoinExchange::printValues(const std::string& inputFile)
{
	std::string line;
	std::ifstream input(inputFile.c_str());
	bool firstHeader = true;

	if (!input.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}
	while (std::getline(input, line)) {
		if (firstHeader) {
			if (line == "date | value") {
				firstHeader = false;
				continue;
			}
			throw InputFileInvalid();
		}
		std::string::iterator lineEnd = remove_if(line.begin(), line.end(), IsSpace());
		line.erase(lineEnd, line.end());

		std::istringstream iss(line);
		std::string date;
		std::string valueStr;
		float value;


		// Split the line into date and value parts
		if (std::getline(iss, date, '|') && std::getline(iss, valueStr)) {
			errno = 0;
			char* endptr;
			value = std::strtof(valueStr.c_str(), &endptr);

			if (errno == ERANGE || value > static_cast< float >(std::numeric_limits< int >::max())) {
				std::cerr << "Error: too large a number." << std::endl;
			}
			if (!isValidDate(date)) {
				std::cerr << "Error: bad input => " << date << std::endl;
				continue;
			}
			if (value < 0) {
				std::cerr << "Error: not a positive number." << std::endl;
				continue;
			} else if (value > 1000) {
				std::cerr << "Error: to large a number." << std::endl;
				continue;
			}

			float btcValue = getBitcoinRate(date);
			std::cout << date << " => " << value << " = "
					  << (value * btcValue)
					  << std::endl;
		} else {
			std::cerr << "Error: bad input => " << line << std::endl;
		}
	}
}
