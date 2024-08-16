#include "RPN.hpp"

/*-------------------------------CONSTRUCTORS---------------------------------*/
RPN::RPN() : mStack()
{
	return;
}

RPN::RPN(const RPN& other) : mStack(other.mStack)
{
	return;
}

RPN::RPN(const std::string& inputStr) : mStack()
{
	if (inputStr.empty()) {
		throw InvalidInput();
	}

	std::istringstream iss(inputStr);
	std::string token;
	char delimiter = ' ';

	while (std::getline(iss, token, delimiter)) {
		if (isStringDigit(token)) {
			mStack.push(std::atoi(token.c_str()));
		} else if (isOperator(token)) {
			mStack.push(doOperation(token));
		} else {
			throw InvalidInput();
		}
	}
	if (mStack.size() != 1) {
		throw InvalidOperation();
	}
	std::cout << mStack.top() << std::endl;
	return;
}

/*--------------------------------DESTRUCTOR----------------------------------*/

RPN::~RPN()
{
	return;
}

/*--------------------------------OVERLOADS-----------------------------------*/

RPN& RPN::operator=(const RPN& rhs)
{
	// Guard Self-Assignment
	if (this == &rhs) {
		return *this;
	}
	mStack = rhs.mStack;
	return *this;
}

/*-------------------------------EXCEPTIONS-----------------------------------*/

const char* RPN::InvalidInput::what() const throw()
{
	return "Error: Invalid input.";
}

const char* RPN::InvalidOperator::what() const throw()
{
	return "Error: invalid operator usage.";
}

const char* RPN::InvalidOperation::what() const throw()
{
	return "Error: invalid operation.";
}

/*----------------------------MEMBER FUNCTIONS--------------------------------*/

bool RPN::isStringDigit(const std::string& str)
{
	for (size_t i = 0; i < str.size(); ++i) {
		if (!std::isdigit(str[i])) {
			return false;
		}
	}
	return true;
}


bool RPN::isOperator(std::string& token)
{
	if (token != "*" && token != "/" && token != "+" && token != "-") {
		return false;
	}

	return true;
}

int RPN::doOperation(std::string& token)
{
	if (mStack.size() < 2) {
		throw InvalidOperator();
	}

	int a, b;

	a = mStack.top();
	mStack.pop();
	b = mStack.top();
	mStack.pop();

	if (token == "+") {
		return b + a;
	} else if (token == "-") {
		return b - a;
	} else if (token == "*") {
		return b * a;
	}

	return b / a;
}
