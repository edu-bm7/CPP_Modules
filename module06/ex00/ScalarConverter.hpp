#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cctype>
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

class ScalarConverter {
public:
	~ScalarConverter();                                     // Canonical Default Destructor
	ScalarConverter& operator=(const ScalarConverter& rhs); // Canonical Assignment Operator

	// Methods
	static void convert(const std::string& literal);

private:
	ScalarConverter();                             // Canonical Default Constructor
	ScalarConverter(const ScalarConverter& other); // Canonical Copy Constructor

	static bool mIsPseudoLF;
	static bool mIsPseudoLD;

	static bool mIsChar(const std::string& literal);
	static bool mIsInt(const std::string& literal);
	static bool mIsFloat(const std::string& literal);
	static bool mIsDouble(const std::string& literal);
	static bool mIsPseudoLiteralFloat(const std::string& literal);
	static bool mIsPseudoLiteralDouble(const std::string& literal);
	static bool checkIntOverflow(const std::string& str);
	static bool checkCharOverflow(const std::string& str);
	static bool checkFloatOverflow(const std::string& str);
	static bool checkDoubleOverflow(const std::string& str);
	static void mConvertChar(const std::string& literal);
	static void mConvertInt(const std::string& literal);
	static void mConvertFloat(const std::string& literal);
	static void mConvertDouble(const std::string& literal);

	struct Conversion {
		bool (*mIsType)(const std::string&);
		void (*mConvert)(const std::string&);
	};
};

#endif // SCALARCONVERTER_HPP
