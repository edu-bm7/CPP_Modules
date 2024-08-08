#include "ScalarConverter.hpp"
#include <limits>

bool ScalarConverter::mIsPseudoLF = false;
bool ScalarConverter::mIsPseudoLD = false;

/*-------------------------------CONSTRUCTORS---------------------------------*/
ScalarConverter::ScalarConverter()
{
	return;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	*this = other;
	return;
}
/*--------------------------------DESTRUCTOR----------------------------------*/

ScalarConverter::~ScalarConverter()
{
	return;
}

/*--------------------------------OVERLOADS-----------------------------------*/
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
	// Guard Self-Assignment
	if (this == &rhs) {
		return *this;
	}

	mIsPseudoLF = rhs.mIsPseudoLF;
	mIsPseudoLD = rhs.mIsPseudoLD;

	return *this;
}

/*---------------------------------METHODS------------------------------------*/

void ScalarConverter::convert(const std::string& literal)
{
	Conversion conversions[] = {
			{mIsChar, mConvertChar},
			{mIsInt, mConvertInt},
			{mIsFloat, mConvertFloat},
			{mIsDouble, mConvertDouble},
	};

	const int conversionsNum = sizeof(conversions) / sizeof(Conversion);

	for (int i = 0; i < conversionsNum; ++i) {
		if (conversions[i].mIsType(literal)) {
			conversions[i].mConvert(literal);
			return;
		}
	}

	std::cerr << "Invalid input" << std::endl;
}

bool ScalarConverter::mIsChar(const std::string& literal)
{
	if ((literal.length() == 1 && !std::isdigit(literal[0])) ||
		(literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')) {
		return true;
	}
	return false;
}

bool ScalarConverter::mIsInt(const std::string& literal)
{
	if (literal.empty()) {
		return false;
	}

	size_t start = 0;
	if (literal[0] == '-' || literal[0] == '+') {
		if (literal.length() == 1) {
			return false;
		}
		start = 1;
	}

	for (size_t i = start; i < literal.length(); ++i) {
		if (!std::isdigit(literal[i])) {
			return false;
		}
	}
	return true;
}

bool ScalarConverter::mIsFloat(const std::string& literal)
{
	if (literal.empty()) {
		return false;
	}

	if (mIsPseudoLiteralFloat(literal)) {
		mIsPseudoLF = true;
		return true;
	}

	size_t start = 0;
	if (literal[0] == '-' || literal[0] == '+') {
		if (literal.length() == 1) {
			return false;
		}
		start = 1;
	}

	bool hasDot = false;
	size_t length = literal.length();
	for (size_t i = start; i < length; ++i) {
		if (literal[i] == '.') {
			if (hasDot) {
				return false; // more than one dot
			}
			hasDot = true;
		} else if (literal[i] == 'f') {
			if (i != length - 1) {
				return false;
			}
		} else if (!std::isdigit(literal[i])) {
			return false;
		}
	}

	// Ensure there is at least one digit
	if (start + 1 == length && literal[start] == '.') {
		return false;
	}

	return true;
}

bool ScalarConverter::mIsDouble(const std::string& literal)
{
	if (literal.empty()) {
		return false;
	}

	if (mIsPseudoLiteralDouble(literal)) {
		mIsPseudoLD = true;
		return true;
	}

	size_t start = 0;
	if (literal[0] == '-' || literal[0] == '+') {
		if (literal.length() == 1) {
			return false;
		}
		start = 1;
	}

	bool hasDot = false;
	size_t length = literal.length();
	for (size_t i = start; i < length; ++i) {
		if (literal[i] == '.') {
			if (hasDot) {
				return false; // more than one dot
			}
			hasDot = true;
		} else if (!std::isdigit(literal[i])) {
			return false;
		}
	}

	// Ensure there is at least one digit
	if (start + 1 == length && literal[start] == '.') {
		return false;
	}

	return true;
}

bool ScalarConverter::mIsPseudoLiteralFloat(const std::string& literal)
{
	return literal == "-inff" || literal == "+inff" || literal == "nanf";
}

bool ScalarConverter::mIsPseudoLiteralDouble(const std::string& literal)
{
	return literal == "-inf" || literal == "+inf" || literal == "nan";
}


bool ScalarConverter::checkCharOverflow(const std::string& str)
{
	errno = 0;
	char* end;
	long value = std::strtol(str.c_str(), &end, 10);
	if (errno == ERANGE || value < std::numeric_limits<char>::min() ||
		value > std::numeric_limits<char>::max()) {
		return true;
	}
	return false;
}

bool ScalarConverter::checkIntOverflow(const std::string& str)
{
	errno = 0;
	char* end;
	long value = std::strtol(str.c_str(), &end, 10);
	if (errno == ERANGE || value < std::numeric_limits<int>::min() ||
		value > std::numeric_limits<int>::max()) {
		return true;
	}
	return false;
}

bool ScalarConverter::checkFloatOverflow(const std::string& str)
{
	errno = 0;
	char* end;
	float value = std::strtof(str.c_str(), &end);
	if (errno == ERANGE || std::isinf(value)) {
		return true;
	}
	return false;
}

bool ScalarConverter::checkDoubleOverflow(const std::string& str)
{
	errno = 0;
	char* end;
	double value = std::strtod(str.c_str(), &end);
	if (errno == ERANGE || std::isinf(value)) {
		return true;
	}
	return false;
}

void ScalarConverter::mConvertChar(const std::string& literal)
{
	char c;
	if (literal.length() == 1) {
		c = literal[0];
	} else {
		c = literal[1];
	}
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: "
			  << static_cast<float>(c) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: "
			  << static_cast<double>(c) << std::endl;
}

void ScalarConverter::mConvertInt(const std::string& literal)
{
	int i = std::atoi(literal.c_str());

	if (checkCharOverflow(literal)) {
		std::cout << "char: impossible" << std::endl;
	} else if (!std::isprint(static_cast<char>(i))) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	}

	if (checkIntOverflow(literal)) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << i << std::endl;
	}

	if (checkFloatOverflow(literal)) {
		std::cout << "float: impossible" << std::endl;
	} else {
		std::cout << std::fixed << std::setprecision(1) << "float: "
				  << static_cast<float>(i) << "f" << std::endl;
	}

	if (checkDoubleOverflow(literal)) {
		std::cout << "double: impossible" << std::endl;
	} else {
		std::cout << std::fixed << std::setprecision(1) << "duble: "
				  << static_cast<double>(i) << std::endl;
	}
}

void ScalarConverter::mConvertFloat(const std::string& literal)
{
	if (mIsPseudoLiteralFloat(literal)) {
		std::string pseudo = literal.substr(0, literal.length() - 1);
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << pseudo << "f" << std::endl;
		std::cout << "double: " << pseudo << std::endl;
		return;
	}

	errno = 0;
	float f = strtof(literal.c_str(), NULL);

	if (errno == ERANGE ||
		f > static_cast<float>(std::numeric_limits<char>::max()) ||
		f < static_cast<float>(std::numeric_limits<char>::min())) {
		std::cout << "char: impossible" << std::endl;
	} else if (!std::isprint(static_cast<char>(f))) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	}

	if (errno == ERANGE ||
		f > static_cast<float>(std::numeric_limits<int>::max()) ||
		f < static_cast<float>(std::numeric_limits<int>::min())) {
		std::cout << "int: impossible" << std::endl;
	} else {

		std::cout << "int: " << static_cast<int>(f) << std::endl;
	}

	if (errno == ERANGE || std::isinf(f)) {
		std::cout << "float: impossible" << std::endl;
	} else {
		std::cout << std::fixed << std::setprecision(1) << "float: "
				  << f << "f" << std::endl;
	}

	if (checkDoubleOverflow(literal)) {
		std::cout << "double: impossible" << std::endl;
	} else {
		std::cout << std::fixed << std::setprecision(1) << "double: "
				  << static_cast<double>(f) << std::endl;
	}
}

void ScalarConverter::mConvertDouble(const std::string& literal)
{
	if (mIsPseudoLiteralDouble(literal)) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << literal << "f" << std::endl;
		std::cout << "double: " << literal << std::endl;
		return;
	}

	errno = 0;
	double d = strtod(literal.c_str(), NULL);

	if (errno == ERANGE ||
		d > static_cast<double>(std::numeric_limits<char>::max()) ||
		d < static_cast<double>(std::numeric_limits<char>::min())) {
		std::cout << "char: impossible" << std::endl;
	} else if (!std::isprint(static_cast<char>(d))) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	}

	if (errno == ERANGE ||
		d > static_cast<double>(std::numeric_limits<int>::max()) ||
		d < static_cast<double>(std::numeric_limits<int>::min())) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	}


	if (errno == ERANGE ||
		d > static_cast<double>(std::numeric_limits<float>::max()) ||
		d < static_cast<double>(std::numeric_limits<float>::min())) {
		std::cout << "float: impossible" << std::endl;
	} else {
		std::cout << std::fixed << std::setprecision(1) << "float: "
				  << static_cast<float>(d) << "f" << std::endl;
	}

	if (errno == ERANGE || std::isinf(d)) {
		std::cout << "double: impossible" << std::endl;
	} else {
		std::cout << std::fixed << std::setprecision(1) << "double: "
				  << d << std::endl;
	}
}
