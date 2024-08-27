#ifndef RPN_HPP
#define RPN_HPP

#include <cerrno>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

class RPN {
public:
	RPN();                 // Canonical Default Constructor
	RPN(const RPN& other); // Canonical Copy Constructor
	~RPN();                // Canonical Default Destructor

	// Nested Exception Classes
	class InvalidInput : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class InvalidOperator : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class InvalidOperation : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	RPN(const std::string& inputStr);
	RPN& operator=(const RPN& rhs); // Canonical Assignment Operator

private:
	std::stack< long > mStack;
	bool isStringDigit(const std::string& str);
	bool isOperator(std::string& token);
	long doOperation(std::string& token);
};

#endif // RPN_HPP
